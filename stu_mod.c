#include "student.h"

void modnode(SLL *ptr)
{
    if(ptr == 0)
    {
        printf("NO RECORDS FOUND\n");
        return;
    }

    SLL *temp;
    char op, name[20];
    int roll, flag = 0;
    float percentage;

    printf("*****ENTER WHICH RECORD TO SEARCH FOR MODIFICATION*****\n");
    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");

    scanf(" %c", &op);

    if(op == 'R' || op == 'r')
    {
        printf("*****ENTER ROLL NUMBER*****\n");
        scanf("%d", &roll);
    }
    else if(op == 'N' || op == 'n')
    {
        printf("*****ENTER NAME*****\n");
        scanf("%19s", name);
    }
    else if(op == 'P' || op == 'p')
    {
        printf("*****ENTER PERCENTAGE*****\n");
        scanf("%f", &percentage);
    }
    else
    {
        printf("*****INVALID CHOICE*****\n");
        return;
    }

    temp = ptr;

    while(temp)
    {
        if((op == 'R' || op == 'r') && temp->rollno == roll)
        {
            flag = 1;
            break;
        }
        else if((op == 'N' || op == 'n') &&
                strcmp(temp->name, name) == 0)
        {
            printf("%d %s %.2f\n",
                   temp->rollno, temp->name, temp->percentage);
            flag = 1;
        }
        else if((op == 'P' || op == 'p') &&
                temp->percentage == percentage)
        {
            printf("%d %s %.2f\n",
                   temp->rollno, temp->name, temp->percentage);
            flag = 1;
        }

        temp = temp->next;
    }

    if(flag == 0)
    {
        printf("RECORD NOT FOUND\n");
        return;
    }

    if(op == 'N' || op == 'n' || op == 'P' || op == 'p')
    {
        printf("*****ENTER ROLL NUMBER OF RECORD TO MODIFY*****\n");
        scanf("%d", &roll);
    }

    temp = ptr;
    flag = 0;

    while(temp)
    {
        if(temp->rollno == roll)
        {
            if(op == 'N' || op == 'n')
            {
                if(strcmp(temp->name, name) != 0)
                {
                    temp = temp->next;
                    continue;
                }
            }

            if(op == 'P' || op == 'p')
            {
                if(temp->percentage != percentage)
                {
                    temp = temp->next;
                    continue;
                }
            }

            printf("CURRENT DETAILS PRINTING:\n");
            printf("%d %s %.2f\n",
                   temp->rollno, temp->name, temp->percentage);

            printf("*****ENTER UPDATED NAME AND PERCENTAGE*****\n");
            scanf("%s %f", temp->name, &temp->percentage);

            printf("*****RECORD MODIFICATION DONE*****\n");
            flag = 1;
            break;
        }

        temp = temp->next;
    }

    if(flag == 0)
        printf("RECORD NOT FOUND\n");
}
