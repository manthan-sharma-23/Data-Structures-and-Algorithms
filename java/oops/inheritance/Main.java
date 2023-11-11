package inheritance;

// import inheritance.Box;

public class Main {
    public static void main(String[] args) {
        Box pack = new Box(4);
        Box box = new Box(pack);

        System.out.println(box.l + " " + box.h + " " + box.w + "  ");

        Boxweight bwt = new Boxweight(box, 45);
        System.out.println(bwt.weigth);

        Box vx = new Boxweight(box, 34); //Box weght creates an object in Heap memory
        // vx.weigth; // Box refrence vx is a refrence type which allows specific members that are not private in Box class.

    }
}
