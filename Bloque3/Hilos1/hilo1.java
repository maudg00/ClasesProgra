public class hilo1 implements Runnable{
    public String nombreHilo;
    Thread miHilo;
    hilo1(String nombreHilo)
    {
        this.nombreHilo=nombreHilo;
    }
    public void run()
    {
        System.out.println("Hola Mundo"+" me llama el hilo " + this.nombreHilo);
        try {
            Thread.sleep(3000);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        System.out.println("Desperté "+" me llama el hilo " + this.nombreHilo);
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
