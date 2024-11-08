import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());

        Stack<Integer> S = new Stack<>();

        for (int k = 0; k < n; k++) {
            String function = scanner.next();
            switch (function) {
                case "push":
                    int i = Integer.parseInt(scanner.next());
                    S.push(i);
                    break;
                case "pop":
                    if (S.isEmpty())
                        System.out.println(-1);
                    else {
                        System.out.println(S.pop());
                    }
                    break;
                case "size":
                    System.out.println(S.size());
                    break;
                case "empty":
                    if (S.isEmpty())
                        System.out.println(1);
                    else
                        System.out.println(0);
                    break;
                case "top":
                    if (S.isEmpty())
                        System.out.println(-1);
                    else {
                        System.out.println(S.peek());
                    }
                    break;
            }
        }
        scanner.close();
    }
}
