import javax.swing.*;
import java.awt.GridLayout;
public class vista extends JFrame{
    vista(panelResultados miPanelResultados, panelNumeros miPanelNumeros, panelOperadores miPanelOperadores, panelFunciones miPanelFunciones)
    {
        super();
        this.setLayout(new GridLayout(4,1));
        this.add(miPanelResultados);
        this.add(miPanelNumeros);
        this.add(miPanelOperadores);
        this.add(miPanelFunciones);
        this.setVisible(true);
        this.pack();
    }
}
