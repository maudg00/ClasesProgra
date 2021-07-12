class Calculadora
{
    public static double ANS;
    public static double Suma(double a, double b)
    {
        Calculadora.ANS=a+b;
        return a+b;
    }
    public static double Resta(double a, double b)
    {
        Calculadora.ANS=a-b;
        return a-b;
    }
    public static double Multiplicar(double a, double b)
    {
        Calculadora.ANS=a*b;
        return a*b;
    }
    public static double Dividir(double a, double b)
    {
        Calculadora.ANS=a/b;
        return a/b;
    }
}