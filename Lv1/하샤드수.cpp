#include <vector>
#include <numeric>
using namespace std;

bool solution(int x) {
    int copy = x;
    vector<int> v;
    while(copy) {
        v.push_back(copy%10);
        copy /= 10;
    }
    return !(x % accumulate(v.begin(), v.end(), 0)); 
}