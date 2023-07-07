#include <vector>
#include <algorithm>

#define LEN 50001
using namespace std;

bool seive[LEN];

void set_seive () {
    fill(seive, seive + LEN, true);
    seive[0] = seive[1] = false;
    
    for(int i = 2; i < LEN; i++) {
        if (seive[i]) {
            for (int j = 2; i * j < LEN; j++) seive[i * j] = false;
        }
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    int is_prime;
    vector<bool> comb(nums.size());
    
    comb[0] = comb[1] = comb[2] = true;
    set_seive();
    do {
        is_prime = 0;
        for (int i = 0; i < comb.size(); ++i) {
            if (comb[i]) is_prime += nums[i];
        }
        if (seive[is_prime]) answer++;
    } while (prev_permutation(comb.begin(), comb.end()));
    
    return answer;
}