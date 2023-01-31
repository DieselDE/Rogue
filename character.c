#include <stdio.h>

#define MAX 50
#define MAX_DEF 200

/*
erst inventar und items einführen
Gegner erstellen -> erstmal ne Liste, 
dann dynamisch mit malloc
*/

struct player{
    char name[MAX];
    int lvl; // class changed to level/experience
    int hp;
    int atk;
    int def;
    int spe;
};

struct enemy{
    char name[MAX];
    int hp;
    int atk;
    int def;
    int spe;
};

struct player blub = {
        "Blub", 5, 100, 15, 10, 20
    };