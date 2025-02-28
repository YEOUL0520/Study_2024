import java.util.*;

class Solution {
    public ArrayList<Integer> solution(int[] answers) {
        ArrayList<Integer> answer = new ArrayList<>();
        int[] correct = new int[3];

        int[] first = {1,2,3,4,5};
        int[] second = {2,1,2,3,2,4,2,5};
        int[] third = {3,3,1,1,2,2,4,4,5,5};

        for(int i=0; i<answers.length; i++){
            if(first[i%5] == answers[i]) { correct[0]++; }
            if(second[i%8] == answers[i]) { correct[1]++; }
            if(third[i%10] == answers[i]) { correct[2]++; }
        }

        int maxScore = Math.max(correct[0], Math.max(correct[1], correct[2]));

        if (correct[0] == maxScore) { answer.add(1); }
        if (correct[1] == maxScore) { answer.add(2); }
        if (correct[2] == maxScore) { answer.add(3); }

        return answer;
    }
}