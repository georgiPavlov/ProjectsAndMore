/**
 * Created by Georgi on 8/9/2015.
 */

public class Student {
    public enum work1{ONE,TWO,TREE};
    private String names;
    private int year;
    private String university;
    private String email;
    private long number;
    private String work;
    public  static int count=0;

    public Student(String names,int year,String university,String email){
        this.names=names;
        this.year=year;
        this.university=university;
        this.email=email;
        this.number=0;
        this.work=null;
        count++;
    }

    public String getNames(){
        return  names;
    }

    public String getUniversity() {
        return university;
    }

    public String getEmail() {
        return email;
    }

    public long getNumber() {
        return number;
    }

    public String getWork() {
        return work;
    }

    public int getYear(){
        return year;
    }

    public void information(){
        System.out.printf("The sudent names : %s \n student year: %d \n student university" +
                " : %s \n count: %d \n", names, year, university,count);
    }



}
