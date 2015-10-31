/**
 * Created by Georgi on 8/13/2015.
 */
public class ArrayReverse {
    private Object []array;
    private int count;
    private static  final int BIG=4;
    private int index=BIG;

    public ArrayReverse(){
        array=new Object[BIG];
        count=0;
    }

    public int getCount(){
        return count;
    }

    public void add(Object info){
        Object []arrayNew;
        if(index == 0){
            arrayNew=new Object[array.length*2];
            int i=array.length-1;
            int j=arrayNew.length-1;
            for(;i >=0;i--,j--){
             arrayNew[j]=array[i];
                index=j;
            }
            array=arrayNew;
            array[index]=info;
            count++;
        }
        else{
            array[index-1]=info;
            index--;
            count++;
        }
        //System.arraycopy(arr, arr.length-count-1,arrayNew,arrayNew.length-count-2,count); оригинално решение!!
    }

    public  static void main(String []argv){
        ArrayReverse arr=new ArrayReverse();
        arr.add("one");
        arr.add("two");
        arr.add("tree");
        arr.add("four");
        arr.add("five");
        arr.add("six");

        //System.out.print(arr.array[3]);
        for(int u=0;u<arr.array.length; u++){
           if(arr.array[u] != null){
            System.out.println(arr.array[u]);
           }
        }


    }


}
