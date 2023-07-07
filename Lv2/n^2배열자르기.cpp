#include <bits/stdc++.h>
using namespace std;

int slice_array_idx(long long idx, int n) {
    int quotient = idx / n + 1;
    int remainder = idx % n + 1;
    
    return quotient > remainder ? quotient : remainder;
}

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(auto i = left; i <= right; i++) answer.push_back(slice_array_idx(i, n));
    return answer;
}