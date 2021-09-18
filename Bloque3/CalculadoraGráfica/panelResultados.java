import javax.swing.*;
import java.awt.GridLayout;
public class panelResultados extends JPanel{
    public static JTextArea resultArea;
    panelResultados()
    {
        super();
        this.setLayout(new GridLayout(1,1));
        resultArea=new JTextArea();
        resultArea.setText("0");
        this.add(resultArea);
        this.setVisible(true);
    }
}
