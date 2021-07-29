import java.util.Dictionary;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;
public class Principal {
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        HashMap<Integer,String> myMap=new HashMap<Integer,String>();//Creating HashMap
        agregaAHash("Fran", myMap);
        agregaAHash("Tania", myMap);
        System.out.println("Dame un nombre: ");
        String nombre=sc.next();
        agregaAHash(nombre, myMap);
        System.out.println("Dame un nombre: ");
        nombre=sc.next();
        agregaAHash(nombre, myMap);
        for(Map.Entry m : myMap.entrySet())
        {    
            System.out.println(String.format("0x%08X", m.getKey())+" "+m.getValue());    
        }  
        sc.close();
    }
    public static void agregaAHash(String nombre, HashMap<Integer, String> myMap)
    {
        boolean hayColision=false;
        String nombreCopia=nombre;
        do
        {
            hayColision=false;
            int key=generateHash(nombreCopia);
            if(myMap.containsKey(key)==true)
            {
                char primerCaracter=nombreCopia.charAt(0);
                primerCaracter+=1;
                char[] stringCopia=nombreCopia.toCharArray();
                stringCopia[0]=primerCaracter; 
                String nombreCambiado=new String(stringCopia); 
                nombreCopia=nombreCambiado;
                System.out.println("Hay colision.");
                hayColision=true;
            }
            else
            {
                myMap.put(key, nombre);
            }
        }
        while(hayColision==true);
    }
    public static int generateHash(String nombre)
    {
        int finalHash=nombre.hashCode();
        return finalHash;
    }
}
