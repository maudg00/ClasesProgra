class Principal
{
    public static void main(String[] args)
    {
        Calculadora.Suma(3.2,4.1);
        double suma=Calculadora.ANS;
        System.out.println("Suma: "+suma);
        System.out.println("Resta: "+Calculadora.Resta(Calculadora.ANS, 4));
        double multi=Calculadora.Multiplicar(2,3);
        System.out.println("Multiplicacion: "+multi);
        double div=Calculadora.Dividir(Calculadora.ANS, 3);
        System.out.println("Division: "+div);
    }
}