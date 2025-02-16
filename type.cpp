#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int size_s = survey.size();

    map<char, int> scores = { //key-value ������ map ���
        {'R', 0}, {'T', 0}, {'C', 0}, {'F', 0},
        {'J', 0}, {'M', 0}, {'A', 0}, {'N', 0}
    };

    for (int i = 0; i < size_s; i++) {
        string type = survey[i];
        int score = choices[i];

        scores[type[0]] += 4 - score; //�ΰ��� ���ĺ��� �տ��� ���� ��� ��� ���� ����
    }

    answer += (scores['R'] >= scores['T']) ? 'R' : 'T';
    //���ĺ� ������ R�� ���� �̹Ƿ� ������ ���ų� ũ�� answer���ٰ� �ٷ� ���� �̾� ����
    //�Ʒ� �ڵ嵵 ���� ����
    answer += (scores['C'] >= scores['F']) ? 'C' : 'F';
    answer += (scores['J'] >= scores['M']) ? 'J' : 'M';
    answer += (scores['A'] >= scores['N']) ? 'A' : 'N';

    return answer;
}