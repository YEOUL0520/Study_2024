import java.util.*;

public class Deduplication {
    public int[] solution(int []arr) {
        Queue <Integer> queue = new LinkedList<>();

        for (int n=0; n<arr.length; n++){
            if (n < arr.length - 1 && arr[n] != arr[n+1]) {
                queue.add(arr[n]);
            }
            else if (n == arr.length -1)
                queue.add(arr[n]);
        }

        int[] answer = new int[queue.size()];

        int index = 0;
        for (int num : queue) {
            answer[index++] = num;
        }

        return answer;
    }
}