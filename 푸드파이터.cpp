#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "0"; //기준점,정중앙의 물

    for (int i = food.size() - 1; i > 0; i--) {
        int count = food[i] / 2; //나머지 버려
        for (int j = 0; j < count; j++) { //양쪽에 동일하게 붙이기
            answer = to_string(i) + answer + to_string(i); //to_string은 숫자->문자열 전환
        }
    }

    return answer;
}