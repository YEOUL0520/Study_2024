import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int scan = sc.nextInt();
        sc.nextLine();

        //StringBuilder 배열 생성, but 각 요소는 null (생성만 해 둔 상태로 StringBuilder 객체 가리키지 X)
        StringBuilder[] result = new StringBuilder[scan];

        for (int i = 0; i < scan; i++) {
            String input = sc.nextLine();
            String[] example = input.split(" ");

            int k = Integer.parseInt(example[0]);
            String word = example[1];
            result[i] = new StringBuilder(); //각 배열 요소에 할당

            for (int a = 0; a< word.length(); a++){
                for (int b = 0; b < k; b++) {
                    result[i].append(word.charAt(a));
                }
            }
        }

        for(StringBuilder s : result){
            System.out.println(s);
        }
    }
}
