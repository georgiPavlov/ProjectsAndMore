import java.util.Arrays;
import java.util.Comparator;
import java.util.Objects;

/**
 * Created by Georgi on 8/28/2015.
 */
public class Main {
    public static void main(String[]argv){
        Student []student=new Student[10];


        student[0]=new Student("pesho","petrov",6);
        student[1]=new Student("pesho","petrov",5);
        student[2]=new Student("pesho","petrov",3);
        student[3]=new Student("pesho","petrov",4);
        student[4]=new Student("pesho","petrov",5);
        student[5]=new Student("pesho","petrov",6);
        student[6]=new Student("pesho","petrov",2);
        student[7]=new Student("pesho","petrov",2);
        student[8]=new Student("pesho","petrov",5);
        student[9]=new Student("pesho","petrov",6);


        Arrays.sort(student);






        for(Student oneStudentPrint : student){
            System.out.println(oneStudentPrint.getFirstName()+ " " +
                    oneStudentPrint.getLastName()+" "+ oneStudentPrint.getMark());

        }




    }
}
