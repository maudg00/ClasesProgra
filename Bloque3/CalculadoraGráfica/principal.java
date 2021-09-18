public class principal
{
    public static void main(String[] args)
    {
        ControladorNumeros miControladorNumeros=new ControladorNumeros();
        ControladorOperadores miControladorOperadores=new ControladorOperadores();
        ControladorFunciones miControladorFunciones=new ControladorFunciones();
        panelResultados miPanelResultados= new panelResultados();
        panelNumeros miPanelNumeros= new panelNumeros(miControladorNumeros);
        panelOperadores miPanelOperadores=new panelOperadores(miControladorOperadores);
        panelFunciones miPanelFunciones= new panelFunciones(miControladorFunciones);
        vista mainView=new vista(miPanelResultados, miPanelNumeros, miPanelOperadores, miPanelFunciones);
        mainView.setVisible(true);
    }
    
}
