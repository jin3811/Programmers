#include <bits/stdc++.h>
using namespace std;

int same_cnt(const vector<int>& lotto, const vector<int> win) {
    int cnt = 0;
    for(int i = 0; i < lotto.size(); i++) {
        if (lotto[i] == 0) continue;
        for(int j = 0; j < win.size(); j++) {
            if (lotto[i] == win[j]) cnt++;
        }
    }
    return cnt;
}

int zero_cnt(const vector<int>& lotto) {
    int cnt = 0;
    for(int i = 0; i < lotto.size(); i++) {
        if (lotto[i] == 0) cnt++;
    }
    return cnt;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int same = same_cnt(lottos, win_nums);
    int zero = zero_cnt(lottos);
    
    answer.push_back(7 - (same + zero ? same + zero : 1)); // 모두 다른 경우를 위한 조건식
    answer.push_back(7 - (same ? same : 1)); // 같은것이 아예 없을 때의 조건식

    return answer;
}