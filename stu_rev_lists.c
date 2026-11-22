 #include "student.h"
 void reverselink(SLL **ptr)
{
    if(*ptr==0)
    {
        printf("NO RECORDS FOUND\n");
        return;
    }

    int i,c=countnode(*ptr);

    if(c>1)
    {
        SLL **a=malloc(sizeof(SLL*)*c);

        SLL *t=*ptr;

        for(i=0;i<c;i++)
        {
            a[i]=t;
            t=t->next;
        }

        for(i=c-1;i>0;i--)
            a[i]->next=a[i-1];

        a[0]->next=0;
        *ptr=a[c-1];

        free(a);
    }

    printf("LINKED LIST REVERSED SUCCESSFULLY\n");
}
