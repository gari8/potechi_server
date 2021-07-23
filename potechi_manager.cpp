//
// Created by HAGARI HAYATO on 2021/07/24.
//
#include <iostream>
#include <map>
#include <tuple>
#include <string>

using namespace std;

map<int, string> choices = {
    {0, "usushio"},
    {1, "consomme_punch"},
    {2, "norishio"},
    {3, "happy_butter"},
    {4, "shouyu"},
};

class PotechiManager {
public:
    PotechiManager(){

    };

    tuple<map<string, int>, bool> AddVoting(string voter_name, vector<int> flavor_numbers) {
        if (vote_cnt.count(voter_name) == 0) {
            vote_cnt[voter_name] = 0;
        }
        vote_cnt[voter_name] += flavor_numbers.size();
        for (auto i: flavor_numbers) {
            if (!match_choices(i)) return forward_as_tuple(vote_box, false);
        }
        for (auto i: flavor_numbers) {
            if (vote_box.count(choices[i]) == 0) {
                vote_box[choices[i]] = 0;
            }
            vote_box[choices[i]] += 1;
        }
        return forward_as_tuple(vote_box, true);
    };

    double CheckContribution(string voter_name) {
        int sum = 0;
        int mine = 0;
        for (auto x: vote_cnt) {
            if (x.first == voter_name) {
                mine += x.second;
            }
            sum += x.second;
        }
        return (double)mine / (double)sum;
    }


private:
    // 選択肢ごとの得票数
    map<string, int> vote_box;
    // voter毎の投票回数
    map<string, int> vote_cnt;

    bool match_choices(int i) {
        return i == 0 || i == 1 || i == 2 || i == 3 || i == 4;
    };
};

