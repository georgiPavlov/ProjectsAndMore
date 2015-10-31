import javax.swing.*;
import java.awt.*;

/**
 * Created by Georgi on 9/9/2015.
 */
public class Swing9 extends JFrame{

    JButton button1,button2,button3,button4,button5,button6,button7,
    button8,button9,button0,buttonPlus,buttonMinus,clearAll;
    JTextField textResut;

    public static void main(String[] argv){
        new Swing9();
    }
    public Swing9(){
        this.setSize(300, 400);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        this.setTitle("Swing9::Java");

        JPanel panel = new JPanel();
        panel.setLayout(new GridBagLayout());
        GridBagConstraints gridBagConstraints = new GridBagConstraints();
        gridBagConstraints.gridx = 1;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.gridwidth = 1;
        gridBagConstraints.gridheight = 1;
        gridBagConstraints.weightx = 50;
        gridBagConstraints.weighty = 100;
        gridBagConstraints.insets = new Insets(5,5,5,5);
        gridBagConstraints.anchor = GridBagConstraints.CENTER;
        gridBagConstraints.fill= GridBagConstraints.BOTH;

        textResut = new JTextField("0", 20);
        Font font = new Font("Helvetica", Font.PLAIN,18);
        textResut.setFont(font);



        button1 = new JButton("1");
        button2 = new JButton("2");
        button3 = new JButton("3");
        button4 = new JButton("4");
        button5 = new JButton("5");
        button6 = new JButton("6");
        button7 = new JButton("7");
        button8 = new JButton("8");
        button9 = new JButton("9");
        button0 = new JButton("0");
        buttonPlus = new JButton("Plus");
        buttonMinus = new JButton("Minus");
        clearAll = new JButton("Clear");

        panel.add(clearAll,gridBagConstraints);
        gridBagConstraints.gridwidth= 20;
        gridBagConstraints.gridx = 5;
        panel.add(textResut,gridBagConstraints);
        gridBagConstraints.gridwidth= 1;
        gridBagConstraints.gridx = 1;
        gridBagConstraints.gridy = 2;
        panel.add(button1,gridBagConstraints);
        gridBagConstraints.gridx = 5;
        panel.add(button2,gridBagConstraints);
        gridBagConstraints.gridx = 9;
        panel.add(button3,gridBagConstraints);
        gridBagConstraints.gridx = 1;
        gridBagConstraints.gridy= 3;
        panel.add(button4,gridBagConstraints);
        gridBagConstraints.gridx = 5;
        panel.add(button5,gridBagConstraints);
        gridBagConstraints.gridx = 9;
        panel.add(button6,gridBagConstraints);
        gridBagConstraints.gridx = 1;
        gridBagConstraints.gridy = 4;
        panel.add(button7,gridBagConstraints);
        gridBagConstraints.gridx = 5;
        panel.add(button8,gridBagConstraints);
        gridBagConstraints.gridx = 9;
        panel.add(button9,gridBagConstraints);
        gridBagConstraints.gridx = 1;
        gridBagConstraints.gridy = 5;
        panel.add(button0,gridBagConstraints);
        gridBagConstraints.gridx = 5;
        panel.add(buttonPlus,gridBagConstraints);
        gridBagConstraints.gridx = 9;
        panel.add(buttonMinus,gridBagConstraints);




        this.add(panel);
        this.setVisible(true);






    }
}
