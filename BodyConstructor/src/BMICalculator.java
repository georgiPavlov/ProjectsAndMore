import java.util.Scanner;

/**
 * Created by Georgi on 10/4/2015.
 */
public class BMICalculator {
    private  double kilograms=0,height=0;

    public BMICalculator(){
        System.out.println("Program running for BMI!!");
    }

    public double getBMI(Scanner scanner){
        System.out.print("Enter your height in inches(1cm is 2.54 inches: ");
        height = scanner.nextDouble();
        System.out.print("Enter your mass in pounds(1 kilogram is 2.2046 pounds ): ");
        kilograms = scanner.nextDouble();
        return bmiFor();
    }

    private double bmiFor(){
        return 703*kilograms/(height*height);
    }

    public String  getStatus(){
        String[] status={"underweight","normal","overweight","obese"};
        double index = bmiFor();
        if(index <=18.5){
            return status[0];
        }
        else if(index >18.5 && index<=25){
            return status[1];
        }
        else if(index >25 && index<=30){
            return status[2];
        }
        else {
            return status[3];
        }
    }

    public void reportResults(int number,double BMIIndex,String status){
        System.out.print("Person number: " + number + "\n" +
                 "BMI: " + Math.round(BMIIndex) + "\n" +
                 "Status: " + status );
    }


}

