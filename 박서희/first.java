import java.util.*;

class Solution {
    public int solution(String[] friends, String[] gifts) {
    	 int answer = 0;
         int friendsLenght = friends.length;
         
         HashMap<String, Integer> dic = new HashMap<>();

         for ( int i = 0; i < friendsLenght; i++ ) {
             dic.put(friends[i], i);
         }
         
         int[] giftDegree = new int[friendsLenght];
         int[][] giftGraph = new int[friendsLenght][friendsLenght];
         
         for ( String gift : gifts ) {
             String[] giftName = gift.split(" ");
//             System.out.println(giftName[0]);
//             System.out.println(giftName[1]);
             giftDegree[dic.get(giftName[0])]++;
             giftDegree[dic.get(giftName[1])]--;
             giftGraph[dic.get(giftName[0])][dic.get(giftName[1])]++;    
         }
         
         for ( int i =0; i< friendsLenght; i++) {
             int num = 0;
             for ( int j = 0; j< friendsLenght; j++) {
                 if ( i == j) {
                     continue;
                 }    
                 
                 if (giftGraph[i][j] > giftGraph[j][i] ||
                      (giftGraph[i][j] == giftGraph[j][i] && giftDegree[i] > giftDegree[j])) {
                         num++;
                     }
             }
             
             if ( answer < num) {
                 answer = num;
             }
         }
         
         return answer;
    }
}

public class first {
	public static void main(String[] args) {
		Solution sol=new Solution();
		String[] friends= {"muzi", "ryan", "frodo", "neo"};
		String[] gifts= {"muzi frodo", "muzi frodo",
						"ryan muzi", "ryan muzi", "ryan muzi",
						"frodo muzi", "frodo ryan",
						"neo muzi"};	
		System.out.println(sol.solution(friends, gifts));
	}
}
