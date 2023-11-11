package statics.exp;

import statics.exp.Human;

public class Main {
    public static void main(String[] args) {
        Human Manthan = new Human(22, "Manthan Sharma", 70, false);
        Human Sawraj = new Human(22, "Sawraj Bansal", 65, false);

        System.out.println(Manthan);
        Main fun = new Main();
        fun.greet();
    }

    static void fun() {
        // greet(); //cannot access non static stuff in static stuff

        // have to use an instance for the same
        Main obj = new Main();
        obj.greet(); // can be used in this way

    }

    void greet() {
        System.out.println("Greet here");
    }
}
