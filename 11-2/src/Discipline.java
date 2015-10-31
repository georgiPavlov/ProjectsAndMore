/**
 * Created by Georgi on 8/9/2015.
 */
public class Discipline {
    private String disciplineName;
    private int courses;
    private int examples;

    public void setExamples(int examples) {
        this.examples = examples;
    }

    public void setDisciplineName(String disciplineName) {
        this.disciplineName = disciplineName;
    }

    public void setCourses(int courses) {
        this.courses = courses;
    }

    public Discipline(String disciplineName, int courses, int examples) {
        this.disciplineName = disciplineName;
        this.courses = courses;
        this.examples = examples;


    }

    public int getExamples() {

        return examples;
    }

    public int getCourses() {
        return courses;
    }

    public String getDisciplineName() {
        return disciplineName;
    }
    public void print(){
        System.out.printf("\n Discipline %s \n Couses %d \n Example %d \n " , disciplineName,courses,examples);
    }
}
