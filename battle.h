#include <stdio.h>
#include <stdlib.h>

#ifndef BATTLE_H
#define BATTLE_H

#include "battle.c"

void battle(struct player*, struct enemy*);

void attack(struct player*, struct enemy*);

void defend(struct player*, struct enemy*);

void use_item(struct player*, struct enemy*);

void flee(struct player*, struct enemy*);

void enemy_turn(struct player*, struct enemy*, int);

#endif