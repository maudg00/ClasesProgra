import java.util.Scanner;
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

    public static void desplegarAlumnos(alumno[] Alumnos)
    {
        for(int i=0; i<clases.totalAlumnos; i++)
        {
            System.out.println("Alumno "+(i+1)+":");
            System.out.println("\tNombre: "+Alumnos[i].nombre);
            System.out.println("\tEdad: "+Alumnos[i].edad);
            System.out.println("\tSemestre: "+Alumnos[i].semestre);
            System.out.println("\tAsistencias: "+ Alumnos[i].asistencias + " de "+(clases.totalClases)+" posibles.");
        }
    }
}
