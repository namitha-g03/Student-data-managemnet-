 #include "student.h"
void deleteallnode(SLL **ptr)
{
    if(*ptr == 0)
    {
        printf("NO RCORDS FOUND\n");
        return;
    }

    SLL *del = *ptr;

    while(del)
    {
        *ptr = del->next;

        free(del);

        del = *ptr;
    }

    *ptr = NULL;

    printf("ALL STUDENT RECORDS DELETED SUCCESSFULLY\n");
}
