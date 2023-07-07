#include <bits/stdc++.h>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < n; i++) {
        int dec = arr1[i] | arr2[i];
        bitset<16> bin = dec;
        string bin_str;
        for(int j = n - 1; j >= 0; j--) {
            if (bin[j]) bin_str += "#";
            else bin_str += " ";
        }
        answer.push_back(bin_str);
    }
    return answer;
}