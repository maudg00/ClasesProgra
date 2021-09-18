import javax.swing.*;
import java.awt.GridLayout;
public class panelFunciones extends JPanel{
    public JButton botonClear;
    public JButton botonIgual;
    panelFunciones(ControladorFunciones miControlador)
    {
        super();
        this.setLayout(new GridLayout(1,2));
        botonClear=new JButton("CLS");
        botonClear.addActionListener(miControlador);
        botonIgual=new JButton("=");
        botonIgual.addActionListener(miControlador);
        this.add(botonClear);
        this.add(botonIgual);
        this.setVisible(true);
    }
}
