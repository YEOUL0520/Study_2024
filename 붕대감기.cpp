#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int time = 0; //총 걸리는 시간
    int last = attacks.size(); //몬스터가 마지막으로 공격하는 시간
    time = attacks[last - 1][0];
    int t, x, y, j = 0; //t는 시전 시간, x는 초당 회복량, y는 추가 회복량, j는 attacks의 인덱스
    t = bandage[0];
    x = bandage[1];
    y = bandage[2];
    int success = 0; //연속 성공 횟수
    int f_health = health; //최대 체력

    for (int i = 0; i <= time; i++) {
        if (attacks[j][0] == i) { //몬스터에게 공격받은 경우
            success = 0; //연속 성공 횟수 초기화
            health = health - attacks[j][1]; //공격력만큼 체력 깎기
            j++;
            if (health <= 0) //체력이 0 이하일때
                return -1;
        }
        else { //몬스터에게 공격을 받지 않은 경우
            success++;
            if (success == t) { //연속 성공을 달성할 경우
                success = 0; //연속 성공 횟수 초기화
                if ((health + y) + x >= f_health) //만약 회복량이 체력 최대치를 넘길경우
                    health = f_health;
                else //최대치를 넘기지 않을때
                    health = (health + y) + x;
            }
            else { //연속 성공을 달성하지 못한 경우
                if ((health + x) >= f_health) //만약 회복량이 체력 최대치를 넘길경우
                    health = f_health;
                else //최대치를 넘기지 않을때
                    health = health + x;
            }
        }
    }

    answer = health;

    return answer;
}
