import java.util.ArrayList;

/**
 * Created by Georgi on 9/2/2015.
 */

public class MatrixPath {
    private  String  matrix[][]= {
                                   {"x","0","x","x"},
                                   {"x","*","0","0"},
                                   {"0","x","0","x"},
                                   {"x","x","0","x"}
                                 };

    private ArrayList<Path> path;
    private int x;
    private int y;
    private int count;
    public MatrixPath(){
        this.x=1;
        this.y=1;
        count=0;
    }


    private void engine(int x,int y,String word){
        if(((x > matrix[0].length-1) ||( y >  matrix[0].length-1)) || (x < 0 || y < 0)){
            return;
        } else {
            if(matrix[y][x].equals("x")){
                return;
            }
            else if(matrix[y][x].equals("0")){
                matrix[this.y][this.x]="x";
                matrix[y][x]="*";
                this.y=y;
                this.x=x;
                count++;
            }
            SeeIfFould();
            engine(x+1,y,"right");//right
            engine(x,y+1,"down");//down
            engine(x-1,y,"left");//left
            engine(x,y-1,"up");//up
            count--;

        }

    }

    private void SeeIfFould(){
        if(((this.x == matrix[0].length-1) ||( this.y ==  matrix[0].length-1)) || (this.x == 0 || this.y == 0)){
            System.out.println("job done " + count );
            return;
        }
    }

    public void runEngine(){
        engine(this.x,this.y,"the roads: ");
    }

    public  static void main(String []argv){
        MatrixPath matrixPath=new MatrixPath();
        matrixPath.runEngine();
    }




}
