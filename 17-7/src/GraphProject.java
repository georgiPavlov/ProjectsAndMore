import java.io.*;
import java.lang.*;

/**
 * Created by Georgi on 8/20/2015.
 */
import  java.util.*;

public class GraphProject {

     public  class Node{
         private int number;
         private Node pointer;

         public Node(int number,Node old){
           this.number=number;
           pointer=old;
         }
     }
     public class Vertex{
          private String name;
          private  Node list;

         public Vertex(String name,Node list){
             this.name=name;
             this.list=list;
         }
     }

    Vertex []vertexes;

    private int find(String nameNode){
        for(int i=0;i<vertexes.length;i++){
        if(vertexes[i].name.equals(nameNode))  {
            return i;
        }
        }
    return 0;
    }
    public void readFile(){
        //File input =new File("example.txt");
         String file="E:\\TU_Georgi\\17-7\\example.txt";
         Scanner scanner=new Scanner(new File(file));
         vertexes=new Vertex[scanner.nextInt()];
        for(int i=0;i<vertexes.length;i++){
            vertexes[i]=new Vertex(scanner.nextLine(),null);
        }
        while(scanner.hasNext()){
            int name1Number =find(scanner.next());
            int name2Number =find(scanner.next());

            vertexes[name1Number].list=new Node(name2Number,vertexes[name1Number].list);
        }
    }

    private void print(){
        for(int i=0;i<vertexes.length;i++){
            for(Node temp=vertexes[i].list;vertexes[i].list != null;temp=vertexes[i].list.pointer){
                System.out.println(vertexes[i].name +  " -> " + vertexes[temp.number].name );
            }
        }
    }

    public static void main(String argv[]){
        GraphProject graphProject=new GraphProject();
        graphProject.print();
    }

}
