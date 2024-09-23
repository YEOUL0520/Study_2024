import java.util.*;

class Solution2{
    public int solution(int[] d, int budget) {
        int answer = 0;
        
        Arrays.sort(d);
        for(int i=0;i<d.length;i++) {
        	if(budget-d[i]<0) {
        		break;
        	}
        	else {
        		budget-=d[i];
        		answer++;
        	}
        }
        
        return answer;
    }
}

public class dPtks {
	public static void main(String[] args) {
		int[] d= {1,3,2,5,4};
		int budget=9;
		Solution2 sol=new Solution2();
		System.out.println(sol.solution(d, budget));
	}
}
