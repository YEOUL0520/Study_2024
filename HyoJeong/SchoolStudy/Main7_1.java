import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String[] words = new String[5];
        String[] result = {};

        for (int i=0; i<5; i++){
            words[i] = sc.nextLine();
        }

        StringBuilder sb = new StringBuilder();
        for (int x=0; x<15; x++){
            for (int y=0; y<5; y++){
                if (x<words[y].length())
                    sb.append(words[y].charAt(x));
            }
        }

        System.out.print(sb);
    }
}
