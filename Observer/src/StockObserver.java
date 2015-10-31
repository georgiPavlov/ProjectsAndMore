/**
 * Created by Georgi on 9/25/2015.
 */
public class StockObserver implements Observer {
    private double IBM;
    private double Apple;
    private double Google;

    private  Subject subject;

    public StockObserver(Subject subject){
        this.subject=subject;
        subject.add(this);


    }

    @Override
    public void update(double IBM, double Apple, double Google) {
            this.IBM=IBM;
            this.Apple=Apple;
            this.Google=Google;


    }
}
