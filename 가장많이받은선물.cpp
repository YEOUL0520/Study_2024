#include <string>
#include <vector>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    // 띄어쓰기 기준으로 준 사람과 받은 사람을 구한다.
    // 선물 지수를 구한다.
    // 다음 달에 받을 선물의 수를 구한다.
    int n_f = friends.size(); //친구 수
    int n_g = gifts.size(); //총 선물 수
    vector<int> get_gift(n_f); //각 친구한테 받은 선물 수를 저장
    vector<int> give_gift(n_f); //각 친구한테 준 선물 수를 저장
    vector<int> next_month(n_f); //다음 달에 받을 선물 수를 저장
    string spacebar = " "; //gift에서 띄어쓰기를 구분하기 위해 만든 변수 

    for (int i = 0; i < n_g; i++)
    {
        int index = 0; //문자열에서 띄어쓰기의 위치
        int size = gifts[i].size(); //문자열 길이
        index = gifts[i].find(spacebar, 0);
        if (friends[i] == gifts[i].substr(0, index - 1))
            give_gift[i]++; // 준 선물 수 증가
        if (friends[i] == gifts[i].substr(index + 1, size - 1))
            get_gift[i]++; //받은 선물 수 증가
    }

    for (int i = 0; i < n_f; i++) {
        for (int j = 0; j < n_f; j++) {
            if (i == j) continue; //자기자신

            //두 사람 사이에 주고받은 기록이 있으며 주고 받은 수가 다른 경우
            if (get_gift[i] > give_gift[j])
                next_month[j]++;
            else if (get_gift[i] < give_gift[j])
                next_month[i]++;
            else { //두 사람 사이에 주고받은 기록이 없어 선물지수로 비교하는 경우
                int score_i = get_gift[i] - give_gift[j]; //i의 선물지수
                int score_j = get_gift[j] - give_gift[i]; //j의 선물지수

                if (score_i < score_j)
                    next_month[i]++;
                else if (score_i > score_j)
                    next_month[j]++;
            }

        }
    }

    int answer = 0;
    for (int i = 0; i < n_f; i++)
    {
        if (next_month[i] > answer)
            answer = next_month[i];
    }
    return answer;
}