import java.util.Scanner;
import java.io.File;
public class principal {
    public static void main(String[] args)
    {
        try
        {
            alumno miAlumno;
            File miArchivo=new File("./arch.txt"); //FILE* miArchivo=fopen("arch.txt");
            Scanner sc=new Scanner(miArchivo);
            String Nombre=sc.next();
            String stringEdad=sc.next();
            int edad=Integer.parseInt(stringEdad);
            System.out.println(edad+1);
            int semestre=sc.nextInt();
            int asistencias=sc.nextInt();
            miAlumno=new alumno(semestre, Nombre, edad);
            miAlumno.asistencias=asistencias;
            System.out.println("El alumno "+miAlumno.nombre+" tiene "+miAlumno.edad+" anios, va en "+miAlumno.semestre+" semestre y tiene "+miAlumno.asistencias+" asistencias.");
            sc.close();
        }
        catch(Exception miExcepcion)
        {
            System.out.println("HUBO UN ERROR CON EL ARCHIVO :("+miExcepcion);
        }
    }
}
