import java.util.*;

public class counting {
    public static boolean main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        int countp = 0;
        int county = 0;

        for(char c : s.toCharArray())
        {
            if (c == 'p'||c == 'P')
                countp++;
            else if(c == 'y'|| c == 'Y')
                county++;

        }
        return countp == county;
    }
}
