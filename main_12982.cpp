#include <string>
#include <vector>
#include <algorithm>  // sort

using namespace std;

int solution(vector<int> d, int budget) {
    int n = 0;

    // 오름차순으로 정렬
    sort(d.begin(), d.end());

    // 작은 예산부터 부서 지원
    for (int i = 0; i < d.size(); i++)
    {
        if (budget < d[i])
            break;

        budget -= d[i];
        n++;  // 지원한 부서 수 ++
    }

    return n;
}
