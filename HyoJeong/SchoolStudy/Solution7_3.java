import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] result = new int[commands.length];

        for (int i = 0; i < commands.length; i++) {
            int start = commands[i][0] - 1; //자르기 시작할 위치
            int end = commands[i][1]; //자르기 끝낼 위치
            int k = commands[i][2]; //k번째

            //부분 배열 생성
            int[] slicedArray = Arrays.copyOfRange(array, start, end);

            //정렬
            Arrays.sort(slicedArray);

            //k번째 원소 출력
            result[i] = slicedArray[k - 1];
        }

        return result;
    }
}