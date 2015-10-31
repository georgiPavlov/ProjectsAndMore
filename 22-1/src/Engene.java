import java.util.ArrayList;

/**
 * Created by Georgi on 8/31/2015.
 */
public class Engene {
    private ArrayList<Point> allPointsIn;
    public ArrayList<Point> wall;
    private ArrayList<Point> oldMaxYPoint;


    public void makeWall(ArrayList<Point> allOfThePoints){
        wall=new ArrayList<Point>(10);
        //oldMaxYPoint=
        allPointsIn=allOfThePoints;
        Point start=allOfThePoints.get(0);
        Point startTemp=start;
        int u=0;
       // wall.add(start);
        Point second;
        do  {
            oldMaxYPoint=new ArrayList<Point>(10);
            second = findMaxY();
           // System.out.print(second.getX());
            while (searchOutOfBounds(startTemp, second)) {
                oldMaxYPoint.add(second);
                second = findMaxY();
            }
            oldMaxYPoint=null;
            wall.add(second);
            startTemp = second;
        u++;
        }while (u<2);

    }
y
    public Point findMaxY(){
        Point Y=allPointsIn.get(0);
        Point thisY;
        //int tempY=Y.getY();
        for(int i=1;i<allPointsIn.size();i++){
            thisY=allPointsIn.get(i);
            if(thisY.getY()>Y.getY()&& PointsInWall(thisY) && oldMaxY(thisY)){
                Y=thisY;

           }
         }
        System.out.println(Y.getY());
        return Y;
    }

    public boolean PointsInWall(Point yPoint){
        for(Point pointWall : wall){
            if(yPoint == pointWall){
                return false;
            }
        }
        return true;
    }


    private int lineX(Point start,Point second){

        int lineBoundX=(second.getX() + start.getX())/2;
        return lineBoundX;
    }

    private int lineY(Point start,Point second){

        int lineBoundY=(second.getY() + start.getY())/2;
        return lineBoundY;
    }

    private boolean searchOutOfBounds(Point start,Point second){
        int x = lineX( start, second);
        int y = lineY( start, second);

        for(Point temp : allPointsIn){
            if( temp.getY()>y && temp.getX()<x && PointsInWall(temp) ){

                return true;
            }

        }
        return false;
    }

    public boolean oldMaxY(Point yPoint){
        for(Point oldPoint : oldMaxYPoint){
            if(yPoint == oldPoint){
                return false;
            }
        }
        return true;
    }


}
