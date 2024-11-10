import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());

        Stack<String> S = new Stack<>();

        for (int i = 0; i < n; i++) {
            String sentence = scanner.nextLine();
            String[] RS = sentence.split(" ");
            for (String rs : RS){
                S.push(rs);
            }
            System.out.print("Case #" + (i + 1) + ": ");
            while (S.isEmpty() == false){
                System.out.print(S.pop() + " ");
            }
            System.out.println();
        }
    }

}
