import java.util.ArrayList;

public class Solution {
    public int[] solution(int[] arr) {
        ArrayList<Integer> list=new ArrayList<>(); //list 선언
        
        list.add(arr[0]);
        for(int i=1;i<arr.length;i++){
            if(arr[i]!=arr[i-1]){
                list.add(arr[i]);
            }
        }
        //list를 배열로
        int[] temp = new int[list.size()];
        for(int j = 0; j < list.size(); j++){
            temp[j] = list.get(j);
        }
        
        return temp;
    }
}

public class hatesameNum {
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
