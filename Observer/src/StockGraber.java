import java.util.ArrayList;

/**
 * Created by Georgi on 9/25/2015.
 */
public class StockGraber implements Subject {

    private ArrayList<Observer> observers;
    private double apple,google,IBM;


    public StockGraber(){
        observers = new ArrayList<Observer>();
    }


    @Override
    public void add(Observer newObserver) {
      observers.add(newObserver);
    }

    @Override
    public void delite(Observer newObserver) {
      int index = observers.indexOf(newObserver);
        observers.remove(index);
    }

    @Override
    public void notifyMe() {
        for (Observer observer : observers){
            observer.update(IBM,apple,google);
        }
    }

    public void setApple(double apple) {
        this.apple = apple;
        notifyMe();
    }

    public void setIBM(double IBM) {
        this.IBM = IBM;
        notifyMe();
    }

    public void setGoogle(double google) {
        this.google = google;
        notifyMe();
    }
}
