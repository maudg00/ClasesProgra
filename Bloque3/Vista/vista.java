import javax.swing.*;
import java.awt.Dimension;
import java.awt.GridLayout;
public class vista
{
    public JFrame miFrame;
    public JButton miBoton;
    public JButton miBoton2;
    public JButton miBoton3;
    public JButton miBoton4;
    public static JTextArea miResultado;
    vista()
    {
        //Instancio mi controlador/mi "listener" y el layout que deseo.
        controlador miControlador=new controlador();
        GridLayout miLayout=new GridLayout(3,2);
        //Instancio mi Frame y le digo su layout.
        this.miFrame= new JFrame();
        this.miFrame.setLayout(miLayout);
        this.miFrame.setResizable(true);
        //Instancio mis botones y les pongo su texto.
        this.miBoton=new JButton("Prueba!");
        this.miBoton2=new JButton("Suma");
        this.miBoton3=new JButton("Resta");
        this.miBoton4=new JButton("Multi");
        vista.miResultado=new JTextArea();
        //Ligo botones a controlador.
        this.miBoton.addActionListener(miControlador);
        this.miBoton2.addActionListener(miControlador);
        this.miBoton3.addActionListener(miControlador);
        this.miBoton4.addActionListener(miControlador);
        //Agrego botones a frame.
        this.miFrame.add(miBoton);
        this.miFrame.add(miBoton2);
        this.miFrame.add(miBoton3);
        this.miFrame.add(miBoton4);
        //Agrego el panel y el textArea
        panelEjemplo miPanel= new panelEjemplo();
        miPanel.botonInutil.addActionListener(miControlador);
        this.miFrame.add(miPanel);
        this.miFrame.add(vista.miResultado);
        vista.miResultado.setText("Aqui estara el resultado");
        //Que se vea
        this.miFrame.setVisible(true);
    }
}
