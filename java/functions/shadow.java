package functions;

import java.util.Arrays;

public class shadow {
    static int x = 90;

    public static void main(String[] args) {
        System.out.println(x);
        fun(2, 3, 4, 34, 23, 456, 5);
        multiple(3, 4, "Manthan", 3, 4, 5, 6); // prder of takign arguements in the function

        // function overloading
        first(56);
        first(56, 45);
        first("Manthan");
    }

    static void multiple(int a, int b, String name, int... v) {
        System.out.println(a + " " + b + " " + name + " " + Arrays.toString(v));
    }

    static void fun(int... v) { // v-> array of type int unassigned length of the array to variables
        System.out.println(Arrays.toString(v));
        System.out.println(v[0]);
    }

    /*
     * function overloading --> All functions have same name but different
     * arguements
     */

    static void first(int a) {
        System.out.println(a);
    }

    static void first(int a, int b) {
        System.out.println(b);
    }

    static void first(String a) {
        System.out.println(a);
    }
}
