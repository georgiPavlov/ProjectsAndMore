import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by Georgi on 9/7/2015.
 */
public class Swing4 extends JFrame {

    JComboBox favoriteShows;
    JButton button2;
    String information="";

    public static void main(String[] argv){
     new Swing4();
    }
    public Swing4(){
        this.setSize(400, 400);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        this.setTitle("Swing4");
        JPanel panel = new JPanel();
        String[] shows={"Breaking bad","Arrow"};
        favoriteShows = new JComboBox(shows);
        panel.add(favoriteShows);
        button2 = new JButton("ok");
        ListenForButtons listenForButtons = new ListenForButtons();
        button2.addActionListener(listenForButtons);
        panel.add(button2);
        this.add(panel);
        this.setVisible(true);
    }

    private class ListenForButtons implements ActionListener{


        @Override
        public void actionPerformed(ActionEvent e) {
            if(e.getSource() == button2){
                favoriteShows.setEditable(true);
                information+="Item at 0" + favoriteShows.getItemAt(0) + "\n";
                information+="Selected ID" + favoriteShows.getSelectedItem() + "\n";
                information+="Are Editable" + favoriteShows.isEditable() + "\n";
                JOptionPane.showMessageDialog(Swing4.this,information,"Information",JOptionPane.INFORMATION_MESSAGE );
                information="";

            }
        }
    }
}
