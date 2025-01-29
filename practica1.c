#include <stdio.h>


int longitudCadena(char str[])
{
    int i, longitud = 0;
    for(i = 0; str[i]!= '\0';i++)
    {
        longitud++;
    }
    return longitud;
}

int primerDigito(int longitud) {
    if (longitud >= 1 && longitud <= 10) {
        return longitud;
    }
    if (longitud > 10) {
        return longitud % 10;
    }
    return 0; 
}

char segundoDigito(char str[])
{
   int i = 0;
   
   while (str[i] != '\0')
   {
       char caracter = str[i];
       
       if(caracter > 'a' && caracter <= 'z')
       {
           return caracter - ('a' - 'A');
       }
       if (caracter >= 'A' && caracter <= 'Z')
       {
           return caracter;
       }
        i++;
    }
    return '\0';
}


int tercerDigito(char str[])
{
    int i, vocales = 0;
    for(i = 0; str[i]!= '\0';i++)
    {
        int caracter = str[i];
        if(caracter == 'a' || caracter =='A' || caracter == 'e' || caracter == 'E' || caracter == 'i' || caracter =='I' || caracter == 'o' || caracter == 'O' || caracter == 'u' || caracter == 'U')
        {
            vocales++;
        }
    }
    return vocales;
}


char cuartoDigito(char str[])
{
    int i;
    for(i = 0; str[i]!= '\0';i++)
    {   
        int caracter = str[i];
        if(caracter == 'e' || caracter == 'E')
        {
            return '!';
        }
    }
    return '#';
}


void ultimosTres(char str[]) {
    int longitud = longitudCadena(str);
    if (longitud >= 3) {
        for (int i = longitud - 1; i >= longitud-3; i--) {
            printf("%c", str[i]);
        }
    } else {
        printf("La cadena tiene menos de 3 caracteres ");
    }
    printf("\n");
}
    
    


int main()
{
    char identificador [7];
    char pagina [100];


    printf("Ingrese la web: ");
    scanf("%s", pagina);
    
    identificador[0] = primerDigito(longitudCadena(pagina));
    identificador[1] = segundoDigito(pagina);
    identificador[2] = tercerDigito(pagina);
    identificador[3] = cuartoDigito(pagina);


    
    printf("Para '%s' el primer caracter seria %d \n", pagina, identificador[0]);
    printf("Para '%s' el segundo caracter seria %c \n", pagina, identificador[1]);
    printf("Para '%s' el tercer caracter seria %d \n ", pagina, identificador[2]);
    printf("Para '%s' el cuarto caracter seria %c ", pagina, identificador[3]);
    printf("Para '%s' los ultimos 3 caracteres serian ", pagina);
    ultimosTres(pagina);
    
    printf("Entonces para '%s', el identificador único seria %d%c%d%c", pagina, identificador[0], identificador[1], identificador[2], identificador[3]);
    ultimosTres(pagina);


    return 0;
}
