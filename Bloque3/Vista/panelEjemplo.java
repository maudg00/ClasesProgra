import javax.swing.*;
import java.awt.GridLayout;
public class panelEjemplo extends JPanel{
    public JButton botonInutil;
    panelEjemplo()
    {
        super();
        this.botonInutil=new JButton("Si sirvo!");
        this.setLayout(new GridLayout(1,1));
        this.add(botonInutil);
        this.setVisible(true);
    }
}
