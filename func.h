#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef FUNC_H
#define FUNC_H

#include "func.c"

int random(int, int);

struct enemy* declaration_enemy(int);

void fight(struct player*, struct enemy*, int);

#endif