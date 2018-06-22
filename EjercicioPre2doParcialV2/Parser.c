#include "ArrayList.h"
#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>

int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados)
{
    FILE* pfile;
    int r;
    int auxId;
    char auxNombre[20];
    int auxHoras;
    S_Empleado *auxEmpleado;

    pfile = fopen(fileName,"r");

    if(listaEmpleados != NULL && pfile != NULL)
    {
        fscanf(pfile,"%d,%[^,],%d\n",&auxId,auxNombre,&auxHoras);
        do
        {
            r=fscanf(pfile,"%d,%[^,],%d\n",&auxId,auxNombre,&auxHoras);

            if(r==3)
            {
                auxEmpleado = Empleado_new();
                Empleado_setId(auxEmpleado,auxId);
                Empleado_setNombre(auxEmpleado,auxNombre);
                Empleado_setHorasTrabajadas(auxEmpleado,auxHoras);
                al_add(listaEmpleados,auxEmpleado);
            }
        }while(!feof(pfile));
    }

    fclose(pfile);

    return 1; // OK
}

