import java.util.*;

class Solution {
    public String solution(String[] survey, int[] choices) {
        String answer = "";
        Map<String, Integer> perMap = new HashMap<>();

        //성격 유형 초기화
        String[] perType = {"RT", "CF", "JM", "AN"};
        for (String p : perType) {
            perMap.put(p.charAt(0) + "", 0); //char형 R을 string형으로
            perMap.put(p.charAt(1) + "", 0); //char형 T를 string형으로
        }

        //점수 계산
        for (int i = 0; i < survey.length; i++) {
            String s = survey[i];
            int choice = choices[i];

            if (choice < 4) {
                //선택지가 1, 2, 3이면 왼쪽
                perMap.put(s.charAt(0) + "", perMap.get(s.charAt(0) + "") + (4 - choice));
            } else if (choice > 4) {
                //선택지가 5, 6, 7이면 오른쪽
                perMap.put(s.charAt(1) + "", perMap.get(s.charAt(1) + "") + (choice - 4));
            }
        }

        // 결과 조합
        for (String p : perType) {
            int leftScore = perMap.get(p.charAt(0) + "");
            int rightScore = perMap.get(p.charAt(1) + "");

            if (leftScore >= rightScore) {
                answer += p.charAt(0);
            } else {
                answer += p.charAt(1);
            }
        }

        return answer;
    }
}
