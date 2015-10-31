import java.util.Scanner;

/**
 * Created by Georgi on 9/29/2015.
 */
public  class Factory {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter ");
        String i = scanner.nextLine();
        ShipFactory shipFactory = new ShipFactory(i);

    }
}
