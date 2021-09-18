import javax.swing.JPanel;

import javax.swing.*;
import java.awt.GridLayout;
public class panelNumeros extends JPanel{
    public JButton []numeros;
    panelNumeros(ControladorNumeros miControlador)
    {
        super();
        numeros=new JButton[10];
        this.setLayout(new GridLayout(4,3));
        for(int i=0; i<=9; i++)
        {
            numeros[i]=new JButton(String.valueOf(i));
            this.add(numeros[i]);
            numeros[i].addActionListener(miControlador);
        }
        this.setVisible(true);
    }
}
