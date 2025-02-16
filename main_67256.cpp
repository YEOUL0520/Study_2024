#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {

    string answer = "";
    int L_hand = 10, R_hand = 12;

    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {  // 1, 4, 7
            answer += "L";
            L_hand = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {  // 3, 6, 9
            answer += "R";
            R_hand = numbers[i];
        }
        else {  // 2, 4, 8, 0
            if (numbers[i] == 0)  // 0의 위치를 11로 가정하고 계산
                numbers[i] = 11;

            int L_cal = (L_hand - numbers[i]);
            int R_cal = (R_hand - numbers[i]);

            int L_mov = (abs(L_cal / 3) + abs(L_cal % 3));  // abs(): 절댓값
            int R_mov = (abs(R_cal / 3) + abs(R_cal % 3));

            if (L_mov > R_mov) {  // R이 더 가까울 때
                answer += "R";
                R_hand = numbers[i];
            }
            else if (L_mov < R_mov) {  // L이 더 가까울 때
                answer += "L";
                L_hand = numbers[i];
            }
            else {  // 움직임 횟수가 같을 때

                if (hand == "left") {
                    answer += "L";
                    L_hand = numbers[i];
                }
                else if (hand == "right") {
                    answer += "R";
                    R_hand = numbers[i];
                }
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> numbers = { 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 }; // {} 사용
    string result = solution(numbers, "left");
    cout << result << endl; // 결과 출력
}