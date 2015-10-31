import java.util.ArrayList;

/**
 * Created by Georgi on 8/31/2015.
 */
public class AddPoint {
    public ArrayList<Point> array;
    private Point newPoint;

    public AddPoint() {
        this.newPoint = new Point(1,1);
        this.array=new ArrayList<Point>();
        array.add(newPoint);

    }

    public  void addThePoint(int x,int y){
        this.newPoint= new Point(x,y);
        array.add(newPoint);
    }

    public ArrayList<Point> getArray() {
        return array;
    }

    public Point getNewPoint() {
        return newPoint;
    }
}
