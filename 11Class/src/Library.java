/**
 * Created by Georgi on 8/9/2015.
 */
import java.util.ArrayList;
public class Library {
    private String name;
    private   ArrayList<Book> arrayLibrary = new ArrayList<>();

    public Library(String name)
    {
        this.name=name;
        arrayLibrary.add(new Book("one", "two", "tree",1993,123));
        arrayLibrary.add(new Book("one", "two", "tree",1993,123));
        arrayLibrary.add(new Book("one", "two", "tree",1993,123));
        arrayLibrary.add(new Book("one", "two", "tree",1993,123));
        arrayLibrary.add(new Book("one", "two", "tree",1993,123));


    }

    public String getName() {
        return name;
    }

    public  void compare(){
         String a="tree";
        String test;
        for(int i=0;i<arrayLibrary.size();i++){
            test=arrayLibrary.get(i).getMaker();
            if (a.compareToIgnoreCase(test)==0d){
                System.out.println("number " + i);
                //arrayLibrary.remove(i);




            }
            else{
                System.out.print("Something got wrong");
                break;
            }
        }

    }

}
