class Calculadora
{
    public double ANS;
    public double x1;
    public double x2;
    Calculadora()
    {
        this.ANS=0;
    }
    public double suma(double a, double b)
    {
        this.ANS=a+b;
        return this.ANS;
    }
    public double resta(double a, double b)
    {
        this.ANS=a-b;
        return this.ANS;
    }
    public double multiplica(double a, double b)
    {
        this.ANS=a*b;
        return this.ANS;
    }
    public double divide(double a, double b)
    {
        this.ANS=a/b;
        return this.ANS;
    }
    public void ecuacion2do(double a, double b, double c) throws Exception
    {
        if((Math.pow(b,2))<(4*a*c))
        {
            throw new Exception("Numero imaginario, raices negativas.");
        }
        else
        {
            this.x1=(-b-Math.sqrt(Math.pow(b,2)-4*a*c))/(2*a);
            this.x2=(-b+Math.sqrt(Math.pow(b,2)-4*a*c))/(2*a);
        }
        
    }
}