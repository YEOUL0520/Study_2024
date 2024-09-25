#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    //신청 금액을 오름차순으로 정렬
    sort(d.begin(), d.end());

    int answer = 0; //지원할 수 있는 부서의 수
    int total = 0; //현재까지 지원한 금액

    //금액 순서대로 확인하면서 지원 금액에 추가
    for (int i = 0; i < d.size(); i++) {
        total += d[i];

        //총 지원 금액이 예산을 초과하면
        if (total > budget) {
            break;
        }

        answer++; //지원 가능한 부서 수 증가
    }

    return answer; //최대 지원할 수 있는 부서 수 반환
}

int main() {
    vector<int> d = { 1, 3, 2, 5, 4 };
    int budget = 9;
    cout << solution(d, budget) << endl;
    return 0;
}
