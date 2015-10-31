import java.util.HashSet;
import java.util.Hashtable;
import java.util.Set;

/**
 * Created by Georgi on 8/23/2015.
 */
public class Functions {
    Set<Integer> hashSet1=new HashSet<Integer>(200);
    Set<Integer> hashSet2=new HashSet<Integer>(200);

    public void add(){
        //f1
        int f1=0;
        int k1=100;
        int f2=0;
        int k2=100;
        hashSet1.add(f1);
        while(f1<=100 && f1>=0){
            hashSet1.add(f1);
            f1=2*f1*(k1-1)+3;

        }
        //f2
        hashSet2.add(f2);
        while(f2<=100 && f2 >=0){
            hashSet2.add(f2);
            f2=3*f2*(k2-1)+1;

        }
    }

    public static <E> Set<E> union(Set<E> set1,Set<E> set2){
        Set<E> union=new HashSet<E>();
        union.addAll(set1);
        union.addAll(set2);
        return union;
    }

    public  static  <E> Set<E> intersect(Set<E> set1,Set<E> set2){
        Set<E> intersect=new HashSet<E>();
        intersect.addAll(set1);
        intersect.retainAll(set2);
        return  intersect;
    }

    public void print(){
        System.out.println(union(hashSet1,hashSet2));
        System.out.print(intersect(hashSet1,hashSet2));
    }

    public static void main(String []argv){
        Functions functions=new Functions();
        functions.add();
        functions.print();

    }
}
