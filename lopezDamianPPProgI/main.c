#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMNOTE 4

typedef struct{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
}eNotebook;

float aplicarDescuento(float* precioProd);

int contarCaracteres(char cadena[], char* caracter);

void ordenarNotebookPorMarca(eNotebook listaNotebooks, int tamNote);

int main()
{
    eNotebook listadoNote[TAMNOTE]={
        {100, "Intel I5", "MarcaUno", 10000},
        {100, "Ryzen 3", "MarcaDos", 15000},
        {100, "Ryzen 5", "MarcaTres", 14000},
        {100, "Intel I8", "MarcaDos", 11500},
    };
    float precioProducto;
    char caracter='a';

    printf("Ingrese precio: ");
    scanf("%f",&precioProducto);
    printf("El producto sin descuento vale: $ %.2f\n",precioProducto);
    precioProducto=aplicarDescuento(&precioProducto);
    printf("El producto con descuento vale: $ %.2f\n\n\n",precioProducto);

    printf("%d",contarCaracteres("Probando",&caracter));

    ordenarNotebookPorMarca(listadoNote, TAMNOTE);
    return 0;
}

float aplicarDescuento(float* precioProd)
{
    float retorno=-1;
    if(precioProd!=NULL)
    {
        retorno=*(precioProd)*0.95;
    }

    return retorno;
}

int contarCaracteres(char cadena[], char* caracter)
{
    int contador=-1;
    if(cadena!=NULL)
    {
        contador=0;
        for(int i=0; cadena[i]!='\0'; i++)
        {
            if(cadena[i]==*caracter)
            {
                contador++;
            }
        }
    }

    return contador;
}

void ordenarNotebookPorMarca(eNotebook listaNotebooks, int tamNote)
{
    eNotebook auxNote;
    if(procesador!=NULL && marca!=NULL)
    {
        for(int i=0; i<tamNote-1; i++)
        {
            for(int j=i+1; j<tamNote; j++)
            {
                if(strcmp(listaNotebooks[i].marca,listaNotebooks[j].marca)<0 || (listaNotebooks[i].marca,listaNotebooks[j].marca)==0 && listaNotebooks[i].precio>listaNotebooks[j].precio))
                {
                    auxNote = listaNotebooks[i];
                    listaNotebooks[i] = listaNotebooks[j];
                    listaNotebooks[j]=auxNote;
                }

            }
        }
    }
}
