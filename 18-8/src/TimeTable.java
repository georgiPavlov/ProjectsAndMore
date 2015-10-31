import java.util.*;

/**
 * Created by Georgi on 8/23/2015.
 */
public class TimeTable {
    String[] arr={ "08:24-08:33","08:20-09:00", "08:32-08:37", "09:00-09:15"};
    String compareToArray="08:22-09:05";



    Comparator<String>  front=new Comparator<String>() {
        @Override
        public int compare(String a, String b) {
            String []arrey1=a.split("[:-]");
            String []arrey2=b.split("[:-]");
            int hour1 = Integer.parseInt(arrey1[0]);
            int minute1 = Integer.parseInt(arrey1[1]);
            int hour2 = Integer.parseInt(arrey2[0]);
            int minute2 = Integer.parseInt(arrey2[1]);

           // if(hour1==hour2 && minute1==minute2){
            //    return 0;
           // }
             if(hour1>hour2){
                return 1;
            }
            else if(hour1<hour2){
                return -1;
            }
            else if(minute1>minute2 && hour1==hour2){
                return 1;
            }
            else if(minute1<minute2 && hour1==hour2){
                return -1;
            }
            return 0;
        }
    };

    Comparator<String>  back=new Comparator<String>() {
        @Override
        public int compare(String a, String b) {
            String []arrey1=a.split("[:-]");
            String []arrey2=b.split("[:-]");

            int hour1 = Integer.parseInt(arrey1[2]);
            int minute1 = Integer.parseInt(arrey1[3]);
            int hour2 = Integer.parseInt(arrey2[2]);
            int minute2 = Integer.parseInt(arrey2[3]);

            //if(hour1==hour2 && minute1==minute2){
               // return 0;
           // }
             if(hour1>hour2){
                return -1;
            }
            else if(hour1<hour2){
                return 1;
            }
            else if(minute1>minute2 && hour1==hour2){
                return -1;
            }
            else if(minute1<minute2 && hour1==hour2){
                return 1;
            }
            return 0;
        }
    };

    TreeSet<String> one=new TreeSet<String>(front);
    TreeSet<String> two=new TreeSet<String>(back);
    TreeSet<String> tree=new TreeSet<String>(front);
    TreeSet<String> four=new TreeSet<String>(back);

    public void add(){
        int trueValue=-1;
        for(int i=0;i<arr.length;i++){
            one.add(arr[i]);
            two.add(arr[i]);

        }
        for(String out:one){
            trueValue=front.compare(out,compareToArray);
           // System.out.println(out);
            if(trueValue != 1){
                tree.add(out);
               // System.out.println(out);
            }
        }
        trueValue=-1;
        for(String out2:two){
            trueValue=back.compare(out2,compareToArray);
            if(trueValue != -1){
                four.add(out2);
                //System.out.println(out2);
            }
        }



        System.out.print(intersect(tree,four));


    }

    public  static  <E> Set<E> intersect(Set<E> set1,Set<E> set2){
        Set<E> intersect=new HashSet<E>();
        intersect.addAll(set1);
        intersect.retainAll(set2);
        return  intersect;
    }

     public static void main(String []argv){
         TimeTable timeTable=new TimeTable();
         timeTable.add();
     }
}


