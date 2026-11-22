#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student
{
        int rollno;
        char name[50];
        float percentage;
        struct student *next;
} SLL;


void addnode(SLL **);
void deletenode(SLL **);
void deleteallnode(SLL **);
void printnode(SLL *);
void modnode(SLL *);
void savefile(SLL *);
void readfile(SLL **);
void sortdata(SLL *);
void reverselink(SLL **);
int countnode(SLL *ptr);

#endif
