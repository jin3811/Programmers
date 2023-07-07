#include <bits/stdc++.h>
using namespace std;

int max_diff = -1;
vector<int> ryan(11, 0), apeach, result;

pair<int, int> get_score() {
    pair<int, int> score = {0, 0}; // {ryan, apeach}
    for(int i = 0; i < 11; i++) { 
        if(ryan[i] == apeach[i]) {
            if (ryan[i] == 0) continue;
            else score.second += 10 - i;
        }
        else {
            if (ryan[i] > apeach[i]) score.first += 10 - i;
            else score.second += 10 - i;
        }
    }
    return score;
}

void check() {
    pair<int, int> score = get_score();
    int ryan_score = score.first;
    int apeach_score = score.second;
    int diff = ryan_score - apeach_score;
    
    if (diff < 0 || max_diff > diff) return; // ryan이 apeach보다 점수를 적게 받았거나, 최대 점수차이가 아니면 답이 아니다.
    
    if (max_diff < diff) {
        max_diff = diff;
        result = ryan;
    }
    else if(max_diff == diff) { // 점수차이가 같다면, 더 낮은 점수를 더 많이 맞춘 경우로 답을 바꾼다.
        for(int i = 10; i >= 0; i--) {
            if (ryan[i] > result[i]) {
                result = ryan;
                break;
            }
            else if (ryan[i] < result[i]) {
                break;
            }
        }
    }
}

void dfs(int cnt, int idx, int n) { // 화살 배치
    if (cnt == n) {
        check();
        return;
    }
 
    int curArrow = n - cnt;
    if (idx == 10) {    
        ryan[idx] = curArrow;
        dfs(cnt + curArrow, idx + 1, n);
        ryan[idx] = 0;
    } else {
        if (apeach[idx] + 1 <= curArrow) {
            ryan[idx] = apeach[idx] + 1;
            dfs(cnt + apeach[idx] + 1, idx + 1, n);
            ryan[idx] = 0;
        }
        dfs(cnt, idx + 1, n);
    }
}

vector<int> solution(int n, vector<int> info) {
    apeach = info;
    dfs(0, 0, n);

    if (max_diff == -1) result.push_back(-1);
    else if (max_diff == 0) {
        result.clear();
        result.push_back(-1);
    }
    return result;
}