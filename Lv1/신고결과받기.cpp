#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <utility>  

#define all(x) (x).begin(), (x).end()
using namespace std;

inline int get_index(vector<string>& id_list, string& name) {
    for(int i = 0; i < id_list.size(); i++)
        if (id_list[i] == name) return i;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0); // 답
    vector<int> report_cnt(id_list.size(), 0); // 각 유저가 신고당한 횟수
    pair<string, string> user_report; // <유저id, 유저가 신고한 id>
    
    // report 중복 제거, 동일 유저가 한 유저를 여러번 신고했다면, 같은 형식의 데이터가 여러개 들어있을 수 밖에 없다.
    sort(all(report));
    report.erase(unique(all(report)), report.end());
    
    // 신고당한 횟수 작성
    for(auto rp : report) {
        stringstream ss(rp);
        getline(ss, user_report.first, ' ');
        getline(ss, user_report.second, ' ');
        
        report_cnt[get_index(id_list, user_report.second)]++;
    }
    
    // 답안 작성
    for(auto rp : report) {
        stringstream ss(rp);
        getline(ss, user_report.first, ' ');
        getline(ss, user_report.second, ' ');
        
        if (report_cnt[get_index(id_list, user_report.second)] >= k)
            answer[get_index(id_list, user_report.first)]++;
    }
    
    return answer;
}