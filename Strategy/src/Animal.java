/**
 * Created by Georgi on 9/25/2015.
 */
public class Animal {

    Fly FlyT;



    public String  say(){
      return FlyT.FlyType();
    }

    public void set(Fly fly){
        FlyT = fly;
    }
}
