#include <bits/stdc++.h>
using namespace std;

int idx;

bool comp(const string& a, const string& b) {
    return a[idx] != b[idx] ? a[idx] < b[idx] : a < b;
}

vector<string> solution(vector<string> strings, int n) {
    idx = n;
    sort(strings.begin(), strings.end(), comp);
    return strings;
}