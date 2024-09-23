import java.util.*;

class Solution1 {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int answer = 0;
        int attacksNum = attacks.length;
        int maxHealth = health;
        int time = 0; // 몬스터 시간용
        int continuous = 0; // 연속 회복 횟수

        // 공격 시간을 기준으로 반복
        for (int i = 0; i <= attacks[attacksNum - 1][0]; i++) {
            // 현재 시간이 공격시간인지
            if (attacks[time][0] == i) {
                health -= attacks[time][1]; // 피해량 적용
                continuous = 0; // 연속 회복 초기화
                time++;
            }
            else {
                // 회복 처리
                if (continuous <= bandage[0]) {
                    health += bandage[1]; // 1초당 회복량
                    continuous++;
                }
                // 연속 회복이 끝났을 때 추가 회복 처리
                if (continuous == bandage[0]) {
                    health += bandage[2]; // 추가 회복량
                    continuous = 0; // 연속 회복 초기화
                }
            }

            // 체력이 최대를 초과하지 않도록 조정
            if (health > maxHealth) {
                health = maxHealth;
            }

            // 체력이 0 이하가 되면 종료
            if (health <= 0) {
                answer = -1; // 실패
                break;
            }
        }

        // 체력이 남아있다면 최종 체력 반환
        if (health > 0) {
            answer = health;
        }
        
        return answer;
    }
}

public class qndeo {
    public static void main(String[] args) {
        Solution1 sol = new Solution1();
        int[] bandage = {5, 1, 5}; // 붕대 감기 시전 시간, 1초당 회복량, 추가 회복량
        int health = 30; // 최대 체력
        int[][] attacks = {{2, 10}, {9, 15}, {10, 5}, {11, 5}}; // 몬스터 공격 시간, 피해량
        System.out.println(sol.solution(bandage, health, attacks));
    }
}
