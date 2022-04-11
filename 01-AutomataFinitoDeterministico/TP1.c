#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int asignar_columna(char caracter){
    char* cadena0 = "0";
    char* cadena1 = "1234567";
    char* cadena2 = "89";
    char* cadena3 = "abcdefABCDEF";
    char* cadena4 = "xX";
    char cadena_aux[2];
    cadena_aux[0] = caracter;
    
    if(strstr(cadena0,cadena_aux)){
        return 0;
    }else
    if(strstr(cadena1,cadena_aux)){
        return 1;
    }else
    if(strstr(cadena2,cadena_aux)){
        return 2;
    }else
    if(strstr(cadena3,cadena_aux)){
        return 3;
    }else
    if(strstr(cadena4,cadena_aux)){
        return 4;
    }else{
        return -1;
    }
    
// Lee el caracter dado y lo compara con varios strings, si se encuentra algun caracter en el string se devuelve el estado siguiente segun el caracter.

};

int aisgnar_estado(int estado,char caracter){
    int columna;
    int matriz[6][5] = {
        {1,2,2,6,6},
        {5,5,6,6,3},
        {2,2,2,6,6},
        {4,4,4,4,6},
        {4,4,4,4,6},
        {5,5,6,6,6}
    };

// Define una variable columna a definir y una matriz ya inicializada con los valores de la matriz de lectura de constantes (https://onedrive.live.com/redir?resid=73A86BFF829778D1%21269&authkey=%21AO1GED7Gink1j1g&page=View&wd=target%28AF.one%7C98d52e32-fca4-4b4d-9e51-a21304f9edc1%2FEjemplo%20Constantes%20Enteras%20de%20C%7Cc06b2d48-a235-485d-8c64-e0219aa9cb46%2F%29)


    if(estado == 6){
        return 6;
    }else{
        columna = asignar_columna(caracter);
        if(columna != -1){
            return matriz[estado][columna];
        }else{
            return 6;
        }
    }

/* Recibe el estado anterior y el caracter, si el estado anterior es 6 devuelve de nuevo 6 debido a que esta es la lectura de una linea no reconocida, sino le asigna un estado a la columna segun el caracter
y de ahi comprueba de que el caracter haya sido reconocido, de ser a si lee la matriz y devuelve el estado proximo o sino devuelve 6. */

};

char* definir_estado(int estado){
    switch (estado) {
    case 1 : return "OCTAL";
        break;
    case 2 : return "DICIMAL";
        break;
    case 4 : return "HEXADECIMAL";
        break;
    case 5 : return "OCTAL";
        break;
    default : return "NO RECONOCIDO";     
    }

// Define el estado segun si esta en uno de los estados finales de la gramatica (1, 2, 4, o 5) o si esta en el estado incorrecto  (6) (u otro estado) y devuelve un string segun eso.

}

int main(int argc, char const *argv[]){

    int estado = 0;

    char caracter[2];

    char *tipopalabra, *espacio = "    ", *salto = "\n";

/* Define las variables, siendo estado el punto del automata en el que esta, caracter el caracter leido del archivo entrada, tipopalabra el nombre del sistema del numero, espacio para añadir al principio de la 
linea y salto para poner al final. */

    FILE *f = fopen("entrada.txt","r");
    FILE *t = fopen("salida.txt","w");

// Abre los archivos de entrada y salida. 

     if (f == NULL){
        printf("Error al abrir el archivo entrada.txt");
        system ("pause");    
        return -1;
    }

// Si el archivo esta vacio o no se abre correctamente se cancela el programa.

    caracter[0]=getc(f);

// Se lee el caracter en el que el pointer del archivo esta puesto, despues se mueve un caracter a la izquierda.

    while (caracter[0]!=EOF) {
          
// Cicla por todo el archivo hasta que el caracter es igual a EndOfFile.

          if(caracter[0]!=','){
            
            estado=aisgnar_estado(estado,caracter[0]);
            
            fputc(caracter[0],t);

// Si el caracter es distinto de ',' (una coma), se le asigna un estado de la columna de estados y de ahi lo escribe al archivo y mueve el puntero del archivo salida a la derecha.

        }else{

            tipopalabra = definir_estado(estado);

            estado = 0;

            fputs(espacio,t);
            fputs(tipopalabra,t);
            fputs(salto,t);
            
/* Si el caracter es ',' (una coma), se define el tipo de la string en base a su ultimo estado que deberia ser uno finalizador (estados 1, 2, 4, 5), se devuelve el estado a 0, y se imprime en el archivo 
los espacios, el tipo del string, y el salto de linea para comenzar de nuevo. */

        }
    caracter[0]=getc(f);

// Se vuelve a leer el archivo.

    }
    
    fclose(f);
    fclose(t);

// Se cierran los archivos de entrada y salida.

    return 0;
}