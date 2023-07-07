#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    int i;
    char* arr[] = {"수", "박"};
    char* answer = (char*)malloc(sizeof(char) * 3 + 1);
    strcpy(answer, "수\0");
    for (i = 1; i < n; i++) {
        strcat(answer, arr[i % 2]);
    }
    return answer;
}


/* 
한글 바이트에 대해 모를때
char* solution(int n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    int i;
    char* arr[] = {"수", "박"};
    char* answer = (char*)malloc(sizeof(arr[0]) * n);
    strcpy(answer, arr[0]);
    for (i = 1; i < n; i++) {
        strcat(answer, arr[i % 2]);
    }
    return answer;
}
*/

int main () {
    printf("%s", solution(4));
    return 0;
}
