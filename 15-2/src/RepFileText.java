/**
 * Created by Georgi on 8/10/2015.
 */
import java.io.*;
import java.util.*;

public class RepFileText {
    public static void main(String []argv){
        Scanner in=null;
        PrintStream out=null;
        StringBuilder fileInput=null;
        String nameFile="text.txt";
        String key= "finally";
        String []words=null;

        try {
            File textFile=new File(nameFile);
            in=new Scanner(textFile);
            fileInput=new StringBuilder();
            while(in.hasNextLine()){

                   fileInput.append(in.nextLine());

            }
            String a=fileInput.toString();
            words=a.split("[ ]+");
            for(int i=0;i<words.length;i++){
                if(words[i].equalsIgnoreCase("one")){
                    words[i]=key;
                }
            }
        }
        catch (FileNotFoundException e){
            System.out.print("the file " + nameFile  + " was not found!!!\n");
        }
        catch (NullPointerException b){
            System.out.print("the file " + nameFile  + " was not found!!!");
        }

        finally {
            if(in !=null){
                in.close();
            }

            try {
                out=new PrintStream(nameFile);
                for(int j=0;j<words.length;j++){
                    out.print(words [j] + " ");
                }
            }
            catch (FileNotFoundException f){
                System.out.print("the file " + nameFile  + " was not found 2 !!!\n ");

            }
            catch (NullPointerException n){
                System.out.print("the file " + nameFile  + " was not found 2 !!!");

            }
            finally {
               if(out != null){
                   out.close();
               }


                System.out.println("\n job done");
            }
        }

    }
}
