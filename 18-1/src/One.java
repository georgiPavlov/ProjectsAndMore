import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;
import  java.util.Map;

/**
 * Created by Georgi on 8/22/2015.
 */
public class One {
    int []arr={1,3,4,4,4,2,2,1};
    Map<Integer,Integer> hashMap=new TreeMap<Integer,Integer>();
    Integer count;


    public void addHash(){
        for(int i=0;i<arr.length;i++){
            count=hashMap.get(arr[i]);
            if(count== null){
                count=0;
            }
            hashMap.put(arr[i],count+1);

        }
        for(Map.Entry<Integer,Integer> one1 : hashMap.entrySet()){
            Integer key=one1.getKey();
            Integer count2=one1.getValue();
            if(count2 % 2 != 0 ) {
                hashMap.put(key,0);
            }

        }
    }



    public void printHash(){
        int i=0;
       for(Map.Entry<Integer,Integer> one : hashMap.entrySet()){
           if(one.getValue()!= 0){
           System.out.println("number: " + one.getKey() + " count: " + one.getValue());}
       }
    }
    public static void main(String[] argv){
        One two=new One();
        two.addHash();
        two.printHash();

    }


}
