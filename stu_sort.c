#include "student.h"
void sortdata(SLL *ptr)
{
    if(ptr == 0)
    {
        printf("NO RECORDS FOUND\n");
        return;
    }

    char op;
    int i, j, c = countnode(ptr);

    SLL *p1 = ptr, *p2;
    SLL t;

    printf("N/n : Sort with name\n");
    printf("P/p : Sort with percentage\n");

    scanf(" %c", &op);

    for(i = 0; i < c - 1; i++)
    {
        p2 = p1->next;

        for(j = 0; j < c - 1 - i; j++)
        {
            if((op == 'N' || op == 'n') &&
               strcmp(p1->name, p2->name) > 0)
            {

                t.rollno = p1->rollno;
                strcpy(t.name, p1->name);
                t.percentage = p1->percentage;

                p1->rollno = p2->rollno;
                strcpy(p1->name, p2->name);
                p1->percentage = p2->percentage;

                p2->rollno = t.rollno;
                strcpy(p2->name, t.name);
                p2->percentage = t.percentage;
            }

            else if((op == 'P' || op == 'p') &&
                    p1->percentage < p2->percentage)
            {

                t.rollno = p1->rollno;
                strcpy(t.name, p1->name);
                t.percentage = p1->percentage;

                p1->rollno = p2->rollno;
                strcpy(p1->name, p2->name);
                p1->percentage = p2->percentage;

                p2->rollno = t.rollno;
                strcpy(p2->name, t.name);
                p2->percentage = t.percentage;
            }

            p2 = p2->next;
        }

        p1 = p1->next;
    }

    if(op == 'N' || op == 'n')
        printf("+++++RECORDS SORTED BY NAME+++++\n");
    else if(op == 'P' || op == 'p')
        printf("+++++RECORDS SORTED BY PERCENTAGE+++++\n");
    else
        printf("+++++INVALID CHOICE+++++\n");
}
