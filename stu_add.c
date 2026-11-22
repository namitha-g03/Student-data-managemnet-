#include "student.h"

void addnode(SLL **ptr)
{
    SLL *new;
    SLL *temp;
    int roll = 1, flag;

    new = malloc(sizeof(SLL));

    if(new == NULL)
    {
        printf("NO RECORDS FOUND\n");
        return;
    }

    while(1)
    {
        flag = 0;
        temp = *ptr;

        while(temp)
        {
            if(temp->rollno == roll)
            {
                flag = 1;
                break;
            }
            temp = temp->next;
        }

        if(flag == 0)
            break;

        roll++;
    }

    new->rollno = roll;

    printf("***** ENTER NAME AND PERCENTAGE *****\n");
    scanf("%s %f", new->name, &new->percentage);

    new->next = *ptr;
    *ptr = new;

    printf("***** RECORD ADDED SUCCESFULLY *****\n");
}
