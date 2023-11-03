package intro;

public class main {
    public static void main(String[] args) {
        // store data of 5 students: {roll no, name, marks} --> objects and classes
        // Student[] students=new Student[10];
        // constructor defines what to be done when the object gets created

        Student manthan=new Student();
       
        manthan.rno=13;
        manthan.name="Manthan Sharma";
        manthan.marks=92.5f;

        System.out.println(manthan.rno);
        System.out.println(manthan.name);
        System.out.println(manthan.marks);

    }

}

// create a class
class Student {
    int rno;
    String name;
    float marks;
}