package arrays;

import java.util.*;

// when you dont know the size of array you want to use

public class arrayList {
    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<Integer>(10);

        list.add(43);
        list.add(43);
        list.add(3434);

        for (int i = 0; i < 11; i++) {
            list.add(in.nextInt());
        }

        System.out.println(list);
    }
}
