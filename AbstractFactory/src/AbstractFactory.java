import java.util.Scanner;

/**
 * Created by Georgi on 9/29/2015.
 */
public class AbstractFactory {
    public static void main(String[] args){
        String[] mass=new String[5];
        int i =0;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter 5 strings");
        while(scanner.hasNext()){
            mass[i]=scanner.next();
            i++;
            if(i==5){
                break;
            }
        }
        for (int j = 0; j < mass.length; j++) {
            if(mass[j]!=null){
                System.out.print(mass[j]+" ");
            }

        }

    }
}
