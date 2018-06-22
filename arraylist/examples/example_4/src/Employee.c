#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Employee.h"

void printEmployee(Employee* p)
{
    printf("Nombre:%s email:%s\r\n",p->name,p->email);
}

/** \brief Set this employee the values recived as parameters
 *
 * \param pEmployee employee*
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
Employee* newEmployee(char name[],char email[])
{
    Employee* returnAux = NULL;
    Employee* pEmployee = malloc(sizeof(Employee));

    if(pEmployee != NULL)
    {
        strcpy(pEmployee->name,name);
        strcpy(pEmployee->email,email);
        returnAux = pEmployee;
    }

    return returnAux;

}

