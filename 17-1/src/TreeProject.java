import java.util.ArrayList;

/**
 * Created by Georgi on 8/19/2015.
 */
public class TreeProject {

    private static class TreeNode{
       private  int number;
       private ArrayList<TreeNode> children;
       private boolean hasParent;

       public TreeNode(int number){
           this.number=number;
           children=new ArrayList<TreeNode>();
       }

        public int getNumber() {
            return number;
        }

        public void setNumber(int number) {
            this.number = number;
        }

        public void addChildren(TreeNode child){
            child.hasParent=true;
            children.add(child);
        }

        public TreeNode getChildren(int index) {
            return this.children.get(index);
        }

        public int getChildrenCount(){
            return  this.children.size();
        }
    }

    private TreeNode root;

    public TreeProject(int number){
         this.root=new TreeNode(number);
    }

    public TreeProject(int number,TreeProject ...children){
        this(number);

        for(TreeProject child : children){
            this.root.addChildren(child.root);
        }
    }

    public TreeNode getRoot() {
        return this.root;
    }

    public ArrayList<TreeNode> getChildNodes(){
        if(this.root != null){
            return  this.root.children;
        }
        return new ArrayList<TreeNode>();
    }

    public int DFS(TreeNode root,int numberNode){
        int count=0;

        if(this.root == null){
            return count;
        }
        TreeNode temp=null;
        for(int i=0;i<root.getChildrenCount();i++){
            temp=root.getChildren(i);
            count=DFS(temp,numberNode);
           if(numberNode == temp.number){ count++;}
            if(!root.hasParent){
                if(numberNode == root.number){ count++;}
            }
        }
        return count;
    }
     private int leaf=0,peak=1;
    public void DFS2(TreeNode root){



        if(this.root == null){
            leaf++;

            return ;
        }
        TreeNode temp=null;
        TreeNode temp2=null;


        for(int i=0;i<root.getChildrenCount();i++){
            temp=root.getChildren(i);
            if(temp.getChildrenCount() != 0){ peak++;}
            else {leaf++;}

            DFS2(temp);
        }

    }

    public void DFS3(TreeNode root){



        if(this.root == null){
            leaf++;

            return ;
        }
        TreeNode temp=null;
        TreeNode temp2=null;


        for(int i=0;i<root.getChildrenCount();i++){
            temp=root.getChildren(i);
            if(temp.getChildrenCount() != 0){

                for(int j=0;j<temp.getChildrenCount();j++)
                temp2=temp.getChildren(j) ;
                if(temp2.getChildrenCount()==0){

                    System.out.println(root.getChildren(i).number);
                }

            }


            DFS3(temp);
        }

    }

    public void DFSmain(){
      DFS3(this.root);
       // return cout;
    }

    public static void main(String []argv){
        int nodeCount=0;
        TreeProject one=new TreeProject(10,new TreeProject(10,new TreeProject(1,new TreeProject(11)),new TreeProject(9,new TreeProject(13))));
        one.DFSmain();
       // System.out.print(one.peak + " " + one.leaf);
    }
}
