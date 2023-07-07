#include <bits/stdc++.h>
using namespace std;

int bfs(vector<string>& board, int x, int y) {
    queue<tuple<int, int, int>> q;
    bool visit[5][5] = {false};
    int dist = 0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    q.push({x, y, 0});
    visit[y][x] = true;

    while(!q.empty()) {
        int cur_x = get<0>(q.front());
        int cur_y = get<1>(q.front());
        int cur_dist = get<2>(q.front());
        q.pop();

        if (cur_dist < 2) {
            for (int i = 0; i < 4; i++) {
                int next_x = cur_x + dx[i];
                int next_y = cur_y + dy[i];
                if (next_x < 0 || next_x >= 5 || next_y < 0 || next_y >= 5) continue;
                if (visit[next_y][next_x]) continue;

                if (board[next_y][next_x] == 'O') {
                    q.push({next_x, next_y, cur_dist + 1});
                    visit[next_y][next_x] = true;
                }
                else if (board[next_y][next_x] == 'P') return 0;
                else continue;
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int temp;

    for(auto& tcase : places) {
        temp = 1;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(tcase[i][j] == 'P') temp &= bfs(tcase, j, i);
            }
        }
        answer.push_back(temp);
    }
    return answer;
}

int main() {
        // {"PXOOO", "OOOOO", "PXOOO", "OOOOO", "OOOPO"}
    vector<vector<string>> v = {
        {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
    };
    vector<int> answer = solution(v);
    for(auto& t : answer) cout << t << " ";
}