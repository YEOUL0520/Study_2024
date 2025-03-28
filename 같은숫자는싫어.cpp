#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int arr_size = arr.size(); //배열의 크기
    answer.push_back(arr[0]);
    for (int i = 1; i < arr_size; i++) {
        if (arr[i - 1] != arr[i]) {
            answer.push_back(arr[i]);
        }
    }

    return answer;
}