#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;

void dec_to_kbase(string& result, int dec, int k) {
    if (k == 0) result = to_string(dec);

    while (dec) {
        result += to_string(dec % k);
        dec /= k;
    }
    reverse(result.begin(), result.end());
}

bool is_prime(ull n) {
    if (n <= 1) return false;

    for(ull i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string nBase;
    dec_to_kbase(nBase, n, k);
    vector<ull> target;
    string p;
    
    for(char x : nBase) {
        if (x == '0') {
            if (p != "") {
                target.push_back(stoull(p));
                p = "";
            }   
        }
        else p += x;
    }
    if (p != "") target.push_back(stoull(p));
    for (ull x : target) {
        if (is_prime(x)) answer++;
    }
    return answer;
}