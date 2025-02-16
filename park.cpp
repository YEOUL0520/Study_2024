#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1; //�ƹ��� ���ڸ��� �� ��

    // ���� ��ȹ�� ���
    int row = park.size(); //park�� �� ����
    int col = park[0].size(); //park�� �� ����

    vector<vector<int>> dp_mat(row, vector<int>(col, 0)); //park�� ũ�Ⱑ ���� ���̺�
    int max_size = 0; //���簢���� �ִ� ũ��

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (park[i][j] == "-1") {
                if (i == 0 || j == 0) { dp_mat[i][j] = 1; }
                else {
                    dp_mat[i][j] = min({ dp_mat[i - 1][j],dp_mat[i][j - 1],dp_mat[i - 1][j - 1] }) + 1;
                    //���� ����, ����, �ϼ���. 3���� ���� ���� ���� �Ÿ� ���ϱ�.
                }
                max_size = max(max_size, dp_mat[i][j]); //���� ū ���簢�� ũ�� �� �� ����
            }
        }
    }

    //���� �ִ� ���ڸ� ũ�� ��
    int mat_size = mats.size(); //���ڸ� ����
    sort(mats.rbegin(), mats.rend()); //������������ ����, rbegin(),rend()�� ���� �ݺ���, vector������ ��밡��

    for (int i = 0; i < mat_size; i++) {
        if ((answer == -1) && (mats[i] <= max_size)) { answer = mats[i]; }
        //answer�� ������ 0�̰� �ִ� ũ�� ã�� �� ���ǹ� ����
        //�������� �����̹Ƿ� �ִ� ũ�⸦ ã���� answer�� ���� �ٲ�� ������ �߰������� ���� ���̻� �� �ٲ�
    }

    return answer;
}