import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;

public class controlador implements ActionListener{
    
    public void actionPerformed(ActionEvent evento)
    {
        //Obtengo el boton que me mando a llamar
        JButton caller=(JButton)evento.getSource();
        String textoBoton=caller.getText();
        System.out.println("Me llamo el objeto: " + textoBoton);
        int num1=(Integer)panelEjemplo.numero1.getValue();
        int num2=(Integer)panelEjemplo.numero2.getValue();
        int resultadoNum;
        String resultadoString;
        switch(textoBoton)
        {
            case "Prueba!":
                resultadoString=modelo.funcionPrueba();
                vista.miResultado.setText(resultadoString);
            break;
            case "Suma":
                resultadoNum=modelo.funcionSuma(num1, num2);
                vista.miResultado.setText(String.valueOf(resultadoNum));
            break;
            case "Resta":
                resultadoNum=modelo.funcionResta(num1, num2);
                vista.miResultado.setText(String.valueOf(resultadoNum));
            break;
            case "Multi":
                resultadoNum=modelo.funcionMulti(num1, num2);
                vista.miResultado.setText(String.valueOf(resultadoNum));
            break;
            case "Si sirvo!":
                resultadoString=modelo.funcionSirvo();
                vista.miResultado.setText(resultadoString);
            break;
        }
    }


}
