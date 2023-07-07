#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = 0;
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    } else if (a == b) {
        return a;
    }

    for (int i = a; i <= b; i++) {
        answer += i;
    }
    return answer;
}

int main () {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld", solution(a,b));
    return 0;
}