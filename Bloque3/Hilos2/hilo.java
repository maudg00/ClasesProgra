import java.util.Random;

public class hilo implements Runnable{
    Thread miHilo;
    String nombreHilo;
    hilo(String nombreHil)
    {
        this.nombreHilo=nombreHil;
    }
    public void run()
    {
        Random RNG= new Random();
        int miNum=RNG.nextInt(100);
        System.out.println("Me llama el hilo "+nombreHilo + " con el id "+this.id());
        // INICIO SECCIÓN CRÍTICA
        try {
            compartidas.mutexLock.acquire();
            compartidas.numeros.add(miNum);
            System.out.println(compartidas.numeros);
            compartidas.mutexLock.release();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        // FIN SECCIÓN CRÍTICA
    }
    public void start()
    {
        try {
            miHilo= new Thread(this);
            miHilo.start();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
    public Long id()
    {
        return miHilo.getId();
    }
    public void finish()
    {
        try
        {
            miHilo.join();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        
    }
}