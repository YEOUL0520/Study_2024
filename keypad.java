package codingTest;
import java.util.*;

class solutionK1{
	String keyboard(int[] numbers,String hand) {
		//각번호를 누른 엄지 손가락이 뭔지 리턴
		String result="";
		//상,하,좌,우(4가지 방향)으로만 이동 가능
		for(int i:numbers) {
			//왼손,오른손 위치 필요
			int left=10;
			int right=12;
			//1,4,7
			if(i==1 || i==4 || i==7) {
				result+="L";
			}
			//3,6,9
			else if(i==3 || i==6 || i==9) {
				result+="R";
			}
			//2,5,8,0
			else {
				
			}
		}
		return result;
	}
}

public class keypad {
	public static void main(String[] args) {
		//누를번호가 담긴 배열
		int[] numbers= {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
		//어떤 손잡이인지 나타내는 문자열
		String hand="right";
		solutionK1 s=new solutionK1();
		System.out.println(s.keyboard(numbers, hand));
	}
}
