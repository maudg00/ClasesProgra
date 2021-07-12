import java.util.Scanner;
public class Calcu 
    {
        public static void main(String [] args)
        {
            Calculadora miCalculadora=new Calculadora();
            miCalculadora.suma(3,5);
            double suma=miCalculadora.ANS;
            System.out.println("suma: "+suma+"cola");
            System.out.println("resta: "+miCalculadora.resta(miCalculadora.ANS,2));
            System.out.println("multiplicacion: "+miCalculadora.multiplica(miCalculadora.ANS,5));
            System.out.println("division: "+miCalculadora.divide(miCalculadora.ANS,4));
            Scanner sc = new Scanner(System.in);
            System.out.println("Dame el coeficiente a:");
            double a = sc.nextDouble();
            System.out.println("Dame el coeficiente b:");
            double b = sc.nextDouble();
            System.out.println("Dame el coeficiente c:");
            double c = sc.nextDouble();
            miCalculadora.ecuacion2do(a,b,c);
            System.out.println("Raiz x1: "+miCalculadora.x1);
            System.out.println("Raiz x2: "+miCalculadora.x2);
            sc.close();
        }
    }
