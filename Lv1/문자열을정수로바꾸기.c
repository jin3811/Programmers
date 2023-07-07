#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define N 5

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    char * str;
    strcpy(str, s);
    answer = atoi(str);
    // int i = 0; // 위치 인자
    // int len = strlen(s); // 반복문에 범위로 삽입하는 경우 strlen을 반복해서 계산한다.
    // int operater = 1; // 양, 음에 따라 연산자가 결정된다.
    // char string;
    // // char * string;
    // // strcpy(string, s); // 일단은 복사해보도록 하자
    
    // if (s[0] == '-') {
    //     operater *= -1;
    //     i++;
    // }
    // for (i; i < len; i++) {
    //     string = s[i];
    //     answer *= 10;
    //     answer += operater * (string - '0');
    // }

    
    return answer;
}

int main () {
    char string[N];
    scanf("%s", string);
    printf("%d", solution(string));
    return 0;
}