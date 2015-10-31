/**
 * Created by Georgi on 8/13/2015.
 */
public class Example2 {
    private class StackD{
        private Object apple;
        private StackD stack;

        public StackD(Object apple,StackD stackOld){
            this.apple=apple;
            this.stack=stackOld;
        }

        public  StackD(Object apple){
            this.apple=apple;
            this.stack=null;
        }
    }

    private StackD head;
    private StackD tail;
    int count;

    public Example2(){
        head=null;
        tail=null;
        count=0;
    }

    public int  push (Object item){
       if(head == null){
           StackD newStack= new StackD(item);
           head=newStack;
           tail=head;
       }
        else{
           StackD newStack= new StackD(item,head);
           head=newStack;
       }
        count++;
        return count;
    }

    public Object pop(){
       Object popObject;
        if(count == 1){
            popObject=head.apple;
            head=null;
            tail=null;
        }
        else{
            popObject=head.apple;
            head=head.stack;
        }
        count--;
        return popObject;
    }

    public Object peek(){

           Object peekObject;
           peekObject =head.apple;
           return peekObject;
    }

    public int size(){
        return count;
    }

    public  boolean contains(Object item){
        int index=count;
        boolean  b = false;
        StackD containsNode=head;
        while(index > 0){
           if(containsNode.apple.equals(item)) {
               b=true;
               break;
           }
            containsNode=containsNode.stack;
            index--;
        }
        if (b) return true;
        else return false;
    }

    public Object toArray(){
        Object []array=new Object[count];
        StackD arrStack;
        int a=0;
        for(arrStack=head;a<count;a++,arrStack=arrStack.stack ){
            array[a]=arrStack.apple;
        }
        return  array;
    }

    public static void main (String []argv){
        Example2 example2=new Example2();

        example2.push("one");
        example2.push("two");
        example2.push("tree");
        example2.push("four");
        example2.push("five");

        System.out.println(example2.size());
        System.out.println(example2.head.apple);
        System.out.println(example2.head.stack.apple);

        Object one =example2.pop();
        System.out.println(one);

        System.out.print(example2.contains("one"));
    }
}
