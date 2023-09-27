package functions;

import java.util.*;

public class prime {
    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        int n = in.nextInt();
        boolean isPrime = isPrime1(n);
        // boolean isPrime = isPrime2(n);
        if (isPrime == true) {
            System.out.println("Prime !");
        } else {
            System.out.println("Not Prime !");
        }
    }

    // ONE WAY
    static boolean isPrime1(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;

    }

    // OTHER WAY
    static boolean isPrime2(int n) {
        if (n <= 1) {
            return false;

        }
        int c = 2;
        while (c * c <= n) {
            if (n % c == 0) {
                return false;
            }
            c++;
        }
        return c * c > n;
    }
}
