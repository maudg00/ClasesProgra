import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;

public class ControladorOperadores implements ActionListener{
    
    public void actionPerformed(ActionEvent evento)
    {
        //Obtengo el boton que me mando a llamar
        JButton caller=(JButton)evento.getSource();
        String textoBoton=caller.getText();
        System.out.println("Me llamo el objeto: " + textoBoton);
        String textoResult=panelResultados.resultArea.getText();
        panelResultados.resultArea.setText(textoResult+textoBoton);
    }


}
