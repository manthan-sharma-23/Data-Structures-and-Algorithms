package statics;

class Test {
    String name;

    Test(String name) {
        this.name = name;
    }
}

public class InnerClasses {
    // outside classes are never static because they are themselves not dependent on
    // any other class.

    public static void main(String[] args) {
        Test a = new Test("Kunal");
        Test b = new Test("Kunal");
    }
}
