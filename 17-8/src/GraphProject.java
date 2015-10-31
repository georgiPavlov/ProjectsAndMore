import java.io.File;
import java.io.FileNotFoundException;


/**
 * Created by Georgi on 8/20/2015.
 */
import java.util.Scanner;

public class GraphProject {

    private static class Node {
        private int number;
        private Node pointer;

        public Node(int number, Node old) {
            this.number = number;
            pointer = old;
        }
    }


    private static class Vertex {
        private String name;
        private Node list;

        public Vertex(String name, Node list) {
            this.name = name;
            this.list = list;
        }
    }


    Vertex[] vertexes;


    public void readFile() {

        Scanner scannerI = null;
        try {
            scannerI = new Scanner(new File("E:\\TU_Georgi\\17-8\\12.txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            System.out.print("job done");
        } finally {

            String graphType = scannerI.next();
            boolean undirected = true;
            if (graphType.equals("directed")) {
                undirected = false;
            }

            vertexes = new Vertex[scannerI.nextInt()];
            for (int i = 0; i < vertexes.length; i++) {
                vertexes[i] = new Vertex(scannerI.next(), null);
            }
            while (scannerI.hasNext()) {
                int name1Number = find(scannerI.next());
                int name2Number = find(scannerI.next());

                vertexes[name1Number].list = new Node(name2Number, vertexes[name1Number].list);
                vertexes[name2Number].list = new Node(name1Number, vertexes[name2Number].list);

            }
        }

    }


    private int find(String nameNode) {
        for (int i = 0; i < vertexes.length; i++) {
            if (vertexes[i].name.equals(nameNode)) {
                return i;
            }
        }
        return -1;
    }

    public void print() {
        System.out.println();
        for (int i = 0; i < vertexes.length; i++) {
            System.out.print(vertexes[i].name);
            for (Node temp = vertexes[i].list; temp != null; temp = temp.pointer) {
                System.out.print(" --> " + vertexes[temp.number].name);
            }
            System.out.println("\n");
        }

    }

    public static void main(String argv[]) {
        GraphProject graphProject = new GraphProject();
        graphProject.readFile();
        graphProject.print();
    }


}
