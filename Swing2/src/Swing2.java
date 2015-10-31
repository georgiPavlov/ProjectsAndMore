/**
 * Created by Georgi on 9/6/2015.
 */
import javax.swing.*;
import  java.awt.event.*;
import  java.awt.Dimension;
public class Swing2 extends JFrame {

    JButton button1;
    JTextField textField1;
    JTextArea textArea1;
    int buttonClicked;

    public static void main(String[] argv){
         new Swing2();
    }

    public Swing2(){
        this.setSize(300, 420);
        //this.setVisible(true);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("Swing 2");
        JPanel panel = new JPanel();

        button1=new JButton("ok");
        panel.add(button1);
        ListenForButton listenForButton=new ListenForButton();
        button1.addActionListener(listenForButton);


        textField1 = new JTextField("Type here",12);
        ListenForKeys listenForKeys =new ListenForKeys();
        textField1.addKeyListener(listenForKeys);
        panel.add(textField1);

        textArea1=new JTextArea(20,20);
        panel.add(textArea1);
        textArea1.setLineWrap(true);
        textArea1.setText("");
        textArea1.setWrapStyleWord(true);

        JScrollPane jScrollPane = new JScrollPane(textArea1,JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        panel.add(jScrollPane);

        ListenForWindow listenForWindow = new ListenForWindow();
        this.addWindowListener(listenForWindow);

        ListenForMouse listenForMouse = new ListenForMouse();
        panel.addMouseListener(listenForMouse);

        this.add(panel);
        this.setVisible(true);
    }

    private class ListenForButton implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
         if(e.getSource() == button1){
             buttonClicked++;
             textArea1.append("button clicked: " + buttonClicked + "\n");
             e.getSource().toString();
         }
        }
    }

    private  class ListenForKeys implements  KeyListener{

        @Override
        public void keyTyped(KeyEvent e) {
            textArea1.append("Key Hit: " + e.getKeyChar() + "\n");
        }

        @Override
        public void keyPressed(KeyEvent e) {

        }

        @Override
        public void keyReleased(KeyEvent e) {

        }
    }

    private  class ListenForWindow implements WindowListener{

        @Override
        public void windowOpened(WindowEvent e) {
            textArea1.append("Window open \n");
        }

        @Override
        public void windowClosing(WindowEvent e) {

        }

        @Override
        public void windowClosed(WindowEvent e) {

        }

        @Override
        public void windowIconified(WindowEvent e) {

        }

        @Override
        public void windowDeiconified(WindowEvent e) {

        }

        @Override
        public void windowActivated(WindowEvent e) {
            textArea1.append("Window open \n");
        }

        @Override
        public void windowDeactivated(WindowEvent e) {

        }
    }

     private class ListenForMouse implements MouseListener {

        @Override
        public void mouseClicked(MouseEvent e) {
            textArea1.append("Mouse: " + e.getX() + " " + e.getY() + "\n");
            textArea1.append("Mouse: " + e.getClickCount() + "\n");
        }

        @Override
        public void mousePressed(MouseEvent e) {

        }

        @Override
        public void mouseReleased(MouseEvent e) {

        }

        @Override
        public void mouseEntered(MouseEvent e) {

        }

        @Override
        public void mouseExited(MouseEvent e) {

        }
    }

}
