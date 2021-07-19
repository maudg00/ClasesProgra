import java.util.Scanner;
public class principal {
    public static void main(String[] args)
    {
        alumno[] Alumnos=new alumno[clases.maximoCupo];
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
                    
                    if(clases.totalAlumnos>=10)
                    {
                        System.out.println("ERROR: se ha superado el cupo maximo de alumnos.");
                    }
                    else
                    {
                        System.out.println("Dame el nombre de tu alumno: ");
                        tempNombre=UI.sc.next();
                        System.out.println("Dame la edad de tu alumno: ");
                        tempEdad=UI.sc.nextInt();
                        System.out.println("Dame el semestre de tu alumno: ");
                        tempSemestre=UI.sc.nextInt();
                        Alumnos[clases.totalAlumnos]=new alumno(tempSemestre, tempNombre, tempEdad);
                        System.out.println("El alumno "+(clases.totalAlumnos+1)+" se ha dado de alta exitosamente.");
                        clases.totalAlumnos++;
                    }
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
