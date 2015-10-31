import java.util.Scanner;

/**
 * Created by Georgi on 8/22/2015.
 */
public class HashArray {
    int size;
    HashNodeMake[] arr;
    String[][] words = {
            {"ace", "Very good"},
            {"act", "Take action"},
            {"add", "Join (something) to something else"},
            {"age", "Grow old"},
            {"ago", "Before the present"},
            {"aid", "Help, assist, or support"},
            {"aim", "Point or direct"},
            {"air", "Invisible gaseous substance"},
            {"all", "Used to refer to the whole quantity"},
            {"amp",
                    "Unit of measure for the strength of an electrical current"},
            {"and", "Used to connect words"}, {"ant", "A small insect"},
            {"any", "Used to refer to one or some of a thing"},
            {"ape", "A large primate"},
            {"apt", "Appropriate or suitable in the circumstances"},
            {"arc", "A part of the circumference of a curve"},
            {"are", "Unit of measure, equal to 100 square meters"},
            {"ark", "The ship built by Noah"},
            {"arm", "Two upper limbs of the human body"},
            {"art", "Expression or application of human creative skill"},
            {"ash", "Powdery residue left after the burning"},
            {"ask", "Say something in order to obtain information"},
            {"asp", "Small southern European viper"},
            {"ass", "Hoofed mammal"},
            {"ate", "To put (food) into the mouth and swallow it"},
            {"atm", "Unit of pressure"},
            {"awe", "A feeling of reverential respect"},
            {"axe", "Edge tool with a heavy bladed head"},
            {"aye", "An affirmative answer"}};


    HashArray(int size) {
        this.size = size;
        arr = new HashNodeMake[size];

        for (int i = 0; i < arr.length; i++) {
            arr[i] = new HashNodeMake();
        }

        addArray(words);
    }

    public void addArray(String[][] nodeWords) {
        String wordAdd;
        String defAdd;
        HashNode newNode;

        for (int i = 0; i < nodeWords.length; i++) {

            wordAdd = nodeWords[i][0];
            defAdd = nodeWords[i][1];
            newNode = new HashNode(wordAdd, defAdd);
            insert(newNode);
        }
    }

    public void insert(HashNode newNode) {
        String word = newNode.word;
        int hashCode = code(word);
        arr[hashCode].insert(newNode, hashCode);
    }


    public int code(String word) {
        int result = 0;
        final int PRIME = 31;

        for (int i = 0; i < word.length(); i++) {
            int charCode = word.charAt(i) - 96;
            result = (PRIME * result + charCode) % size;
        }
        return result;
    }

    public HashNode findFirst(String word) {
        int hash = code(word);
        HashNode result = arr[hash].find(word);
        return result;
    }


    public class HashNode {

        public String word;
        public String def;
        int key;
        HashNode NodePointer = null;

        HashNode(String word, String def) {
            this.word = word;
            this.def = def;
        }

        public String toString() {
            return word + " : " + def;
        }
    }

    public class HashNodeMake {

        HashNode head;

        public HashNodeMake() {
            this.head = null;
        }

        public void insert(HashNode newNode, int key) {
            newNode.key = key;
            if (head == null) {
                head = newNode;
            } else {
                newNode.NodePointer = head;
                head = newNode;
            }
        }

        public HashNode find(String word) {
            HashNode temp;
            for (temp = head; head != null; temp = temp.NodePointer) {
                if (temp.word.equals(word)) {
                    return temp;
                }
            }
            return null;
        }


    }

    public static void main(String[] argv) {
        HashArray hashArray = new HashArray(61);
        Scanner in = new Scanner(System.in);
        String word = " ";
        while (!word.equalsIgnoreCase("exit")) {
            System.out.println("enter word to see the defenition: ");
            word = in.nextLine();
            System.out.print(hashArray.findFirst(word));
            System.out.println("\n");
        }


    }
}
