#include <bits/stdc++.h>
using namespace std;

inline bool equal(string& str, string& pattern, int start) {
    for (int i = 0; i < pattern.size(); i++)
        if (str[start + i] != pattern[i]) return false;
    return true;
}

int solution(string s) {
    if (s.length() == 1) return 1;
    int answer = 1001;
    int cnt;
    string compression_str;
    string pattern;
    for (int pattern_len = 1; pattern_len <= s.length() / 2; pattern_len++) { // 패턴 길이 설정
        compression_str = "";
        for (int j = 0; j < s.length(); j += cnt * pattern_len) { // 비교
            cnt = 1;
            pattern = s.substr(j, pattern_len); // 패턴 생성
            for (int start = j + pattern_len; start < s.length(); start += pattern_len) { // 비교
                if (equal(s, pattern, start)) {
                    cnt++;
                }
                else break;
            }

            if (cnt != 1) compression_str += to_string(cnt) + pattern;
            else compression_str += pattern;
        }
        answer = min(answer, (int)compression_str.length());
    }
    return answer;
}