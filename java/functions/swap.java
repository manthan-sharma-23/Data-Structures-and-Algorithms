package functions;

public class swap {
    static int Swap(int a, int b) {
        int temp = a;
        a = b;
        b = temp;

        return b;
    }

    public static void main(String[] args) {
        int a = 10;
        int b = 20;

        // swap code
        int temp = a;
        a = b;
        b = temp;

        System.out.println(a + " " + b);

    }
}
