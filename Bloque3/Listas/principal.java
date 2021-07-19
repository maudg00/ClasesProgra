import java.util.ArrayList;
public class principal
{
    public static void main(String[] args)
    {
        ArrayList<alumno> listaAlumnos=new ArrayList<alumno>();
        alumno alumnoPrueba=new alumno(7, "Tania", 21);
        listaAlumnos.add(alumnoPrueba);
        alumno alumno2=new alumno(7,"Ana",21);
        listaAlumnos.add(alumno2);
        for(int i=0; i<listaAlumnos.size();i++)
        {
            alumno temp=listaAlumnos.get(i);
            System.out.println("Alumno "+(i+1)+ " se llama "+temp.nombre);
        }
    }
    
}
