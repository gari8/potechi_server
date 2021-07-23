#include <iostream>
#include <string>
#include <map>
#include <vector>

#include <grpc/grpc.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include "potechi_manager.cpp"
#include "codegen/potechi.pb.h"
#include "codegen/potechi.grpc.pb.h"

using namespace std;
using namespace potechi;
using namespace grpc;

class PotechiServiceImpl final : public Potechi::Service {
    Status Vote(ServerContext* context,
                ServerReaderWriter<VoteReply, VoteRequest>* stream) override {
        VoteRequest request;
        while (stream->Read(&request)) {
            if (request.voter_name().size() == 0) return Status(StatusCode::INVALID_ARGUMENT, "error: Argument not found");
            vector<int> flavor_numbers;
            for (int i = 0; i < request.flavor_numbers_size(); i++) {
                flavor_numbers.push_back(request.flavor_numbers(i));
            }
            // DATA: data { key: value, _key: _value }
            map<string, int> data;
            bool ok;
            tie(data, ok) = pm.AddVoting(request.voter_name(), flavor_numbers);
            if (ok) {
                VoteReply reply;
                for (auto x: data) {
                    cout << x.first << ":" << x.second << endl;
                    (*reply.mutable_result())[x.first] = x.second;
                }
                stream->Write(reply);
            }
        }
        return Status::OK;
    }
    Status Counting(ServerContext* context, const CountingRequest* request,
                    CountingReply* reply) override {
        if (request->voter_name().size() == 0) return Status(StatusCode::INVALID_ARGUMENT, "error: Argument not found");
        double rate = pm.CheckContribution(request->voter_name());
        string msg = "";
        if (rate > 0.0) {
            msg = "You are very contributing";
        } else {
            msg = "You haven't contributed at all";
        }
        reply->set_contribution_rate(rate);
        reply->set_message(msg);
        return Status::OK;
    }

    private:
        mutex mu_;
        PotechiManager pm;
};

void RunServer() {
    string server_address("0.0.0.0:50051");
    PotechiServiceImpl service;

    EnableDefaultHealthCheckService(true);
    reflection::InitProtoReflectionServerBuilderPlugin();
    ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(&service);
    // Finally assemble the server.
    unique_ptr<Server> server(builder.BuildAndStart());
    cout << "Server listening on " << server_address << endl;

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    server->Wait();
}

int main(int argc, char** argv) {
    RunServer();
    return 0;
}