#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    vector<int> count = { 781,156,31,6,1 }; //첫번째 자리 (625+125+25+5+1), 두번째 자리 (125+25+5+1), 세번째 자리 (25+5+1), 네번째 자리(5+1), 다섯번째 자리 (1)
    vector<char> vec = { 'A','E','I','O','U' };

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= vec.size(); j++)
        {
            if (word[i] == vec[j])
            {
                answer += j * count[i];
            }
        }
    }

    answer += word.size();

    return answer;
}