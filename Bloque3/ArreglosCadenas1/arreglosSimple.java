public class arreglosSimple
{
    public static void main(String[] args)
    {
        char[] arreglo={'a','n','a'};
        System.out.println(arreglo[1]);
        System.out.println(arreglo[0]+arreglo[1]+arreglo[2]);
        arreglo[1]='j';
        String palabra=new String(arreglo);
        System.out.println(palabra);
        System.out.println(palabra.charAt(1));
        String palabra2=palabra.replace('a', 'e');
        System.out.println(palabra2);
        String[] arregloStrings={"Ana", "Tania", "Jose Luis", "Fran"};
        System.out.println(arregloStrings[2]);
    }
}
