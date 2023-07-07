#include <string>
#include <vector>
#include <stack>

using namespace std;


int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int target;
    vector<stack<int>> bd(board[0].size());
    stack<int> busket;
    
    // board 전처리
    for(int i = board.size() - 1; i >= 0; i--)  {
        for(int j = 0; j < board[i].size(); j++) {
            if(board[i][j]) bd[j].push(board[i][j]);
        }
    }

    // 풀이
    for(int i : moves) {
        i--;
        if(!bd[i].empty()) {
            target = bd[i].top();
            bd[i].pop();
            
            if(!busket.empty() && target == busket.top()) {
                answer += 2;
                busket.pop();
            }
            else busket.push(target);
        }
    }
    return answer;
}