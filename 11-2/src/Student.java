/**
 * Created by Georgi on 8/9/2015.
 */
import java.util.Scanner;

public class Student {
    private String name;
    private int number;
    private Scanner in= new Scanner(System.in);

    public Student() {
        this.setName();
        this.setNumber();
    }

    public void setName() {

        System.out.print("Enter name ");
        this.name = in.nextLine();
    }

    public void setNumber() {
        System.out.print("Enter number ");
        this.number = in.nextInt();
    }

    public String getName() {

        return name;
    }

    public int getNumber() {
        return number;
    }
    public void print(){
        System.out.printf("\nStudent %s \nNumber %d \n\n" ,name,number);
    }
}
