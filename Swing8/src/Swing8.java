/**
 * Created by Georgi on 9/9/2015.
 */
import javax.swing.*;
import java.awt.Dimension;
import  java.awt.BorderLayout;
import java.awt.FlowLayout;

public class Swing8 extends JFrame{

   JButton button1, button2, button3, button4, button5;

    public static void main(String[] argv){
        new Swing8();
    }
    public Swing8(){
        this.setSize(300, 300);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        this.setTitle("Swing8::Java");
        button1= new JButton("ok1");
        button2= new JButton("ok2");
        Box box = Box.createHorizontalBox();
        box.add(button1);
        box.add(Box.createRigidArea(new Dimension(70,500)));
        box.add(button2);

        this.add(box);

       /*
       Flow
       JPanel panel = new JPanel();
        panel.setLayout(new FlowLayout(FlowLayout.RIGHT,30,20));
        button1= new JButton("ok1");
        button2= new JButton("ok2");
        panel.add(button1);
        panel.add(button2);

        Border
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());
        button1= new JButton("ok1");
        button2= new JButton("ok2");*/


        this.setVisible(true);


    }
}
