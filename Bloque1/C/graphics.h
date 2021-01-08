/* graphics.h

Biblioteca que facilita el uso de colores al imprimir en terminal en C. Funciona
en Linux/UNIX. Utiliza los ANSI Escape codes de 3 bits. 

@author José Luis Aguilar <aguilarch.joseluis@gmail.com>
Hecho el 8 de enero de 2021

*/

#include <stdio.h>
#ifndef graphics_h
#define graphics_h
#ifndef graphics_IMPORT
    #define EXTERN
#else
    #define EXTERN extern
#endif
/* Colores del texto: */
#define Black "\033[0;30m" 
#define Red "\033[0;31m"
#define Green "\033[0;32m"
#define Yellow "\033[0;33m"
#define Blue "\033[0;34m"
#define Magenta "\033[0;35m"
#define Cyan "\033[0;36m"
#define White "\033[0;37m"
#define gray "\033[0;90m"
#define brightRed "\033[0;91m"
#define brightGreen "\033[0;92m"
#define brightYellow "\033[0;93m"
#define brightBlue "\033[0;94m"
#define brightMagenta "\033[0;95m"
#define brightCyan "\033[0;96m"
#define brightWhite "\033[0;97m"

#define boldtext "\033[1m"
#define italicstext "\033[3m"
#define underscoretext "\033[4m"

/* Colores del background: */
#define BlackBG "\033[0;30m"
#define RedBG "\033[0;31m"
#define GreenBG "\033[0;32m"
#define YellowBG "\033[0;33m"
#define BlueBG "\033[0;34m"
#define MagentaBG "\033[0;35m"
#define CyanBG "\033[0;36m"
#define WhiteBG "\033[0;37m"
#define grayBG "\033[0;100m"
#define brightRedBG "\033[0;101m"
#define brightGreenBG "\033[0;102m"
#define brightYellowBG "\033[0;103m"
#define brightBlueBG "\033[0;104m"
#define brightMagentaBG "\033[0;105m"
#define brightCyanBG "\033[0;106m"
#define brightWhiteBG "\033[0;107m"

#define endformat "\033[0m"

/* Pallette: 
*
* Imprime una paleta de colores y tipos de fuentes en la terminal.
* 
*/
void graphicsPallette(void);

#undef graphics_IMPORT
#undef EXTERN
#endif