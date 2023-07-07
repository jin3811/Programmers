#include <bits/stdc++.h>
#define ALL(X) X.begin(),X.end()
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int curr_fat;
    int cnt;
    sort(ALL(dungeons));
        
    do {
        cnt = 0;
        curr_fat = k;
        for(auto& elem : dungeons) {
            if (curr_fat < elem[0]) break;
            
            curr_fat -= elem[1];
            cnt++;
        }
        answer = max(cnt, answer);
	} while(next_permutation(ALL(dungeons)));
    
    return answer;
}