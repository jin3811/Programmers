#include <bits/stdc++.h>
#define MOD (int)(1e9+7)
using namespace std;

int solution(int n) {
    if (n % 2 == 1) return 0;

     vector<long long> dp = {0, 3, 11}; // 0, 2, 4, 6
    if (n / 2 <= 2) return dp[n / 2];
    else {
        for(int i = 2; i < n / 2; i++) {
            long long temp = (3 * dp[i] + 2) % MOD;
            for (int j = i - 1; j >= 1; j--) {
                temp += (2 * dp[j]) % MOD;
                temp %= MOD;
            }
            temp %= MOD;
            dp.push_back((int)temp);
        }
    }
    return dp[n / 2];
}