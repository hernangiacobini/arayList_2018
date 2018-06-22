/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"
#include "../inc/Employee.h"


void cargarDatos(ArrayList* lista, char* nombreArchivo);

int main(void)
{
    ArrayList* listaTotal;
    listaTotal = al_newArrayList();
    ArrayList* listaNegra;
    listaNegra = al_newArrayList();
    ArrayList* listaBlanca;
    listaBlanca = al_newArrayList();

    cargarDatos(listaTotal,"destinatarios.csv");
    cargarDatos(listaNegra,"black_list.csv");

    return 0;
}

void cargarDatos(ArrayList* lista, char* nombreArchivo)
{
    FILE* archivo;
    archivo=fopen(nombreArchivo,"r");

    char auxNombre[51];
    char auxEmail[51];

    if(archivo != NULL)
    {
        do
        {
            int partes = fscanf(archivo,"%[^,],%[\n]\n",auxNombre,auxEmail);

            if(partes==2)
            {
                Employee* auxempl = newEmployee(auxNombre,auxEmail);

                al_add(lista,auxempl);
            }

        }while(!feof(archivo));
    }
}


int compareField(void* campo1, void* campo2)
{
    int returnAux = -1;
    int i;

    if(campo1 != NULL && campo2 != NULL)
    {

    }
    return returnAux;
}
}

