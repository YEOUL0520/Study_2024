import java.util.*;

class Sol {
    static List<String> list;
    static String[] words = {"A", "E", "I", "O", "U"};

    public int solution(String word) {
        int answer = 0;
        list = new ArrayList<>();
        dfs("", 0);
        
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).equals(word)) {
                answer = i;
                break;
            }
        }
        return answer;
    }

    // 단어 조합 생성
    void dfs(String str, int len) {
        list.add(str);
        if (len == 5)
            return;
        for (int i = 0; i < 5; i++) {
            dfs(str + words[i], len + 1);
        } 
    }
}

public class dict {
    public static void main(String[] args) {
        String word = "AAAAE";
        Sol sol = new Sol();
        System.out.println(sol.solution(word)); // 출력: 6
    }
}
