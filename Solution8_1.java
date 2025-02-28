import java.util.*;

class Solution {
    public String solution(int[] food) {
        String answer = "";

        for(int n=1; n<food.length; n++){
            for (int i = 0; i<food[n]/2; i++){
                answer += n;
            }
        }

        StringBuilder sb = new StringBuilder(answer);
        String revanswer = sb.reverse().toString();
        answer = answer+0+revanswer;

        return answer;
    }
}