/**
 * Created by Georgi on 8/10/2015.
 */

import java.io.*;
import java.io.File;
import java.util.*;
public class FileText {
    public static void main(String []argv){
        //File one=null;
        Scanner in=null;
        int count=0;
        String line;
        try {

            in=new Scanner(new File("text.txt"));
            while(in.hasNextLine()){
                count++;
                line=in.nextLine();
                if(count % 2 !=0){
                    System.out.println(line);
                }
            }
        }
        catch(FileNotFoundException e){
            System.out.print("not fould file");
        }
        catch (NullPointerException e){
            System.out.print("not fould file");
        }
        finally {
            if(in !=null){
                in.close();
            }
        }



    }
}
