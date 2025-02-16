import java.util.*;

class Solution {
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        
        HashMap<Integer, Integer> hash = new HashMap<>();
        
        //해시맵에 귤 크기, 개수 저장
        for (int size : tangerine) {
            hash.put(size, hash.getOrDefault(size, 0) + 1);
        }
        
        //해시맵의 value를 기준으로 내림차순 정렬
        List<Map.Entry<Integer, Integer>> sortedList = new ArrayList<>(hash.entrySet());
        sortedList.sort((o1, o2) -> o2.getValue().compareTo(o1.getValue()));
        
        //
        for (Map.Entry<Integer, Integer> entry : sortedList) {
            k -= entry.getValue(); //현재 종류의 귤 개수를 - k
            answer++;
            
            if (k <= 0) {
                break; //k가 0 이하 되면 종료
            }
        }
        
        return answer;
    }
}
