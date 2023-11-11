package inheritance;

public class Boxweight extends Box {
    double weigth;

    public Boxweight() {
        this.weigth = -1;
    }

    Boxweight(double l, double w, double h, double weigth) {
        super(l, w, h);
        this.weigth = weigth;
    }
    Boxweight(Box box, double weigth) {
        super(box);
        this.weigth = weigth;
    }
}
