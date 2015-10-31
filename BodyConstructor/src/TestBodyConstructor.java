import java.util.Scanner;

/**
 * Created by Georgi on 10/4/2015.
 */
public class TestBodyConstructor {
    public static void main(String[] args){
        Scanner scanner= new Scanner(System.in);
        BMICalculator bmiCalculator = new BMICalculator();
        bmiCalculator.reportResults(1,bmiCalculator.getBMI(scanner),bmiCalculator.getStatus());
    }
}
