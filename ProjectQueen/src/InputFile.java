/**
 * Created by Georgi on 10/25/2015.
 */
import java.lang.*;
import java.util.Scanner;

public class InputFile {
   void be() throws Exception2{
       int a;
       boolean trueInt=false;
       Scanner scanner = new Scanner(System.in);
       while (!trueInt) {

           try {
               System.out.println("Wnter");

               a = scanner.nextInt();

               trueInt=true;
           } catch (Exception e) {

               throw  new Exception2();
           }
           finally {
               System.out.println("a");
           }

       }
   }

    class Exception2 extends Exception{

        @Override
        public String getMessage(){

            return "Invalid price!";

        }
    }

    public static void main(String[] args){
        InputFile inputFile = new InputFile();
       try {
           inputFile.be();
       }
       catch (Exception2 e){
           System.out.println("err");
           System.out.print(e.getMessage());
       }
        finally {
           System.out.println("t");

       }
    }

}
