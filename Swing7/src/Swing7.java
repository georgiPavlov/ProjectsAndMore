/**
 * Created by Georgi on 9/8/2015.
 */

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import  java.util.Enumeration;
import  javax.swing.tree.*;

public class Swing7 extends JFrame{

    JButton button;
    String output="";
    JTree theTree;
    DefaultMutableTreeNode documents,work,games,emails;
    DefaultMutableTreeNode fileSystem = new DefaultMutableTreeNode("C drive");


    public static void main(String[] argv){
        new Swing7();
    }

    public Swing7(){
        this.setSize(400, 400);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        this.setTitle("Swing7::Tree");
        JPanel panel = new JPanel();
        button= new JButton("ok");
        ListenForButton listenForButton=new ListenForButton();
        button.addActionListener(listenForButton);
        panel.add(button);
        theTree = new JTree(fileSystem);
        theTree.getSelectionModel().setSelectionMode(TreeSelectionModel.SINGLE_TREE_SELECTION);
        theTree.setVisibleRowCount(2);
        documents = addFile("Docs",fileSystem);
        addFile("taxes.txt",documents);
        addFile("taxes.txt",documents);
        addFile("taxes.txt", documents);
        addFile("taxes.txt", documents);
        //panel.add(theTree);
        JScrollPane scrollPane = new JScrollPane(theTree);
        Dimension d = scrollPane.getPreferredSize();
        d.width=200;
        scrollPane.setPreferredSize(d);
        panel.add(scrollPane);
        this.add(panel);
        this.setVisible(true);
    }

    private class ListenForButton implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            if(e.getSource() == button){
                Object treeObject = theTree.getLastSelectedPathComponent();
                DefaultMutableTreeNode theFile= (DefaultMutableTreeNode) treeObject;
                String theNode=(String) theFile.getUserObject();
                output+="tHE SELECTED " + theNode + "\n";
                output+="Child " + theFile.getChildCount()+ "\n";
                output+="Sublig " + theFile.getSiblingCount()+ "\n";
                output+="Parent " + theFile.getParent()+ "\n";

                for(Enumeration enumValue = theFile.children();enumValue.hasMoreElements();){
                    output+="\n " + enumValue.nextElement()+ " \n";
                }

                TreeNode[] pathNodes = theFile.getPath();
                for(TreeNode in : pathNodes){
                    output+="\n Path " + in + "\n";
                }

                JOptionPane.showMessageDialog(Swing7.this,output,"one",JOptionPane.INFORMATION_MESSAGE);
                output="";
            }
        }
    }

    private DefaultMutableTreeNode addFile(String filename,DefaultMutableTreeNode parentNode){
        DefaultMutableTreeNode newFile = new DefaultMutableTreeNode(filename);
        parentNode.add(newFile);
        return newFile;
    }
}
