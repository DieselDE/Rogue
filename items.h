#include <stdio.h>

#ifndef ITEMS_H
#define ITEMS_H

#include "items.c"

struct item_list;

char *Item_name;

int item_name_list;

struct item_list* generate_item(int);

#endif