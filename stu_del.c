#include "student.h"

void deletenode(SLL **ptr)
{
    if(*ptr == 0)
    {
        printf("NO RECORDS FOUND\n");
        return;
    }

    char op, name[20];
    int roll, flag = 0;

    printf("----R/r : Enter roll number to delete----\n");
    printf("----N/n : Enter name to delete----\n");
    scanf(" %c", &op);

    if(op == 'R' || op == 'r')
    {
        printf("----ENTER ROLL NUMBER TO DELETE----\n");
        scanf("%d", &roll);
    }
    else if(op == 'N' || op == 'n')
    {
        printf("----ENTER NAME TO DELETE----\n");
        scanf("%s", name);

        SLL *temp = *ptr;

        while(temp)
        {
            if(strcmp(temp->name, name) == 0)
            {
                printf("%d %s %f\n",
                       temp->rollno, temp->name, temp->percentage);
                flag = 1;
            }

            temp = temp->next;
        }

        if(flag == 0)
        {
            printf("----NAME NOT FOUND----\n");
            return;
        }

        printf("----ENTER ROLL NUMBER TO DELETE----\n");
        scanf("%d", &roll);
    }
    else
    {
        printf("----INVALID CHOICE----\n");
        return;
    }

    SLL *del = *ptr;
    SLL *prev = NULL;

    while(del)
    {
        if(del->rollno == roll)
        {
            if(op == 'N' || op == 'n')
            {
                if(strcmp(del->name, name) != 0)
                {
                    printf("----ROLL NUMBER DOES NOT MATCH NAME----\n");
                    return;
                }
            }

            if(del == *ptr)
                *ptr = del->next;
            else
                prev->next = del->next;

            free(del);

            printf("----RECORD DELETED SUCCESSFULLY----\n");
            return;
        }

        prev = del;
        del = del->next;
    }

    printf("----NO ROLLNO FOUND----\n");
}
