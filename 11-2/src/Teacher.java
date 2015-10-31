/**
 * Created by Georgi on 8/9/2015.
 */
import java.util.Scanner;
public class Teacher {
    private String teacher;
    private String disciplineName;
    private int coursesName;
    private int examplesName;
    private Scanner in= new Scanner(System.in);

    public String getDisciplineName() {
        return disciplineName;
    }

    public void setDisciplineName() {
        System.out.print("Enter disciplene ");
        this.disciplineName=in.nextLine();
    }

    public void setTeacher() {
        System.out.print("Enter teacher name ");
        this.teacher= in.nextLine();

    }

    public String getTeacher() {

        return teacher;
    }

    public int getExamplesName() {
        return examplesName;
    }

    public void setExamplesName() {
        System.out.print("Enter Examplename (int) ");
        this.examplesName = in.nextInt();
    }

    public int getCoursesName() {
        return coursesName;
    }

    public void setCoursesName() {
        System.out.print("Enter course ");
        this.coursesName =in.nextInt();
    }

    public Teacher() {

        this.setTeacher();
        System.out.printf("teacher %s \n", this.teacher);
        this.setDisciplineName();
        this.setCoursesName();
        this.setExamplesName();
        Discipline disciplineObject =new Discipline(getDisciplineName(),getCoursesName(),getExamplesName());
        disciplineObject.print();

    }


}
