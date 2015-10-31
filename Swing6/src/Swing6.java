import javax.swing.*;
import java.awt.*;
import  java.awt.event.*;
import java.util.Calendar;
import  java.util.Date;
import javax.swing.SpinnerDateModel;

/**
 * Created by Georgi on 9/8/2015.
 */
public class Swing6 extends JFrame{

    JButton button;
    JSpinner spinner1,spinner2,spinner3,spinner4;

    public static void main(String[] argv){
        new Swing6();
    }

    public Swing6(){
        this.setSize(400, 400);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        this.setTitle("Swing6");
        JPanel panel = new JPanel();

        button= new JButton("ok");
        ListenForButton listenForButton=new ListenForButton();
        button.addActionListener(listenForButton);
        panel.add(button);

        spinner1 = new JSpinner();
        panel.add(spinner1);

        spinner2 = new JSpinner(new SpinnerNumberModel(1,1,100,1));
        panel.add(spinner2);

        String[] weekDays = {"Monday","Tuesday","Wednesday","Friday"};
        spinner3 = new JSpinner(new SpinnerListModel(weekDays));
        Dimension d = spinner3.getPreferredSize();
        d.width = 80;
        spinner3.setPreferredSize(d);
        panel.add(spinner3);

        Date date = new Date();
        spinner4= new JSpinner(new SpinnerDateModel(date,null,null, Calendar.DAY_OF_MONTH));
        JSpinner.DateEditor dateEditor = new JSpinner.DateEditor(spinner4,"dd:MM:yy");
        spinner4.setEditor(dateEditor);
        panel.add(spinner4);

        //ListenFotSpinner listenFotSpinner = new ListenForSpinner();
        //spinner4.addChangeListener(listenFotSpinner);

        this.add(panel);
        this.setVisible(true);




    }

    private class ListenForButton implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            if(e.getSource() == button){
                String one="";
                one+="Operation " + spinner1.getValue() + "\n";
                one+="Operation " + spinner2.getValue() + "\n";
                one+="Operation " + spinner3.getValue() + "\n";
                one+="Operation " + spinner4.getValue() + "\n";


                JOptionPane.showMessageDialog(Swing6.this,one,"one",JOptionPane.INFORMATION_MESSAGE);
                one ="";
            }
        }
    }

}
