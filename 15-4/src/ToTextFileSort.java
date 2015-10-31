import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * Created by Georgi on 8/10/2015.
 */
public class ToTextFileSort {
    public static void main(String []argv){
        Scanner in=null;
        PrintStream out=null;
        StringBuilder fileInput=null;
        String nameFile="text.txt";
        String nameFile2="textSort.txt";
        String []words=null;
        String temp;

        try {
            File textFile=new File(nameFile);
            in=new Scanner(textFile);
            fileInput=new StringBuilder();
            while(in.hasNextLine()){

                fileInput.append(in.nextLine());
                fileInput.append(" ");

            }
            String a=fileInput.toString();
            words=a.split("[ ]+");
           for(int g=0;g<words.length-1;g++){
               for(int i=0,f=1;i<words.length-1-g;i++,f++){
                   if(words[i].compareToIgnoreCase(words[f])>=0) {
                       temp = words[i];
                       words[i] = words[f];
                       words[f] = temp;
                   }
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
                out=new PrintStream(nameFile2);
                for(int j=0;j<words.length;j++){
                    out.print(words [j] + "\n");
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
