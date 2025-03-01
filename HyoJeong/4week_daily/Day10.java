import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        int count = 0;

        HashMap <Integer, Integer> map = new HashMap <>();

        //각 폰켓몬 종류를 HashMap에 저장
        for(int i : nums){
            map.put(i, 1);
        }

        //폰켓몬 종류와 N/2 중 더 작은 값을 출력
        return Math.min(map.size(), nums.length / 2);
    }
}
