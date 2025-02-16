import java.util.*;

public class Main {
    public static void main(String[] args){
        //Set <String> PW = new HashSet<String>();
        ArrayList <String> PW = new ArrayList<String>();
        String reverse = "";

        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());

        for (int i = 0; i<n; i++){
            String password = scanner.nextLine();
            PW.add(password);
            reverse = new StringBuilder(password).reverse().toString();

            if(PW.contains(reverse)) {
                int length = password.length();
                char midChar = password.charAt(length / 2);

                System.out.println(length + " " + midChar);
                return;
            }
        }
        scanner.close();
    }
}
