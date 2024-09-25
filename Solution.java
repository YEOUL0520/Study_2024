import java.util.*;
import java.time.LocalDate;

class Solution {
    public int[] solution(String today, String[] terms, String[] privacies) {
        int count = 0;
        int[] answer = {};
        int[] result = new int[privacies.length];
        HashMap<String, Integer> map = new HashMap<>();

        //terms를 공백 기준으로 나누고 hashmap에 넣어줌
        for (String i : terms) {
            String[] parts = i.split(" ");
            map.put(parts[0], Integer.parseInt(parts[1]));
        }

        //today를 .기준으로 나누고 .빼고 다시 합쳐줄 배열 todayDate생성
        String[] t = today.split("\\.");
        int[] todayDate = new int[3]; //year, month, date 총 3개
        for (int i = 0; i < 3; i++) {
            todayDate[i] = Integer.valueOf(t[i]);
        }

        //JAVA의 LocalDate를 사용해 todayD를 생성
        LocalDate todayD = LocalDate.of(todayDate[0], todayDate[1], todayDate[2]);

        for (int i = 0; i < privacies.length; i++) {
            String[] temp = privacies[i].split(" ");
            String day = temp[0];
            String name = temp[1];

            int during = map.get(name);

            String[] s = day.split("\\.");
            int[] signs = new int[3];
            for (int j = 0; j < 3; j++) {
                signs[j] = Integer.valueOf(s[j]);
            }
            LocalDate signday = LocalDate.of(signs[0], signs[1], signs[2]);

            //만기일은 사인한 날 하루전에 만기되므로 1을 빼줘야 함
            //LocalDate써도 괜찮은 이유 = day의 마지막이 31이므로 1일에서 -1이 되어 31이 되더라도 어떤 경우에라도 28<31, 만기일보다 크다.
            LocalDate expire = signday.plusMonths(during).minusDays(1);

            //오늘 날짜가 만기일보다 크면 삭제
            if (todayD.isAfter(expire)) {
                result[count] = i + 1;
                count++;
            }

        }

        answer = new int[count];
        for (int i = 0; i < count; i++) {
            answer[i] = result[i];
        }

        return answer;
    }
}
