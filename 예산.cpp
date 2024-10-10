#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

void selectsort(vector<int>& d, int size) {
    int i, j, temp;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (d[j] < d[i]) {
                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }

    return;
}

int solution(vector<int> d, int budget) {
    int answer = 0;
    int d_size = d.size(); //부서 개수

    // 부서별 신청한 금액 오름차순으로 정렬
    selectsort(d, d_size);

    //더하기
    for (int i = 0; i < d_size; i++) {
        if (budget - d[i] >= 0) {
            budget = budget - d[i];
            answer++;
        }
    }

    return answer;
}