package intro;

public class main {
    public static void main(String[] args) {
        // store data of 5 students: {roll no, name, marks} --> objects and classes
        // Student[] students=new Student[10];
        // constructor defines what to be done when the object gets created

        Student manthan = new Student(35, "Manthan Sharma", 88.5f);
        // Student() --> special type of function in a class called constructor

        // System.out.println(manthan.rno);
        // System.out.println(manthan.name);
        // System.out.println(manthan.marks);

        // manthan.rno = 13;
        // manthan.name = "Manthan Sharma";
        // manthan.marks = 92.5f;

        // System.out.println("\n" + manthan.rno);
        // System.out.println(manthan.name);
        // System.out.println(manthan.marks);

        // manthan.greeting();

        // Student someone = new Student();

        // System.out.println(someone.name);

        Student Aditya = new Student("Aditya Khitauliya", manthan);
        System.out.println(Aditya.name);
        System.out.println(Aditya.rno);
        System.out.println(Aditya.marks);
    }

}

// create a class
class Student {
    int rno;
    String name;
    float marks;

    void greeting() {
        System.out.println("Hello there, I am " + this.name);
    }

    Student(String name, Student other) { // constructor or function overloading
        this(other.rno,name,other.marks);
    }

    Student(int roll, String naam, float number) { // constructor
        this.name = naam;
        this.rno = roll;
        this.marks = number;
    }

    Student() { // constructor
        this(-1, "Anonymous", 100f);
    }
}