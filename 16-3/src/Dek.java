/**
 * Created by Georgi on 8/13/2015.
 */
public class Dek {
   private  class Node{
       private Object apple;
       private Node node;

       public Node(Object apple){
           this.apple=apple;
           this.node=null;
       }

       public Node(Object apple,Node old){
           this.apple=apple;
           this.node=old;
       }
   }

    private Node headRight;
    private Node headLeft;
    private Node tailRight;
    private Node tailLeft;
    private int countRight;
    private int countLeft;

    public Dek(){
        headRight=null;
        headLeft=null;
        tailLeft=null;
        tailRight=null;
        countRight=0;
        countRight=0;
    }

    public void add(Object info,String side){
        if (countRight == 0 && countLeft == 0){
            Node newNode=new Node(info);
            if(side.equalsIgnoreCase("right")){
                headRight=newNode;
                tailRight=headRight;
                countRight++;
            }
            else{
                headLeft=newNode;
                tailLeft=headLeft;
                countLeft++;
            }
        }
        else if(countRight == 0){

            if(side.equalsIgnoreCase("right")){
                Node newNode=new Node(info);
                headRight=newNode;
                tailRight=headRight;
                tailRight.node=tailLeft;
                countRight++;
            }
        }
       else if(side.equalsIgnoreCase("right")){
          Node newNode = new Node(info,headRight);
            headRight = newNode;
            if(headLeft != null){
            tailRight.node= tailLeft;
            }
            countRight++;
        }
        else {
            Node newNode = new Node(info,headLeft);
            headLeft = newNode;
            if(headRight != null){
                tailLeft.node= tailRight;
            }
            countLeft++;
        }

    }

    public void remove(Object info ,String side) {
        Node headR = headRight;
        Node headL = headLeft;
        Node prevR = null;
        Node prevL = null;
        int index = 1;

        if (side.equalsIgnoreCase("right")) {
            while (index < countRight) {
                if (headR.equals(info)) {
                    break;
                }
                prevR = headR;
                headR = headR.node;
            }
            countRight--;
            if (countRight == 0) {
                if (countLeft == 0) {
                    headRight = null;
                    headLeft = null;
                    tailLeft = null;
                    tailRight = null;
                } else {
                    headRight = null;
                    tailRight = null;
                    tailLeft.node = null;
                }
            } else if (prevR != null) {
                headR = headR.node;
            } else {
                prevR.node = headR.node;
            }
        } else {
            while (index < countLeft) {
                if (headL.equals(info)) {
                    break;
                }
                prevL = headL;
                headL = headL.node;
            }
            countLeft--;
            if (countLeft == 0) {
                if (countRight == 0) {
                    headRight = null;
                    headLeft = null;
                    tailLeft = null;
                    tailRight = null;
                } else {
                    headLeft = null;
                    tailLeft = null;
                    tailRight.node = null;
                }
            } else if (prevL != null) {
                headL = headL.node;
            } else {
                prevL.node = headL.node;
            }
        }
    }

        public static void main (String []argv){
        Dek dek=new Dek();
        dek.add("one","righ");
        dek.add("one","right");
            dek.add("two","right");

        //dek.remove("one", "right");
        System.out.print(dek.headRight.apple);

        }




}
