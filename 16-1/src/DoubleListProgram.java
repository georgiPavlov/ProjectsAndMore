/**
 * Created by Georgi on 8/12/2015.
 */
public class DoubleListProgram {

    private class Node{
        private Object a;
        private Node nodePointerLeft;
        private Node nodePointerRight;

        public Node(Object a ,Node old){
            this.a=a;
            old.nodePointerRight=this;
            this.nodePointerRight=null;
            this.nodePointerLeft=old;

        }

        public Node(Object a){
            this.a=a;
            this.nodePointerRight=null;
            this.nodePointerLeft=null;
        }
    }
    private Node headLeft;
    private Node headRight;
    private Node tailLeft;
    private Node tailRight;
    private int count=0;

    public DoubleListProgram(){
         this.headLeft=null;
         this.headRight=null;
         this.tailLeft=null;
         this.tailRight =null;
         this.count=0;
    }

    public void add(Object item){
        if( headRight == null && headLeft == null){
            headRight = new Node(item);
            headLeft = headRight;
            tailRight = headRight;
            tailLeft=headLeft;
        }
        else{
            Node oneNewNode=new Node(item,tailRight);
            tailRight=oneNewNode;
            headLeft=tailRight;
        }
        count++;
    }

    public int remove(Object item){

        int currentIndex=0;
        int leftRight =0;
        Node headR=headRight;
        Node prevHeadR=null;
        Node headL=headLeft;
        Node prevHeadL=null;
        Node temp=null;

        while(headR != null && headL !=null){
         if((headR != null && headR.a.equals(item))|| (headR== null && item == null)){
             leftRight =1;
             break;
            }
         else if((headL != null && headL.a.equals(item))|| (headL== null && item == null)){
             leftRight =2;
             break;
            }
            prevHeadR=headR;
            headR=headR.nodePointerRight;
            prevHeadL=headL;
            headL=headL.nodePointerLeft;
            currentIndex++;
        }
        count--;
        if(headR!= null && headL != null){
            if(count==0){
                headRight=null;
                tailRight=null;
                headLeft=headRight;
                tailLeft=tailRight;
            }
            else if(prevHeadR == null || prevHeadL == null){
                if(leftRight == 1){
                    headRight.nodePointerLeft=null;
                    headRight=headRight.nodePointerRight;

                }
                else if(leftRight == 2){
                    headLeft.nodePointerRight=null;
                    headLeft=headLeft.nodePointerLeft;
                }
            }
            else{
                if(leftRight == 1){
                    prevHeadR.nodePointerRight=headR.nodePointerRight;
                     headR.nodePointerLeft.nodePointerLeft=prevHeadR;
                }
                else if(leftRight == 2){

                    prevHeadL.nodePointerLeft = headL.nodePointerLeft;
                   headL.nodePointerLeft.nodePointerRight = prevHeadL;

                }
            }
        return currentIndex;
        }
        else{
            return -1;
        }


    }

    public void addIndex(Object item,int index){

       if(index <=count){
           Node oneNewNode=new Node(item);
        if( index == 1){
            oneNewNode.nodePointerRight=headRight;
            oneNewNode.nodePointerLeft=null;
        }
        else if (index == count){
            oneNewNode.nodePointerRight=headRight;
            oneNewNode.nodePointerLeft=null;
        }
        else{
            int addIndexRight=0;
            int addIndexLeft=count;
            int trueIndex=0;
            Node headR=headRight;
            Node prevHeadR=null;
            Node headL=headLeft;
            Node prevHeadL=null;
            Node temp=null;

            while(true){
                if(addIndexRight != index){
                    prevHeadR=headR;
                    headR=headR.nodePointerRight;
                    addIndexRight++;
                }
                else if(addIndexLeft != index){
                    prevHeadL=headL;
                    headL=headL.nodePointerLeft;
                    addIndexLeft--;
                }
                else if(!(addIndexRight != index)){
                  trueIndex=1;
                    break;
                }
                else if(!(addIndexLeft != index)){
                   trueIndex=2;
                    break;
                }
            }
            if(trueIndex == 1){

                prevHeadR.nodePointerRight=oneNewNode;
                oneNewNode.nodePointerRight=headR;
                headR.nodePointerLeft=oneNewNode;
                oneNewNode.nodePointerLeft=prevHeadR.nodePointerRight;


            }
            else if(trueIndex == 2){

                prevHeadL.nodePointerLeft=oneNewNode;
                oneNewNode.nodePointerLeft=headL;
                headL.nodePointerLeft.nodePointerRight=oneNewNode;
                oneNewNode.nodePointerRight=headL;
            }

        }
        count++;
       }
       else{
           System.out.println("Out of range");
       }
    }

    public static  void  main(String []argv){
        DoubleListProgram list=new DoubleListProgram();
        list.add("one");
        list.add("two");
        list.add("tree");
        list.add("four");

       // System.out.println(list.headRight.nodePointerRight.a);
        //System.out.println(list.headLeft.nodePointerLeft.nodePointerLeft.a);

        list.remove("tree");

        System.out.println(list.headLeft.nodePointerLeft.a);

        list.addIndex("tree", 3);
        System.out.println(list.headLeft.nodePointerLeft.nodePointerLeft.a);
        System.out.println(list.headRight.nodePointerRight.nodePointerRight.a);



    }

}
