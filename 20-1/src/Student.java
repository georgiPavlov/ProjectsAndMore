/**
 * Created by Georgi on 8/28/2015.
 */
public class Student extends Human implements Comparable<Student> {
    int mark;

    public Student(String firstName, String lastName, int mark) {
        super(firstName, lastName);
        this.mark = mark;
    }

    public int getMark() {
        return mark;
    }

    public int compareTo(Student second) {
        return Integer.compare(this.getMark(), second.getMark());
    }
}
