#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    //��û �ݾ��� ������������ ����
    sort(d.begin(), d.end());

    int answer = 0; //������ �� �ִ� �μ��� ��
    int total = 0; //������� ������ �ݾ�

    //�ݾ� ������� Ȯ���ϸ鼭 ���� �ݾ׿� �߰�
    for (int i = 0; i < d.size(); i++) {
        total += d[i];

        //�� ���� �ݾ��� ������ �ʰ��ϸ�
        if (total > budget) {
            break;
        }

        answer++; //���� ������ �μ� �� ����
    }

    return answer; //�ִ� ������ �� �ִ� �μ� �� ��ȯ
}

int main() {
    vector<int> d = { 1, 3, 2, 5, 4 };
    int budget = 9;
    cout << solution(d, budget) << endl;
    return 0;
}
