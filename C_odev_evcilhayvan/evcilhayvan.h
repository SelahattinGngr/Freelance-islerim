#ifndef EVCILHAYVAN_H
#define EVCILHAYVAN_H
#define MAX_PETS 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pet
{
    char species[20];
    char name[20];
    int energy;
    int happiness;
};

#endif