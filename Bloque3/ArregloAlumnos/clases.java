public class clases {
    public static int totalClases=0;
    public static int maximoCupo=10;
    public static int totalAlumnos=0;
    public static void pasarAsistencia(alumno[] Alumnos)
    {
        System.out.println("Dia de clases #"+(clases.totalClases+1)+":");
        for(int i=0;i<totalAlumnos;i++)
        {
            int asistio;
            System.out.println("Vino el alumno "+Alumnos[i].nombre+"?");
            System.out.println("Presiona 0 si falto, 1 si asistio... ");
            asistio=UI.sc.nextInt();
            if(asistio==1)
            {
                Alumnos[i].tomarAsistencia();
            }
        }
        clases.totalClases++;
    }
}
