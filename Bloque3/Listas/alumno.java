public class alumno
{
    
    public int semestre;
    public String nombre;
    public int asistencias;
    public int edad;
    alumno(int semestre, String nombre, int edad)
    {
        this.semestre=semestre;
        this.nombre=nombre;
        this.edad=edad;
        this.asistencias=0;
    }
    public void tomarAsistencia()
    {
        this.asistencias++;
    }
}