package functions;

import java.util.*;

public class armstrong {
    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        int n = in.nextInt();
        if (checkArmStrong(n)) {
            System.out.println("true");
        } else {
            System.out.println("false");
        }

    }

    static boolean checkArmStrong(int n) {
        int a = n;
        int sum = 0;
        while (n > 0) {
            int rem = n % 10;
            n = n / 10;
            sum += rem * rem * rem;
        }

        return sum == a;
    }
}
