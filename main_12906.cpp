#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int p = 0;
    int arr_size = arr.size();

    answer.resize(arr_size); // answer의 크기를 arr의 크기로 설정
    answer[p] = arr[p];  // 첫 번째 값은 무조건 유지

    for (int i = 1; i < arr_size; i++) {
        if (answer[p] == arr[i])
            continue;
        else {
            p++;
            answer[p] = arr[i];
        }
    }

    answer.resize(p + 1); // answer의 인덱스를 사용하여 크기 설정

    return answer;
}