public class hilo2 implements Runnable{
    public String nombreHilo;
    Thread miHilo;
    hilo2(String nombreHilo)
    {
        this.nombreHilo=nombreHilo;
    }
    public void run()
    {
        System.out.println("Adios Mundo "+"me llama el hilo "+this.nombreHilo);
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