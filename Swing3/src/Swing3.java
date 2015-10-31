import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import  java.awt.event.*;
import java.text.NumberFormat;

public class Swing3 extends JFrame {

    JButton button1;
    JLabel label1,label2,label3;
    JTextField textField1,textField2;
    JCheckBox dollarSign,comaSeparator;
    JRadioButton addNums,substractNums,multNums,devideNums;
    JSlider howmanytimes;
    double number1,number2,total;

    public static void main(String[] argv){
        new Swing3();
    }

    public Swing3(){
        this.setSize(400, 400);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("Swing3");
        JPanel panel = new JPanel();

        button1 = new JButton("Calculate");
        ListenForButton listenForButton = new ListenForButton();
        button1.addActionListener(listenForButton);
        panel.add(button1);

        label1 = new JLabel("number1");
        panel.add(label1);
        textField1 = new JTextField("",5);
        panel.add(textField1);

        label2 = new JLabel("number2");
        panel.add(label2);
        textField2 = new JTextField("",5);
        panel.add(textField2);

        dollarSign = new JCheckBox("dollars");
        comaSeparator = new JCheckBox("comaSeparator");
        panel.add(dollarSign);
        panel.add(comaSeparator,true);

        addNums = new JRadioButton("Add");
        substractNums = new JRadioButton("Substract");
        multNums = new JRadioButton("Mult");
        devideNums = new JRadioButton("Divide");
        ButtonGroup buttonGroup = new ButtonGroup();
        buttonGroup.add(addNums);
        buttonGroup.add(substractNums);
        buttonGroup.add(multNums);
        buttonGroup.add(devideNums);
        JPanel opr = new JPanel();
        Border oprBorder = BorderFactory.createTitledBorder("operation");
        opr.setBorder(oprBorder);
        opr.add(addNums);
        opr.add(substractNums);
        opr.add(multNums);
        opr.add(devideNums);
        addNums.setSelected(true);
        panel.add(opr);

        label3 = new JLabel("Slider times");
        panel.add(label3);
        howmanytimes = new JSlider(0,99,1);
        howmanytimes.setMinorTickSpacing(1);
        howmanytimes.setMinorTickSpacing(10);
        howmanytimes.setPaintTicks(true);
        howmanytimes.setPaintLabels(true);
        ListenForSlider listenForSlider = new ListenForSlider();
        howmanytimes.addChangeListener(listenForSlider);
        panel.add(howmanytimes);
        this.add(panel);
        this.setVisible(true);
        textField1.requestFocus();
    }

    private class ListenForButton implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            if(e.getSource() == button1){
                try{
                    number1 = Double.parseDouble(textField1.getText());
                    number2 = Double.parseDouble(textField2.getText());
                }
                catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(Swing3.this, "Error", "RRRRR", JOptionPane.ERROR_MESSAGE);
                    System.exit(0);
                }
                if(addNums.isSelected()){
                    total=addNumbers(number1,number2,howmanytimes.getValue());
                }
                 else if(multNums.isSelected()){
                    total=multNumbers(number1,number2,howmanytimes.getValue());
                }
                else if(devideNums.isSelected()){
                    total=devideNumbers(number1,number2,howmanytimes.getValue());
                }
                else{
                    total=substractNumbers(number1,number2,howmanytimes.getValue());
                }

                if(dollarSign.isSelected()){
                    NumberFormat numberFormat = NumberFormat.getCurrencyInstance();
                    JOptionPane.showMessageDialog(Swing3.this,numberFormat.format(total),"Solution",JOptionPane.INFORMATION_MESSAGE);

                }
                 else if(comaSeparator.isSelected()){
                    NumberFormat numberFormat = NumberFormat.getNumberInstance();
                    JOptionPane.showMessageDialog(Swing3.this,numberFormat.format(total),"Solution",JOptionPane.INFORMATION_MESSAGE);
                }

                else {
                    JOptionPane.showMessageDialog(Swing3.this,total,"Solution",JOptionPane.INFORMATION_MESSAGE);
                }

            }
        }
    }

    private class ListenForSlider implements ChangeListener{

        @Override
        public void stateChanged(ChangeEvent e) {
            if(e.getSource() == howmanytimes){
                label3.setText("operation " + howmanytimes.getValue());
            }
        }
    }

    public static double addNumbers(double number1, double number2, int howMany){
        double totalValue=0;
         int i=1;
        while (i <= howMany){
            totalValue = totalValue + (number1 + number2);
            i++;
        }
        return  totalValue;
    }

    public static double substractNumbers(double number1, double number2, int howMany){
        double totalValue=0;
        int i=1;
        while (i <= howMany){
            totalValue = totalValue + (number1 - number2);
            i++;
        }
        return  totalValue;
    }

    public static double devideNumbers(double number1, double number2, int howMany){
        double totalValue=0;
        int i=1;
        while (i <= howMany){
            totalValue = totalValue + (number1 / number2);
            i++;
        }
        return  totalValue;
    }

    public static double multNumbers(double number1, double number2, int howMany){
        double totalValue=0;
        int i=1;
        while (i <= howMany){
            totalValue = totalValue + (number1 * number2);
            i++;
        }
        return  totalValue;
    }





}
