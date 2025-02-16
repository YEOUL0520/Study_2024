import java.util.*;

class Solution {
    public int[] solution(String today, String[] terms, String[] privacies) {
        // 모든 달은 28일
    	List<Integer> answer = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();
       
        //오늘 날짜 계산
        int todayDate = getDate(today);

        //약관 종류와 기간을 해시맵으로
        for (String s : terms) {
            String[] term = s.split(" ");
            map.put(term[0], Integer.parseInt(term[1]));
        }

        //개인정보 배열 privacies
        for (int i = 0; i < privacies.length; i++) {
            String[] privacy = privacies[i].split(" ");
            int privacyDate = getDate(privacy[0]);
            int totalDate = privacyDate + (map.get(privacy[1]) * 28);

            if (totalDate <= todayDate) {
                answer.add(i + 1);
            }
        }

        //리스트를 배열로 반환
        return answer.stream().mapToInt(i -> i).toArray();
    }

    //날짜를 정수로
    public static int getDate(String date) {
        String[] arr = date.split("\\.");
        int year = Integer.parseInt(arr[0]);
        int month = Integer.parseInt(arr[1]);
        int day = Integer.parseInt(arr[2]);
        //총 일수 계산
        return (year * 12 * 28) + (month * 28) + day;
    }
}


public class terms {
	public static void main(String[] args) {
		String today="";
		String[] terms= {};
		String[] privacies= {};
	}
}
