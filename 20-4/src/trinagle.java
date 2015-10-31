/**
 * Created by Georgi on 8/29/2015.
 */
public class trinagle implements Shape {
     int result;
     public int calculate(){
        return (height*width)/2;
    }

    public trinagle() {
     result= calculate();
    }

    public static void main(String[] argv){
       trinagle trinagle2=new trinagle();
        System.out.print(trinagle2.result);
     }
}
