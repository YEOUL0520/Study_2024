#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

//숫자간의 거리 구하는 함수
int distance(int pos, int num) {//현 손가락 위치, 눌러야하는 넘버 위치
    int d = abs(pos - num); //절댓값 구하기
    int count = 0;
    count = (d / 3) + (d % 3);
    cout << count;
    return count;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int size = numbers.size();
    int L_pos = 10; //왼손가락의 위치, 초기 위치 *
    int R_pos = 12; //오른손가락의 위치, 초기 위치 #
    int Ld = 0; //왼쪽 손가락 거리
    int Rd = 0; //오른쪽 손가락 거리

    for (int i = 0; i < size; i++) {
        if (numbers[i] == 0)
            numbers[i] = 11; //0의 위치 11
    }

    //왼손잡이 or 오른손잡이 출력
    string hand_print;
    if (hand == "left")
        hand_print = 'L';
    else
        hand_print = 'R';

    //L인지 R인지 출력하기
    for (int i = 0; i < size; i++) {
        //1,4,7
        if ((numbers[i] == 1) || (numbers[i] == 4) || (numbers[i] == 7)) {
            answer += 'L';
            L_pos = numbers[i];
        }
        //3,6,9
        else if ((numbers[i] == 3) || (numbers[i] == 6) || (numbers[i] == 9))
        {
            answer += 'R';
            R_pos = numbers[i];
        }
        //2,5,8,0
        else {//거리 구하기
            Ld = distance(L_pos, numbers[i]);
            Rd = distance(R_pos, numbers[i]);
            if ((Ld == Rd) && (hand == "left")) { //거리가 같고, 왼손잡이
                answer += hand_print;
                L_pos = numbers[i];
            }
            else if ((Ld == Rd) && (hand == "right")) { //거리가 같고, 오른손잡이
                answer += hand_print;
                R_pos = numbers[i];
            }
            else if (Ld > Rd) { //오른손가락 거리가 더 짧음
                answer += 'R';
                R_pos = numbers[i];
            }
            else { //왼손가락 거리가 더 짧음
                answer += 'L';
                L_pos = numbers[i];
            }
        }
    }
    return answer;
}