#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct item_list{
    char name[MAX];
    int rare;
    int hp;
    int atk;
    int def;
    int spe;
};

char *Item_name[] = {
    "wooden sword", "silver sword", "leather chestplate", "leather boots", "ring of healing", "ring of regeneration", "ring of power", "longbow", "shortbow", "wand", "throwing stars"
};

int item_name_list = sizeof(Item_name) / sizeof(Item_name[0]);

struct item_list* generate_item(int rarity){
    struct item_list* newitem = (struct item_list*) malloc(sizeof(struct item_list));

    strcpy(newitem->name, Item_name[random(0, (item_name_list - 1))]);
    newitem->rare = rarity;
    newitem->hp = (random(1, 10) * rarity);
    newitem->atk = (random(1, 5) * rarity);
    newitem->def = (random(1, 5) * rarity);
    newitem->spe = (random(1, 2) * rarity);
    
    return newitem;
};