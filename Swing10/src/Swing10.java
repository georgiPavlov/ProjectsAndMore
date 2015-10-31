import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.*;
import java.util.Calendar;
import java.util.Date;

/**
 * Created by Georgi on 9/9/2015.
 */

public class Swing10 extends JFrame {
    JLabel nameLabel,streetlabel,stateLabel,dateLabel,ageLabel;
    JTextField nameText,streetText;
    JComboBox stateList;
    JSpinner dateSpin;
    JSlider ageSlider;
    JRadioButton maleRadio,femaleRadio;
    ButtonGroup sexGroup;
    JTextArea aboutYou;

    public static void main(String[] argv){
      new Swing10();
    }

    public Swing10(){
        //this.setSize(400, 400);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        this.setResizable(false);
        this.setTitle("Swing10::Java");
        JPanel thePanel = new JPanel();

        thePanel.setLayout(new GridBagLayout());
        nameLabel = new JLabel("Name:");
        addComp(thePanel,nameLabel,0,0,1,1,GridBagConstraints.EAST,GridBagConstraints.NONE);

        nameText = new JTextField(30);
        addComp(thePanel,nameText,1,0,2,1,GridBagConstraints.WEST,GridBagConstraints.NONE);

        streetlabel = new JLabel("Street:");
        addComp(thePanel,streetlabel,0,1,1,1,GridBagConstraints.EAST,GridBagConstraints.NONE);

        streetText = new JTextField(30);
        addComp(thePanel,streetText,1,1,1,1,GridBagConstraints.EAST,GridBagConstraints.NONE);

        Box sexBox = Box.createVerticalBox();
        maleRadio = new JRadioButton("Male");
        femaleRadio = new JRadioButton("Female ");
        sexGroup = new ButtonGroup();
        sexGroup.add(maleRadio);
        sexGroup.add(femaleRadio);
        sexBox.add(maleRadio);
        sexBox.add(femaleRadio);
        sexBox.setBorder(BorderFactory.createTitledBorder("Sex"));
        addComp(thePanel, sexBox, 3, 0, 2, 1, GridBagConstraints.CENTER, GridBagConstraints.NONE);

        JPanel statePnel = new JPanel();
        statePnel.setLayout(new FlowLayout(FlowLayout.LEFT,10,0));
        stateLabel = new JLabel("State");
        statePnel.add(stateLabel);
        String[] states = {"Pa","NY","OH","WV"};
        stateList = new JComboBox(states);
        statePnel.add(stateList);
        dateLabel= new JLabel("Time");
        statePnel.add(dateLabel);
        Date date= new Date();
        dateSpin = new JSpinner(new SpinnerDateModel(date,null,null, Calendar.DAY_OF_MONTH));
        JSpinner.DateEditor dateEditor= new JSpinner.DateEditor(dateSpin,"dd:MM:yy");
        dateSpin.setEditor(dateEditor);
        statePnel.add(dateSpin);
        ageLabel = new JLabel("Age 50");
        statePnel.add(ageLabel);
        ageSlider = new JSlider(1,99,50);
        ListenForSlider listenForSlider = new ListenForSlider();
        ageSlider.addChangeListener(listenForSlider);
        statePnel.add(ageSlider);
        addComp(thePanel, statePnel, 1, 2, 5, 1, GridBagConstraints.EAST, GridBagConstraints.NONE);

        JCheckBox morningCheck, afterNCheck,eveningCheck;
        Box optionBox = Box.createVerticalBox();
        morningCheck = new JCheckBox("Morning");
        afterNCheck = new JCheckBox("Afternoon");
        eveningCheck= new JCheckBox("Evenig");
        optionBox.add(morningCheck);
        optionBox.add(afterNCheck);
        optionBox.add(eveningCheck);
        optionBox.setBorder(BorderFactory.createTitledBorder("Time of day"));
        addComp(thePanel, optionBox, 1, 3, 2, 1, GridBagConstraints.NORTHWEST, GridBagConstraints.NONE);

        aboutYou = new JTextArea(6,40);
        aboutYou.setLineWrap(true);
        aboutYou.setWrapStyleWord(true);
        JScrollPane scrollPane =new JScrollPane(aboutYou,JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        addComp(thePanel, scrollPane, 2, 3, 3, 1, GridBagConstraints.EAST, GridBagConstraints.NONE);

        this.add(thePanel);
        this.pack();
        this.setVisible(true);


    }

    private class  ListenForSlider implements ChangeListener{

        @Override
        public void stateChanged(ChangeEvent e) {
            if(e.getSource() == ageSlider){
                ageLabel.setText("Age: " + ageSlider.getValue());
            }
        }
    }

    private void addComp(JPanel thePanel,JComponent comp, int xPos,int yPos, int compWidth, int compHeight, int plase ,int stech ){
        GridBagConstraints gridBagConstraints = new GridBagConstraints();
        gridBagConstraints.gridx = xPos;
        gridBagConstraints.gridy = yPos;
        gridBagConstraints.gridwidth = compWidth;
        gridBagConstraints.gridheight = compHeight;
        gridBagConstraints.weightx = 100;
        gridBagConstraints.weighty = 100;
        gridBagConstraints.insets = new Insets(5,5,5,5);
        gridBagConstraints.anchor = plase;
        gridBagConstraints.fill= stech;
        thePanel.add(comp,gridBagConstraints);
    }
}
