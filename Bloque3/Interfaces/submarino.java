public class submarino implements vehiculo{
    public float aceleracion=15f;
    public float velocidadActual=0f;
    public float velocidadMaxima=155.56f;
    public String color="Negro";
    public float potencia=85.4f;
    public String numeroSerie="464688d";
    public float posicion=0;
    public boolean prendido=false;
    public float altura=5f;
    public boolean sumergido=false;
    public void avanzar(float posicionInicial, float posicionFinal)
    {
        if(posicionInicial<posicionFinal)
        {
            posicion=posicionFinal;
            System.out.println("La nueva posicion del submarino es: "+posicion);
        }
    }
    public void encender()
    {

        this.prendido=true;
        if(sumergido)
        {
            System.out.println("Mi submarino encendio y se sumergio :D");
        }
        else
        {
            System.out.println("Mi submarino encendio y no esta sumergido :D");
        } 
    }
    public void apagar()
    {
        if(this.sumergido==true)
        {
            this.regresarASuperficie();
        }
        this.prendido=false;
        System.out.println("Mi submarino apago :D");
    }
    public void frenar()
    {
        this.velocidadActual=0f;
        System.out.println("Mi submarino freno :D");
    }
    public void acelerar(int segundos)
    {
        if(velocidadActual+(aceleracion*segundos)<=velocidadMaxima)
        {
            velocidadActual+=aceleracion*segundos;
            System.out.println("Acelere a una velocidad de "+velocidadActual);
        }
        else
        {
            velocidadActual=velocidadMaxima;
            System.out.println("Acelere a una velocidad de "+velocidadActual);
        }
    }
    public boolean sumergir(float profundidad)
    {
        if(profundidad>=altura)
        {
            sumergido=true;
        }
        else
        {
            sumergido=false;
        }
        return sumergido;
    }
    public void regresarASuperficie()
    {
        this.sumergido=false;
        System.out.println("Regresando a superficie :D");
    }
}
