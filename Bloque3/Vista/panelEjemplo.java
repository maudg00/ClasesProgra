import javax.swing.*;
import java.awt.GridLayout;
public class panelEjemplo extends JPanel{
    public JButton botonInutil;
    public static JSpinner numero1;
    public static JSpinner numero2;
    panelEjemplo()
    {
        super();
        this.botonInutil=new JButton("Si sirvo!");
        this.setLayout(new GridLayout(1,2));
        this.add(botonInutil);
        this.setVisible(true);
        SpinnerModel reglasSpinner=new SpinnerNumberModel(1,0,100,1); // Empieza en 1, de 0 a 100 y se mueve de 1 en 1
        SpinnerModel reglasSpinner2=new SpinnerNumberModel(1,0,100,1);
        panelEjemplo.numero1 = new JSpinner(reglasSpinner);
        panelEjemplo.numero2= new JSpinner(reglasSpinner2);
        this.add(panelEjemplo.numero1);
        this.add(panelEjemplo.numero2);
    }
}
