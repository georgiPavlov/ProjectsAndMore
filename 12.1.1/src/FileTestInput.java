import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * Created by Georgi on 8/10/2015.
 */
public class FileTestInput {
    public static void main(String []argv){
        //File one=null;
        Scanner in=null;
        int count=0;
        String line;
        try {

            String fileName="file1.txt";
            File one=new File(fileName);
            in=new Scanner(one);
            while(in.hasNextLine()){
                count++;
                line=in.nextLine();
                if(count % 2 !=0){
                    System.out.println(line);
                }
            }
        }
        catch(FileNotFoundException e){
            System.out.print("not fould file 1 " );
        }
        catch (NullPointerException e){
            System.out.print("not fould file 2 ");
        }
        finally {
            if(in !=null){
                in.close();
            }
        }



    }
}
