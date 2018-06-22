#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

S_Empleado* Empleado_new()
{
    S_Empleado* this;
    this=malloc(sizeof(S_Empleado));
    return this;
}

void Empleado_delete(S_Empleado* this)
{
    free(this);
}

int Empleado_setId(S_Empleado* this,int id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int Empleado_getId(S_Empleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Empleado_setNombre(S_Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_getNombre(S_Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_setHorasTrabajadas(S_Empleado* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_getHorasTrabajadas(S_Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_setSueldo(S_Empleado* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int Empleado_getSueldo(S_Empleado* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

void em_calcularSueldo(void* p)
{
    int auxHoras;
    int sueldo;

    if(p!=NULL)
    {
        S_Empleado* empleado = (S_Empleado*) p;
        Empleado_getHorasTrabajadas(empleado,&auxHoras);
        if(auxHoras < 121)
        {
             sueldo=auxHoras*180;
        }
        else
        {
            if(auxHoras < 161)
            {
                sueldo=(120*180)+((auxHoras-120)*240);
            }
            else
            {
                if(auxHoras < 240)
                {
                    sueldo=(120*180)+((auxHoras-120)*240)+((auxHoras-160)*350);
                }
            }
        }
        Empleado_setSueldo(empleado,sueldo);
    }
}
