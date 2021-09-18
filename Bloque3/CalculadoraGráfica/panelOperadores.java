import javax.swing.*;
import java.awt.GridLayout;
public class panelOperadores extends JPanel{
    public JButton botonMas;
    public JButton botonMenos;
    public JButton botonPor;
    public JButton botonEntre;
    panelOperadores(ControladorOperadores miControlador)
    {
        super();
        this.setLayout(new GridLayout(1,4));
        botonMas=new JButton("+");
        botonMas.addActionListener(miControlador);
        botonMenos=new JButton("-");
        botonMenos.addActionListener(miControlador);
        botonPor=new JButton("x");
        botonPor.addActionListener(miControlador);
        botonEntre=new JButton("/");
        botonEntre.addActionListener(miControlador);
        this.add(botonMas);
        this.add(botonMenos);
        this.add(botonPor);
        this.add(botonEntre);
        this.setVisible(true);
    }
}