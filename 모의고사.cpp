#include <string>
#include <vector>
#include <algorithm> //max 사용

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    //수포자 1 : 1 2 3 4 5 반복 (5)
    //수포자 2 : 2 1 2 3 2 4 2 5 반복 (8)
    //수포자 3 : 3 3 1 1 2 2 4 4 5 5 반복 (10)

    vector<int> p1 = { 1,2,3,4,5 };
    vector<int> p2 = { 2,1,2,3,2,4,2,5 };
    vector<int> p3 = { 3,3,1,1,2,2,4,4,5,5 };

    int p1_res = 0, p2_res = 0, p3_res = 0;

    for (int i = 0; i < answers.size(); i++) {
        if (p1[i % 5] == answers[i]) { p1_res++; }
        if (p2[i % 8] == answers[i]) { p2_res++; }
        if (p3[i % 10] == answers[i]) { p3_res++; }
    }

    int max_score = max({ p1_res, p2_res, p3_res });

    if (p1_res == max_score) answer.push_back(1);
    if (p2_res == max_score) answer.push_back(2);
    if (p3_res == max_score) answer.push_back(3);

    return answer;
}