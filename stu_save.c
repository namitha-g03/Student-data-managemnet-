#include "student.h"

void savefile(SLL *ptr)
{
    FILE *fp;

    fp = fopen("student.dat", "w");

    if(fp == 0)
    {
        printf("*****NO FILES PRESENT*****\n");
        return;
    }

    while(ptr)
    {
        fprintf(fp, "%d %s %f\n",
                ptr->rollno, ptr->name, ptr->percentage);

        ptr = ptr->next;
    }

    fclose(fp);

    printf("*****RECORDS SAVED SUCCESSFULLY*****\n");
}

void readfile(SLL **ptr)
{
    SLL *new;
    FILE *fp;

    fp = fopen("student.dat", "r");

    if(fp == 0)
    {
        printf("NO FILES PRESENT\n");
        return;
    }

    while(1)
    {
        new = malloc(sizeof(SLL));

        if(new == 0)
        {
            printf("MEMORY ALLOCATION FAILED\n");
            break;
        }

        if(fscanf(fp, "%d %s %f",
                  &new->rollno, new->name, &new->percentage) != -1)
        {
            free(new);
            break;
        }

        new->next = 0;

        if(*ptr == 0)
            *ptr = new;
        else
        {
            SLL *last = *ptr;

            while(last->next)
                last = last->next;

            last->next = new;
        }
    }

    fclose(fp);

}
