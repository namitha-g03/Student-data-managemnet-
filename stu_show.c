#include "student.h"

void printnode(SLL *ptr)
{
    if(ptr == 0)
    {
        printf("*********NO RECORDS FOUND*********\n");
        return;
    }
    printf("Roll No.     Name          Percentage\n");
    printf("--------------------------------------------------\n");

    while(ptr)
    {
        printf("%-13d %-14s %.2f\n",
               ptr->rollno, ptr->name, ptr->percentage);

        ptr = ptr->next;
    }

    printf("--------------------------------------------------\n");
}
int countnode(SLL *ptr)
{
    int c=0;

    while(ptr)
    {
        c++;
        ptr=ptr->next;
    }

    return c;
}
