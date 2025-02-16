#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int size_s = survey.size();

    map<char, int> scores = { //key-value 가능한 map 사용
        {'R', 0}, {'T', 0}, {'C', 0}, {'F', 0},
        {'J', 0}, {'M', 0}, {'A', 0}, {'N', 0}
    };

    for (int i = 0; i < size_s; i++) {
        string type = survey[i];
        int score = choices[i];

        scores[type[0]] += 4 - score; //두개의 알파벳중 앞에만 점수 계산 대신 음수 포함
    }

    answer += (scores['R'] >= scores['T']) ? 'R' : 'T';
    //알파벳 순서가 R이 먼저 이므로 점수가 같거나 크면 answer에다가 바로 글자 이어 붙임
    //아래 코드도 같은 원리
    answer += (scores['C'] >= scores['F']) ? 'C' : 'F';
    answer += (scores['J'] >= scores['M']) ? 'J' : 'M';
    answer += (scores['A'] >= scores['N']) ? 'A' : 'N';

    return answer;
}