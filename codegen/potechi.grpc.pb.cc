// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: potechi.proto

#include "potechi.pb.h"
#include "potechi.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace potechi {

static const char* Potechi_method_names[] = {
  "/potechi.Potechi/Vote",
  "/potechi.Potechi/Counting",
};

std::unique_ptr< Potechi::Stub> Potechi::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Potechi::Stub> stub(new Potechi::Stub(channel, options));
  return stub;
}

Potechi::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Vote_(Potechi_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  , rpcmethod_Counting_(Potechi_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::ClientReaderWriter< ::potechi::VoteRequest, ::potechi::VoteReply>* Potechi::Stub::VoteRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::potechi::VoteRequest, ::potechi::VoteReply>::Create(channel_.get(), rpcmethod_Vote_, context);
}

void Potechi::Stub::experimental_async::Vote(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::potechi::VoteRequest,::potechi::VoteReply>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::potechi::VoteRequest,::potechi::VoteReply>::Create(stub_->channel_.get(), stub_->rpcmethod_Vote_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::potechi::VoteRequest, ::potechi::VoteReply>* Potechi::Stub::AsyncVoteRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::potechi::VoteRequest, ::potechi::VoteReply>::Create(channel_.get(), cq, rpcmethod_Vote_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::potechi::VoteRequest, ::potechi::VoteReply>* Potechi::Stub::PrepareAsyncVoteRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::potechi::VoteRequest, ::potechi::VoteReply>::Create(channel_.get(), cq, rpcmethod_Vote_, context, false, nullptr);
}

::grpc::Status Potechi::Stub::Counting(::grpc::ClientContext* context, const ::potechi::CountingRequest& request, ::potechi::CountingReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::potechi::CountingRequest, ::potechi::CountingReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Counting_, context, request, response);
}

void Potechi::Stub::experimental_async::Counting(::grpc::ClientContext* context, const ::potechi::CountingRequest* request, ::potechi::CountingReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::potechi::CountingRequest, ::potechi::CountingReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Counting_, context, request, response, std::move(f));
}

void Potechi::Stub::experimental_async::Counting(::grpc::ClientContext* context, const ::potechi::CountingRequest* request, ::potechi::CountingReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Counting_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::potechi::CountingReply>* Potechi::Stub::PrepareAsyncCountingRaw(::grpc::ClientContext* context, const ::potechi::CountingRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::potechi::CountingReply, ::potechi::CountingRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Counting_, context, request);
}

::grpc::ClientAsyncResponseReader< ::potechi::CountingReply>* Potechi::Stub::AsyncCountingRaw(::grpc::ClientContext* context, const ::potechi::CountingRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncCountingRaw(context, request, cq);
  result->StartCall();
  return result;
}

Potechi::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Potechi_method_names[0],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< Potechi::Service, ::potechi::VoteRequest, ::potechi::VoteReply>(
          [](Potechi::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::potechi::VoteReply,
             ::potechi::VoteRequest>* stream) {
               return service->Vote(ctx, stream);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Potechi_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Potechi::Service, ::potechi::CountingRequest, ::potechi::CountingReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Potechi::Service* service,
             ::grpc::ServerContext* ctx,
             const ::potechi::CountingRequest* req,
             ::potechi::CountingReply* resp) {
               return service->Counting(ctx, req, resp);
             }, this)));
}

Potechi::Service::~Service() {
}

::grpc::Status Potechi::Service::Vote(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::potechi::VoteReply, ::potechi::VoteRequest>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Potechi::Service::Counting(::grpc::ServerContext* context, const ::potechi::CountingRequest* request, ::potechi::CountingReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace potechi
