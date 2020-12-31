/* Este programa calcula las raíces reales de un polinomio de segundo grado
con la forma general a*x^2 + b*x + c = 0, siempre y cuando los
coeficientes del polinomio sean todos positivos. El programa utiliza la 
fórmula para la solución general de la ecuación de segundo grado. */

// Librerías a incluir
#include <stdio.h>
#include <math.h>


// Declaración de funciones
void Descripcion(void);
void PedirValor(double *a, const char *description);
void CalcularRaices(double a, double b, double c, double *x1, double *x2);
void Desplegar(double a, double b, double c, double x1, double x2);

// Main
int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    const char 
        *desc1 = "Inserte el coeficiente del término cuadrático:\n",
        *desc2 = "Inserte el coeficiente del término lineal:\n",
        *desc3 = "Inserte el coeficiente del término independiente:\n";

    Descripcion();
    PedirValor(&a, desc1);
    PedirValor(&b, desc2);
    PedirValor(&c, desc3);
    CalcularRaices(a, b, c, &x1, &x2);
    Desplegar(a, b, c, x1, x2);
    return 0;
}

void Descripcion(void)
{
	printf("Este programa calcula las raíces de un polinomio de segundo grado\n"
    "descritos en su forma canónica. Su forma canónica es la siguiente:\n"
    "a*x^2 + b*x + c = 0\n");
}

void PedirValor(double *a, const char *description)
{
	int flag = 0;
	printf("%s", description);	
	while(flag == 0)
    {
		scanf("%lf",a);
		if(*a > 0)
			flag = 1;
		else 
			printf("El valor otorgado no es un número, o es menor a 0.\
            \nIntente de nuevo.\n");
            fflush(stdin);
    }
}

void CalcularRaices(double a, double b, double c, double *x1, double *x2)
{
	double discriminante = pow(b,2) - 4*a*c;
	
	if(discriminante < 0)
    {
		printf("El valor del discriminante del polinomio es menor a cero.\n");
		printf("El programa no permite resolver polinomios con raíces complejas.\n"
        "El programa devolverá ceros. \n");
    }
	else
    {
        *x1 = (-b + sqrt(discriminante))/(2*a);
		*x2 = (-b - sqrt(discriminante))/(2*a);
    }
}

void Desplegar(double a, double b, double c, double x1, double x2)
{
	printf(
		"Las raíces para el polinomio:\n"
		"%.2f x^2 + %.2f x + %.2f = 0\n"
        "Son las siguientes:\nx1 = %f\nx2 = %f\n",
        a, b, c, x1, x2);
}