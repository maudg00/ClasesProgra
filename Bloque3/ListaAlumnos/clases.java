import java.util.ArrayList;
public class clases {
    public static int totalClases=0;
    public static void pasarAsistencia(ArrayList<alumno> Alumnos)
    {
        System.out.println("Dia de clases #"+(clases.totalClases+1)+":");
        for(int i=0;i<Alumnos.size();i++)
        {
            int asistio;
            alumno alumnoActual=Alumnos.get(i);
            System.out.println("Vino el alumno "+alumnoActual.nombre+"?");
            System.out.println("Presiona 0 si falto, 1 si asistio... ");
            asistio=UI.sc.nextInt();
            if(asistio==1)
            {
                alumnoActual.tomarAsistencia();
            }
        }
        clases.totalClases++;
    }
}
