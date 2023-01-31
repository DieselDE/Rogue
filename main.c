#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "battle.h"
#include "func.h"
#include "character.h"

int main(){
    srand(time(NULL));
    struct enemy Goblin = *declaration_enemy(blub.lvl);
    printf("%s", Goblin.name);
    battle(&blub, &Goblin);
    free(&Goblin);

    printf("\n\nHello World");

    return 0;
}