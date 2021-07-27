import java.util.Scanner;
import java.io.File;
import java.io.FileWriter;
public class principal {
    public static void main(String[] args)
    {
        alumno miAlumno;
        String Nombre;
        String stringEdad;
        int edad;
        int semestre;
        int asistencias;
        try
        {
            
            File miArchivo=new File("./Archivos/arch.txt"); //FILE* miArchivo=fopen("arch.txt");
            Scanner sc=new Scanner(miArchivo);
            Nombre=sc.next();
            stringEdad=sc.next();
            edad=Integer.parseInt(stringEdad);
            System.out.println(edad+1);
            semestre=sc.nextInt();
            asistencias=sc.nextInt();
            sc.close();
        }
        catch(Exception miExcepcion)
        {
            System.out.println("HUBO UN ERROR CON EL ARCHIVO DE LECTURA:("+miExcepcion);
            return;
        }
        miAlumno=new alumno(semestre, Nombre, edad);
        miAlumno.asistencias=asistencias;
        System.out.println("El alumno "+miAlumno.nombre+" tiene "+miAlumno.edad+" anios, va en "+miAlumno.semestre+" semestre y tiene "+miAlumno.asistencias+" asistencias.");
        alumno Alumno2=new alumno(7, "Jose Luis", 22);
        Alumno2.tomarAsistencia();
        try
        {
            File archivoEscribir=new File("./Archivos/archivoWrite.txt");
            if(archivoEscribir.createNewFile()==true)
            {
                FileWriter escribirEnArch=new FileWriter(archivoEscribir);
                //FileWriter escribir=new FileWriter("./Archivos/archivoWrite.txt"); POLIMORFISMO
                escribirEnArch.write(Alumno2.nombre+", "+Alumno2.edad+", "+Alumno2.semestre+", "+Alumno2.asistencias);
                escribirEnArch.close();
            }
            else
            {
                System.out.println("Ya existe ese archivo :(.");
            }
        }
        catch (Exception e)
        {
            System.out.println("HUBO UN ERROR CON EL ARCHIVO DE ESCRITURA :( "+e);
        }
        
    }
}
