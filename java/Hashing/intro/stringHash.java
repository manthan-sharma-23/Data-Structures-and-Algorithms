package Hashing.intro;

import java.util.*;

public class stringHash {
    public static void main(String[] args) {
        String name = "abcdaebhjfuabzAGH ";

        char[] charArray = name.toCharArray();
        System.out.println("Your char Array --> " + Arrays.toString(charArray));
        int[] hsh = HashString(charArray);
        System.out.println("Hash arr --> " + Arrays.toString(hsh));
    }

    static int[] HashString(char[] str) {
        int[] hash = new int[26]; // just lower case letters
        for (int i = 0; i < str.length; i++) {
            hash[str[i] - 'a'] += 1;
        }
        return hash;
    }
}
