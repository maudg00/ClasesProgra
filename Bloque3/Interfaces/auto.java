public class auto implements vehiculo{
    public float aceleracion=35f;
    public float velocidadActual=0f;
    public float velocidadMaxima=215.56f;
    public String color="Blanco";
    public float potencia=155.4f;
    public String numeroSerie="45dc67b";
    public float posicion=0;
    public boolean prendido=false;
    public void avanzar(float posicionInicial, float posicionFinal)
    {
        if(posicionInicial<posicionFinal)
        {
            posicion=posicionFinal;
            System.out.println("La nueva posicion del auto es: "+posicion);
        }
    }
    public void encender()
    {
        this.prendido=true;
        System.out.println("Mi auto encendio :D");
    }
    public void apagar()
    {
        this.prendido=false;
        System.out.println("Mi auto apago :D");
    }
    public void frenar()
    {
        this.velocidadActual=0f;
        System.out.println("Mi auto freno :D");
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
    public void prenderLimpiaparabrisas()
    {
        System.out.println("Quitando la mugre lluvia :D.");
    }
    public void prenderRadio()
    {
        System.out.println("Que buena rola");
    }
}
