import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JPanel;

public class controlador implements ActionListener{
    
    public void actionPerformed(ActionEvent evento)
    {
        //Obtengo el boton que me mando a llamar
        JButton caller=(JButton)evento.getSource();
        String textoBoton=caller.getText();
        System.out.println("Me llamo el objeto: " + textoBoton);
        switch(textoBoton)
        {
            case "Prueba!":
                modelo.funcionPrueba();
            break;
            case "Suma":
                modelo.funcionSuma();
            break;
            case "Resta":
                modelo.funcionResta();
            break;
            case "Multi":
                modelo.funcionMulti();
            break;
        }
    }


}
