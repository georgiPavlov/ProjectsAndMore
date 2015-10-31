/**
 * Created by Georgi on 9/25/2015.
 */
public class ObserverTest {
    public static void main(String[] args){
        StockGraber stockGraber = new StockGraber();
        StockObserver observer = new StockObserver(stockGraber);
        stockGraber.setApple(12);
        stockGraber.setIBM(12);
        stockGraber.setGoogle(12);
        System.out.print(observer);

    }
}
