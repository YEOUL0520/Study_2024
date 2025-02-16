import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());

        LinkedList <Integer> Q = new LinkedList<>();

        for (int k = 0; k < n; k++) {
            String function = scanner.next();
            switch (function) {
                case "push":
                    int i = Integer.parseInt(scanner.next());
                    Q.addLast(i);
                    break;
                case "pop":
                    if (Q.isEmpty())
                        System.out.println(-1);
                    else {
                        System.out.println(Q.removeFirst());
                    }
                    break;
                case "size":
                    System.out.println(Q.size());
                    break;
                case "empty":
                    if (Q.isEmpty())
                        System.out.println(1);
                    else
                        System.out.println(0);
                    break;
                case "front":
                    if (Q.isEmpty())
                        System.out.println(-1);
                    else
                        System.out.println(Q.getFirst());
                    break;
                case "back":
                    if (Q.isEmpty())
                        System.out.println(-1);
                    else
                        System.out.println(Q.getLast());
                    break;
            }
        }
        scanner.close();
    }
}
