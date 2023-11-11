package inheritance;

public class Box {
    double l;
    double h;
    double w;

    Box() {
        this.h = -1;
        this.l = -1;
        this.w = -1;
    }

    // cube
    Box(double length) {
        this.l = length;
        this.h = length;
        this.w = length;
    }

    // cuboid
    Box(double l, double w, double h) {
        this.l = l;
        this.h = h;
        this.w = w;
    }

    // copy contructor
    Box(Box old) {
        this.l = old.l;
        this.h = old.h;
        this.w = old.w;
    }

    public void information() {
        System.out.println("Running the box");
    }

}
