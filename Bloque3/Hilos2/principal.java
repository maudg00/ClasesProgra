import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.Semaphore;

public class principal
{
    public static void main(String[] args)
    {
        compartidas.mutexLock=new Semaphore(1);
        Scanner miScan=new Scanner(System.in);
        int numHilos;
        System.out.println("Dime cuantos hilos quieres: ");
        numHilos=miScan.nextInt();
        compartidas.numeros=new ArrayList<Integer>();
        hilo[] miHilos=new hilo[numHilos];
        for(int i=0; i<numHilos; i++)
        {
            miHilos[i]=new hilo("Hilo "+i);
            miHilos[i].start();
        }
        for(int i=0; i<numHilos; i++)
        {
            miHilos[i].finish();
        }
        System.out.println("Terminé :D");
        miScan.close();
    }
}