import java.util.Scanner;
import java.util.ArrayList;
public class UI {
    public static Scanner sc;
    public static char Menu()
    {
        char op;
        System.out.println("MENU: ");
        System.out.println("\t1.- Dar de alta alumno.");
        System.out.println("\t2.- Ver asistencias.");
        System.out.println("\t3.- Tomar asistencia.");
        System.out.println("\t4.- Salir.");
        op=sc.next().charAt(0);
        return op;
    }

    public static void desplegarAlumnos(ArrayList<alumno> Alumnos)
    {
        for(int i=0; i<Alumnos.size(); i++)
        {
            System.out.println("Alumno "+(i+1)+":");
            System.out.println("\tNombre: "+Alumnos.get(i).nombre);
            System.out.println("\tEdad: "+Alumnos.get(i).edad);
            System.out.println("\tSemestre: "+Alumnos.get(i).semestre);
            System.out.println("\tAsistencias: "+ Alumnos.get(i).asistencias + " de "+(clases.totalClases)+" posibles.");
        }
    }
}
