#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int len = 0;
    int arr[32];
    while (n) {
        arr[len++] = n % 3;
        n /= 3;
    }
    answer = arr[0];
    for (int i = 1; i < len; i++) {
        answer = (answer * 3) + arr[i];
    }
    return answer;
}

int main () {
    printf("%d", solution(45));
}