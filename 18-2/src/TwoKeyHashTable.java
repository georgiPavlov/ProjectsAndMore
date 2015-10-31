import java.util.Hashtable;

/**
 * Created by Georgi on 8/23/2015.
 */
public class TwoKeyHashTable {
    Hashtable<String,Integer> one=new Hashtable<String, Integer>(10);
    Hashtable<Integer,Hashtable<String,Integer>> hashtable;

    public void add(){
        hashtable=new Hashtable<Integer, Hashtable<String, Integer>>(15);

        one.put("one",1);
        one.put("two",2);
        hashtable.put(10,one);
        hashtable.put(11,one);
    }

    public void surch(){
        Integer key1=11;
        String key2="two";
        Hashtable<String,Integer> temp = new Hashtable<String,Integer>(1);
        temp=hashtable.get(11);
        System.out.print(temp.get("one"));
    }

    public static  void main(String []argv){
        TwoKeyHashTable twoKeyHashTable=new TwoKeyHashTable();
        twoKeyHashTable.add();
        twoKeyHashTable.surch();
    }
}
