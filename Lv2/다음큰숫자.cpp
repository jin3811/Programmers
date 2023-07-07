#include <bitset>
using namespace std;

int solution(int n) {
    int answer = n + 1;
    bitset<20> bin_n = n, next_big_n = answer;
    while (bin_n.count() != next_big_n.count()) next_big_n = ++answer;
    return answer;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solution(1);
}