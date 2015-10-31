/**
 * Created by Georgi on 10/3/2015.
 */
public class Singleton {
    private static Singleton singleton=null;
    private Singleton(){}
    public Singleton cingletonMake(){
        if(singleton == null){
            singleton= new Singleton();
        }
        return singleton;
    }
}
