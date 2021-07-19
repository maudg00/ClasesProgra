import java.util.Scanner;
import java.util.ArrayList;
public class principal {
    public static void main(String[] args)
    {
        ArrayList<alumno> Alumnos=new ArrayList<alumno>();
        UI.sc=new Scanner(System.in);
        char op;
        String tempNombre;
        int tempEdad, tempSemestre;
        op='z';
        while(op!='4')
        {
            op=UI.Menu();
            switch(op)
            {
                case '1':
                    
                    System.out.println("Dame el nombre de tu alumno: ");
                    tempNombre=UI.sc.next();
                    System.out.println("Dame la edad de tu alumno: ");
                    tempEdad=UI.sc.nextInt();
                    System.out.println("Dame el semestre de tu alumno: ");
                    tempSemestre=UI.sc.nextInt();
                    alumno tempAlumno=new alumno(tempSemestre, tempNombre, tempEdad);
                    Alumnos.add(tempAlumno);
                    System.out.println("El alumno "+(Alumnos.size())+" se ha dado de alta exitosamente.");
                break;
                case '2':
                    UI.desplegarAlumnos(Alumnos);
                break;
                case '3':
                    clases.pasarAsistencia(Alumnos);
                break;
                case '4':
                    System.out.println("Gracias por usar el programa.");
                break;
                default:
                    System.out.println("ERROR: Opcion invalida.");
                break;
            }
            
        }   
        UI.sc.close();
    }
    
}
