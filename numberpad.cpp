#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

//���ڰ��� �Ÿ� ���ϴ� �Լ�
int distance(int pos, int num) {//�� �հ��� ��ġ, �������ϴ� �ѹ� ��ġ
    int d = abs(pos - num); //���� ���ϱ�
    int count = 0;
    count = (d / 3) + (d % 3);
    cout << count;
    return count;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int size = numbers.size();
    int L_pos = 10; //�޼հ����� ��ġ, �ʱ� ��ġ *
    int R_pos = 12; //�����հ����� ��ġ, �ʱ� ��ġ #
    int Ld = 0; //���� �հ��� �Ÿ�
    int Rd = 0; //������ �հ��� �Ÿ�

    for (int i = 0; i < size; i++) {
        if (numbers[i] == 0)
            numbers[i] = 11; //0�� ��ġ 11
    }

    //�޼����� or ���������� ���
    string hand_print;
    if (hand == "left")
        hand_print = 'L';
    else
        hand_print = 'R';

    //L���� R���� ����ϱ�
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
        else {//�Ÿ� ���ϱ�
            Ld = distance(L_pos, numbers[i]);
            Rd = distance(R_pos, numbers[i]);
            if ((Ld == Rd) && (hand == "left")) { //�Ÿ��� ����, �޼�����
                answer += hand_print;
                L_pos = numbers[i];
            }
            else if ((Ld == Rd) && (hand == "right")) { //�Ÿ��� ����, ����������
                answer += hand_print;
                R_pos = numbers[i];
            }
            else if (Ld > Rd) { //�����հ��� �Ÿ��� �� ª��
                answer += 'R';
                R_pos = numbers[i];
            }
            else { //�޼հ��� �Ÿ��� �� ª��
                answer += 'L';
                L_pos = numbers[i];
            }
        }
    }
    return answer;
}