import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Swing5 extends JFrame{
   JButton button1;
    String information="";
    JList favouriteMovies,favouriteColors;
    DefaultListModel defaultListModel = new DefaultListModel();
    JScrollPane scrollPane;

    public static void main(String[] argv){
        new Swing5();
    }

    public Swing5(){
        this.setSize(400, 400);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        this.setTitle("Swing5");
        JPanel panel = new JPanel();

        button1 = new JButton("ok");
        ListenForButton listenForButton = new ListenForButton();
        button1.addActionListener(listenForButton);
        panel.add(button1);

        String[] movies = {"matrix","assassinCreed","Batman","TheDarkKnight"};
        favouriteMovies = new JList(movies);
        favouriteMovies.setFixedCellHeight(30);
        favouriteMovies.setFixedCellWidth(150);
        favouriteMovies.setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);

        String[] colors = {"Black","Pink","Orange","ko be","The new color"};
        for(String color : colors){
            defaultListModel.addElement(color);
        }

        defaultListModel.add(2,"One");
        favouriteColors = new JList(defaultListModel);
        favouriteColors.setVisibleRowCount(2);
        scrollPane = new JScrollPane(favouriteColors,JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        favouriteColors.setFixedCellHeight(30);
        favouriteColors.setFixedCellWidth(150);

        panel.add(favouriteMovies);

        //panel.add(favouriteColors);
        panel.add(scrollPane);
        this.add(panel);
        this.setVisible(true);
    }

    private class ListenForButton implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            if(e.getSource() == button1){
                if(defaultListModel.contains("Black")){
                    information+="Black is here \n";
                }
                JOptionPane.showMessageDialog(Swing5.this,information,"Start",JOptionPane.INFORMATION_MESSAGE);

            }
        }
    }
}
