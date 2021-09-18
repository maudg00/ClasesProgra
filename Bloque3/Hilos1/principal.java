public class principal
{
    public static void main(String[] args)
    {
        hilo1 miPrimerHilo= new hilo1("PrimerHilo");
        hilo2 miSegundoHilo= new hilo2("SegundoHilo");
        miPrimerHilo.start();
        miSegundoHilo.start();
        miPrimerHilo.finish(); // miPrimerHilo.join();
        miSegundoHilo.finish(); // miSegundoHilo.join();
        System.out.println("Acabe");
    }
    
}
