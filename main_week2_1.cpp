#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    //체력 관리
    int maxHealth = health; //최대 체력량 저장
    int currentHealth = health; //현재 체력

    //스킬셋
    int bandageDuration = bandage[0]; //붕대 감기 시전 시간
    int healAmount = bandage[1]; //초당 회복량
    int bonusHeal = bandage[2]; //연속 성공 시 추가 회복량

    //연산 위해 필요한 상수
    int time = attacks[attacks.size() - 1][0];
    int bandageContinue = 0; //연속 붕대 감기 성공 시간
    int lastAttackIndex = 0; //마지막 공격 인덱스

    for (int t = 0; t <= time; t++) {
        if (attacks[lastAttackIndex][0] == t) {
            currentHealth -= attacks[lastAttackIndex][1]; // 체력 감소
            //다이다이할경우
            if (currentHealth <= 0)
                return -1;
            lastAttackIndex++; //다음 공격으로 이동
            bandageContinue = 0; //연속 성공 시간 초기화
        }
        else {

            //붕대 감기 시전중
            if (bandageContinue <= bandageDuration) {
                currentHealth += healAmount; //체력 회복
                bandageContinue++; //성공 시간 증가
            }
            //붕대 감기 완료
            if (bandageContinue == bandageDuration) {
                currentHealth += bonusHeal; //추가 체력 증가
                bandageContinue = 0;
            }
            // 체력이 최대 체력을 넘지 않도록 조정
            if (currentHealth > maxHealth) {
                currentHealth = maxHealth;
            }

        }
    }

    return currentHealth;
}
