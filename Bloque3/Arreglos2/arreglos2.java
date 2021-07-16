import java.util.Scanner;
public class arreglos2
{
    public static void main(String[] args)
    {
        Scanner leeTerminal= new Scanner(System.in);
        System.out.println("Dime de que tamanio es tu arreglo: ");
        int size=leeTerminal.nextInt();
        int[] arreglo=new int[size];
        for(int i=0; i<size; i++)
        {
            System.out.println("Dime el elemento "+(i+1)+" del arreglo: ");
            arreglo[i]=leeTerminal.nextInt();
        }
        for(int i=0; i<size; i++)
        {
            System.out.println("Arreglo["+(i+1)+"]= "+arreglo[i]);
        }
        leeTerminal.close();
    }
}
