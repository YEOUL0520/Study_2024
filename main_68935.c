#include <stdio.h>
#include <math.h>  // pow()

int solution(int n) {
    int* arr = (int*)malloc(n * sizeof(int));  // 동적 배열 할당 :: int arr[100];
    int i = 0, cal = 0, answer = 0;

    // 3진수 계산
    while (n >= 3) {
        arr[i] = n % 3;
        n /= 3;
        i++;
    }

    arr[i] = n;  // 변환 후의 마지막 자리값 넘겨주기

    // 반전시키지 않아도 거꾸로 들어있으므로 그대로 10진법 변환
    for (; i >= 0; i--) {
        answer += (arr[i] * pow(3, cal));
        cal++;
    }

    free(arr);  // 동적 배열 해제

    return answer;
}