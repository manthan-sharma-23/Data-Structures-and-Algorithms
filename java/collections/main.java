package collections;

import java.util.*;

public class main {

    public static void main(String[] args) {
        ArrayList<String> studentName=new ArrayList<>();
        studentName.add("Manthan");

        // studentName.add(5,"Sawraj");
        studentName.add("Sawraj");
        String name=studentName.get(1);
        studentName.remove(1);

        System.out.println(studentName);
    }   
}
