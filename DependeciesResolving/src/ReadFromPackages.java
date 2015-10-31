import java.io.File;
import java.io.FileNotFoundException;

import java.util.Scanner;

/**
 * Created by Georgi on 10/29/2015.
 */
public class ReadFromPackages {
   private void ReadFromFile(){
         Scanner fileInput ;
         String line;
         String nameFile="E:\\TU_Georgi\\DependeciesResolving\\all_packages.json.txt";
         File file=new File(nameFile);


           fileInput = new Scanner(file);
           while (fileInput.hasNextLine()) {
               line = fileInput.nextLine();
               System.out.println(line);
               ReadFromLine(line);

           }
   }

    private void ReadFromLine(String temp)  {
        PackageInstall p =new PackageInstall();


        String[] arr=temp.split("[ \\[,\\]:\"]+");
        String[] arrTemp = new String[arr.length];
        int k=0;
        if((temp.contains("}")) || (temp.contains("{"))){return ; }
        for (int i = 0; i <arr.length ; i++) {

            if(!arr[i].equals("")) {
                p.setName(arr[i]);
                //System.out.println(arr[i]);
                //System.out.println(p.getName());

                for (int j = i+1; j < arr.length; j++) {
                    if(!arr[j].equals("")) {
                        arrTemp[k]=arr[j];
                        System.out.println(arrTemp[k]);
                        i=j;
                        k++;
                    }
                }
                p.setNeedPackages(arrTemp);
            }
            }

        }

    public static void main(String[] args){
        ReadFromPackages r= new ReadFromPackages();
        PackageInstall p;
        r.ReadFromFile();





    }

}
