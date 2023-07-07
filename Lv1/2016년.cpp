#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int monthDay[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int start = 5;
    for  (int i = 0; i < a-1; ++i)
        start += monthDay[i];
    start += b - 1;
    return answer[start % 7];
}