import java.util.*;

class Tangerine {
    public int solution(int k, int[] tangerine) {
        int answer = 0;

        Map <Integer, Integer> tangerineMap = new HashMap <>();

        for (int t : tangerine)
        {
            tangerineMap.put (t, tangerineMap.getOrDefault(t, 0)+1);
        }

        List<Integer> valueList = new ArrayList<>(tangerineMap.keySet());
        valueList.sort(((o1, o2) -> tangerineMap.get(o2) - tangerineMap.get(o1)));

        for (int v : valueList) {
            k-= tangerineMap.get(v);
            answer++;
            if (k<=0)
                break;
        }

        return answer;
    }
}