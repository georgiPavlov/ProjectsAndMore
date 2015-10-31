/**
 * Created by Georgi on 8/30/2015.
 */
public class Garden {
 public static void main(String[] argv){
     AddPoint addPoint=new AddPoint();
     addPoint.addThePoint(3,5);
     addPoint.addThePoint(7,5);
     addPoint.addThePoint(3,9);
     Engene engene=new Engene();
     engene.makeWall(addPoint.array);

     //System.out.print(engene.wall.get(0).getX());


 }
}
