import java.util.*;

public class test {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        System.out.print("Input number to change : ");
        int n = s.nextInt();
        s.close();

        int answer = 0;
        ArrayList<Integer> ternary = new ArrayList<>();
        while (n != 0) {
            ternary.add(n % 3);
            n = n / 3;
        }
        int k = ternary.size()-1;
        for (int t: ternary){
            answer += (Math.pow(3, k))*t;
            k--;
        }

        System.out.println(answer);
    }

}
