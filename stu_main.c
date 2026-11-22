#include"student.h"

int main()
{
    SLL *headptr=0;
    char op,ch;

    readfile(&headptr);

    while(1)
    {
        printf("\n******** STUDENT RECORD MENU ********\n");
        printf("a/A : Add new record\n");
        printf("d/D : Delete a record\n");
        printf("s/S : Show the list\n");
        printf("m/M : Modify a record\n");
        printf("v/V : Save records\n");
        printf("e/E : Exit\n");
        printf("t/T : Sort the list\n");
        printf("l/L : Delete all the records\n");
        printf("r/R : Reverse the list\n");

        printf("Enter your choice:\n");
        scanf(" %c",&op);

        switch(op)
        {
            case 'a':
            case 'A':
                addnode(&headptr);
                break;

            case 'd':
            case 'D':
                deletenode(&headptr);
                break;

            case 's':
            case 'S':
                printnode(headptr);
                break;

            case 'm':
            case 'M':
                modnode(headptr);
                break;

            case 'v':
            case 'V':
                savefile(headptr);
                break;

            case 'e':
            case 'E':
                printf("S/s : Save and exit\n");
                printf("E/e : Exit without saving\n");
                scanf(" %c",&ch);

                if(ch=='s' || ch=='S')
                {
                    savefile(headptr);
                    deleteallnode(&headptr);
                    exit(0);
                }
                else if(ch=='e' || ch=='E')
                {
                    deleteallnode(&headptr);
                    exit(0);
                }
                break;

            case 't':
            case 'T':
                sortdata(headptr);
                break;

            case 'l':
            case 'L':
                deleteallnode(&headptr);
                break;

            case 'r':
            case 'R':
                reverselink(&headptr);
                break;

            default:
                printf("INVALID CHOICE\n");
        }
    }
}
