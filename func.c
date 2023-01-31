#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "character.h"
#include "items.h"

int random(int min, int max){
    return ((rand() % (max - min + 1)) + min);
}


// Eine Liste an Namen wird erstellt
char *Name[] = { // zurzeit 10 Namen
    "orc", "goblin", "vapire", "mummy", "giant spider", "giant", "golem", "zombie", "werewolf", "skeleton"
};

// Die Länge der Liste wird zurückgegeben, damit das weiterverwenden leicht ist
int name_list = sizeof(Name) / sizeof(Name[0]);

/*
struct enemy Goblin = *declaration_enemy(player.lvl);
battle(&player, &Goblin);
free(&Goblin);
Org, 
*/

struct enemy* declaration_enemy(int level){
    struct enemy* dyn_enemy = (struct enemy*) malloc(sizeof(struct enemy));

    strcpy(dyn_enemy->name, Name[random(0, (name_list - 1))]);
    dyn_enemy->hp = 25 + (5 * level);
    dyn_enemy->atk = 10 + (2 * level);
    dyn_enemy->def = 10 + (2 * level);
    dyn_enemy->spe = 10 + level;

    return dyn_enemy;
}

/*
Es fehlen noch Texte
sollte, sonst fertig sein -> zum austesten
XD mein Mathe sollte auch richtig sein, bevor das hier durchgeht, also bei allen funcs den min schaden auf 0 setzen, 
damit man sich nicht durch angriffe heilen kann
*/

void fight(struct player *character1, struct enemy *character2, int choice){
    switch(choice){
        case(1): // attack + attack
            printf("\nYou and the enemy attack eachother");
            character2->hp -= (character1->atk - character2->def);
            break;

        case(2): // attack + defence
            printf("\nThe enemy deflects your attack back at you");
            character1->hp -= character2->def;
            break;

        case(3): // defence + attack
            printf("\nYou deflect the attack");
            character2->hp -= character1->def;
            break;
        
        case(4): // defence + defence
            printf("\nNothing happens");
            break;
        
        case(5): // item + attack
            printf("\n%s attacks you", character2->name);
            character1->hp -= (character2->atk - character1->def);
            break;
        
        case(6): // item + defence
            printf("\nThe enemy does nothing");
            break;
        
        case(7): // flee + attack
            if(random(0, character2->spe) < (character1->spe - character2->spe)){
                printf("\nYou were able to flee from the fight");
            }
            else{
                printf("\nYou were not able to flee and the enemy attacked you");
                character1->hp -= (character2->atk - character1->def); 
            }
            break;

        case(8): // flee + defence
            if(random(0, character2->spe) < (character1->spe - character2->spe)){
                printf("\nYou were able to flee from the fight");
            }
            else{
                printf("\nYou were not able to flee and the enemy just starred at you in disbelief");
            }
            break;
    
        default:
            break;
    }
}