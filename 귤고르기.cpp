#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int max = 0;
    int size = tangerine.size();

    for (int i = 0; i < size; i++) {
        if (tangerine[i] > max)
            max = tangerine[i];
    }

    vector<int> count(max, 0);

    for (int i = 0; i < size; i++) {
        int num = tangerine[i];
        count[num - 1]++;
    }

    sort(count.begin(), count.end(), greater<int>()); //내림차순 정렬

    for (int j = 0; j < size; j++) {
        if (k <= 0)
            break;
        k = k - count[j];
        answer++;
    }

    return answer;
}