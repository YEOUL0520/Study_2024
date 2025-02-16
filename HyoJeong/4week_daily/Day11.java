import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashSet <String> set = new HashSet<>();

        for (String s : participant){
            if (!set.contains(s)){
                set.add(s);
            }
            else
                set.remove(s);
        }
        for (String s : completion){
            if(!set.contains(s)){
                set.add(s);
            }
            else
                set.remove(s);
        }
        answer = String.join("", set);
        return answer;
    }
}
