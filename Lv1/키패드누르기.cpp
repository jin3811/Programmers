#include <bits/stdc++.h>
using namespace std;

int rfing, lfing;

int dist(int finger, int target) {
    int temp = abs(finger-target);
    return (temp / 3) + (temp % 3);
}

void make_ans(string& answer, int is_left, int target) {
    // left == 1이면 왼손, 0이면 오른손
    if (is_left) {
        answer += "L";
        lfing = target;
    } else {
        answer += "R";
        rfing = target;
    }
}
// LRLLRRLLLRR
string solution(vector<int> numbers, string hand) {
    string answer = "";
    rfing = 12; // "#"
    lfing = 10; // "*"
    for (int num : numbers) {
        if (num == 0) num = 11;
        
        if (num % 3 == 0) make_ans(answer, 0, num);
        else if (num % 3 == 1) make_ans(answer, 1, num);
        else if (num % 3 == 2 ) {
            int right_dist = dist(rfing, num);
            int left_dist = dist(lfing, num);

            if (right_dist > left_dist) make_ans(answer, 1, num);
            else if (right_dist < left_dist) make_ans(answer, 0, num);
            else {
                if (hand == "right") make_ans(answer, 0, num);
                else make_ans(answer, 1, num);
            }
        }
    }
    return answer;
}

int main() {
    // vector<int> numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    // vector<int> numbers = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    string hand = "right";
    // string hand = "left";
    cout << solution(numbers, hand) << endl;
}