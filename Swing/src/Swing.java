/**
 * Created by Georgi on 9/6/2015.
 */
import  java.awt.Dimension;
import java.awt.Toolkit;
import javax.swing.*;

public class Swing extends JFrame {

    public static void main(String[] argv){
     new Swing();
    }

    public Swing(){

        this.setSize(300, 300);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("This is frame :: Java the best");
        JPanel thePanel = new JPanel();
        JLabel jLabel = new JLabel("tell me something");
        jLabel.setToolTipText("GO GO GO");
        thePanel.add(jLabel);
        this.add(thePanel);

        JButton button=new JButton("OK");
        thePanel.add(button);
        JTextField jTextField = new JTextField("Typw hwew" , 10);
        JTextField.getKeymap("key map");
        thePanel.add(jTextField);
        jTextField.setColumns(50);
        JTextArea jTextArea = new JTextArea(10,15);
        jTextArea.setLineWrap(false);
        thePanel.add(jTextArea);

        JScrollPane jScrollPane= new JScrollPane(jTextArea,JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        thePanel.add(jScrollPane);
        jTextField.requestFocus();

        this.setVisible(true);







    }


}
