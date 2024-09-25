#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>


using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    //today�� ��ü ��¥, terms�� ��ȿ�Ⱓ, privacies�� ������ ��������
    vector<int> answer;
    string comma = "."; //. ���� ����
    string spacebar = " "; //���⸦ �����ϱ� ���� ���� ����
    string today_year, today_month, today_day; //���� ���� ��¥�� ����, ��, ���� ���� ����

    //���� ��¥�� ����,��,�� �и�
    today_year = today.substr(0, 4); //0��° �ε����� �����ؼ� 4�� ���̸� �ڸ�
    today_month = today.substr(5, 2); //6��° �ε����� �����ؼ� 2�� ���̸� �ڸ�
    today_day = today.substr(8, 2); //9��° �ε����� �����ؼ� 2�� ���̸� �ڸ�

    //terms���� ����� ������ ��ȿ�Ⱓ ����
    int index_terms = terms.size(); //index_terms�� terms�� ���� ����
    vector<string> terms_type(index_terms); //���� ���� ���̸�ŭ ��� ������ ���� ���ο� ���� ����
    vector<string> terms_month(index_terms); //���� ���� ���̸�ŭ �������� ���� �Ⱓ�� ���� ���ο� ���� ����

    for (int i = 0; i < index_terms; i++) {
        int sb_index = terms[i].find(spacebar, 0); //�پ�� ��ġ ã��
        int size = terms[i].size(); //�Է¹��� ���ڿ��� ����
        terms_type[i] = terms[i].substr(0, sb_index); //��� ���� �Է� �ޱ�
        terms_month[i] = terms[i].substr(sb_index + 1);//��� �Ⱓ �Է� �ޱ�
    }

    //privacies�� ���� ����
    int index_pri = privacies.size(); //privacies�� ���� ����
    //���� ���������� �����Ǿ��� ��¥�� ����, ��, ���� ���� ����
    vector<string> date_y(index_pri);
    vector<string> date_m(index_pri);
    vector<string> date_d(index_pri);
    vector<string> ptype(index_pri); //privacies �� �ִ� ��� ���� ����

    for (int j = 0; j < index_pri; j++) {
        int d_size = privacies[j].size(); //privacies�� Ȯ���ؾ��ϴ� ��� ���� ����
        int sb_pindex = privacies[j].find(spacebar, 0); //���� Ȯ�ο�
        ptype[j] = privacies[j].substr(sb_pindex + 1); //��� ���� ����
        date_y[j] = privacies[j].substr(0, 4);
        date_m[j] = privacies[j].substr(5, 2);
        date_d[j] = privacies[j].substr(8, 2);
    }

    //����Ⱓ ���
    for (int i = 0; i < index_terms; i++) {
        for (int j = 0; j < index_pri; j++) {
            if (terms_type[i] == ptype[j]) { //��� ������ ������ ���
                //���� �Ⱓ �� ���
                if (date_d[j] == "01") { date_d[j] = "28"; } //��� ��¥�� 1�� ���
                else { //�׿��� ���
                    int ddate = stoi(date_d[j]);
                    ddate--;
                    date_d[j] = to_string(ddate);
                    if (date_d[j].size() == 1) { date_d[j] = "0" + date_d[j]; }
                }

                //���� �Ⱓ �� ���
                int mdata = (stoi(terms_month[i])) % 12;
                if ((stoi(date_m[j]) + mdata) > 12) { //���� 12�� �Ѿ ���
                    int date = stoi(date_m[j]);
                    date = date + mdata - 12;
                    date_m[j] = to_string(date);
                    if (date_m[j].size() == 1) { date_m[j] = "0" + date_m[j]; }
                    int yydate = stoi(date_y[j]);
                    yydate++;
                    date_y[j] = to_string(yydate);
                }
                else {
                    int date = stoi(date_m[j]);
                    date = date + mdata;
                    date_m[j] = to_string(date);
                    if (date_m[j].size() == 1) { date_m[j] = "0" + date_m[j]; }
                }
                //���� �Ⱓ ���� ���
                int ydata = (stoi(terms_month[i])) / 12;
                int date = stoi(date_y[j]);
                date = date + ydata;
                date_y[j] = to_string(date);
            }
            //cout<<date_y[j]<<date_m[j]<<date_d[j]<<endl;
        }
    }


    //����� ���ᳯ¥�� �������Ƥþƾ���� ��
    for (int i = 0; i < index_pri; i++) {
        if (stoi(date_y[i]) < stoi(today_year) ||
            (stoi(date_y[i]) == stoi(today_year) && stoi(date_m[i]) < stoi(today_month)) ||
            (stoi(date_y[i]) == stoi(today_year) && stoi(date_m[i]) == stoi(today_month) && stoi(date_d[i]) < stoi(today_day))) {
            answer.push_back(i + 1);  // ����� ���
        }
    }

    return answer;
}