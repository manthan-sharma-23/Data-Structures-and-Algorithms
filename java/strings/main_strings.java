package strings;

public class main_strings {
    public static void main(String[] args) {
        // System.out.println("hello there");

        // String name = "Manthan Sharma";

        // System.out.println(name);
        // changeString(name);
        // System.out.println(name); // original object name cannot be changes

        // name = "Aditya";
        // System.out.println(name);
        // System.out.println();

        // Comparison of strings
        // == method comparator -->> Compare if object is same and have same address
        String a = "Manthan";
        String b = "Manthan";
        String e = a;
        System.out.println("Value and address transfered to an another variable in stack " + e == a);
        System.out.println(a == b);

        // here string value is same but object addresses is different as a new object
        // is being created actually creating values outside the pool inside the heap
        String c = new String("Java");
        String d = new String("Java");
        System.out.println("Different memory addresses -->> " + c == d);

        // when only needs to check vvalue use str.equals(str1) method
        System.out.println("Diffreent memory addresses but same value use .equals() " + c.equals(d));

    }

    static void changeString(String str) {
        str = "Sawraj";
    }
}