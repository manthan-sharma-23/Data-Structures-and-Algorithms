package arrays;

import java.util.*;

public class object {
    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        String[] strs = new String[4];
        for (int i=0;i<strs.length;i++) {
            strs[i] = in.next();
        }

        for (String string : strs) {
            System.out.print(string + " ");
        }
    }

}
