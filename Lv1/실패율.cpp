#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> ratio(N);
    int l = 0, r = 0, prev;

    sort(stages.begin(), stages.end());
    for (int i = 1; i <= N; i++) {
        prev = l;
        ratio[i - 1].first = i;

        while (stages[l] <= i) l++;

        ratio[i - 1].second = (double)(l - prev) / (stages.size() - prev);
    }
    stable_sort(ratio.begin(), ratio.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
        return a.second > b.second;
    });
    for (auto& x : ratio) answer.push_back(x.first);
    return answer;
}