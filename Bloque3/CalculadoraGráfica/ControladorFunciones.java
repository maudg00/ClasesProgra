import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;

public class ControladorFunciones implements ActionListener{
    
    public void actionPerformed(ActionEvent evento)
    {
        //Obtengo el boton que me mando a llamar
        JButton caller=(JButton)evento.getSource();
        String textoBoton=caller.getText();
        System.out.println("Me llamo el objeto: " + textoBoton);
        switch(textoBoton)
        {
            case "CLS":
                panelResultados.resultArea.setText("0");
            break;
            case "=":
                
            break;
        }
    }


}
