#include <stdio.h>

#include "character.h"
#include "func.h"

/*
Hp werden richtig angezeigt, battle.c und character.c wurden verändert
Sollte fertig sein, muss aber noch ausgetestet werden
*/

void battle(struct player *player, struct enemy *enemy){
    int choice;

    printf("\nPlayer HP: %d \nEnemy HP: %d",player->hp, enemy->hp);

    while(player->hp > 0 && enemy->hp > 0){
        printf("\n(1) Angreifen \n(2) Blocken \n(3) Gegenstand benutzen \n(4) Fliehen\n");
        scanf(" %d", &choice);

        switch (choice){
            case(1):
                attack(player, enemy);
                break;
            case(2):
                defend(player, enemy);
                break;
            case(3):
               use_item(player, enemy);
               break;
            case(4):
                flee(player, enemy);
                break;
            default:
                exit(EXIT_FAILURE);
        }
        
        printf("\nPlayer HP: %d \nEnemy HP: %d",player->hp, enemy->hp);
    }
}

void attack(struct player *player, struct enemy *enemy){
    printf("\nYou attack the enemy");

    enemy_turn(player, enemy, 1);
};

void defend(struct player *player, struct enemy *enemy){
    printf("\nYou try to block");

    enemy_turn(player, enemy, 2);
};

void use_item(struct player *player, struct enemy *enemy){
    printf("\nYou use an item");

    enemy_turn(player, enemy, 3);
};

void flee(struct player *player, struct enemy *enemy){
    printf("\nYou try to flee");

    enemy_turn(player, enemy, 4);
};

void enemy_turn(struct player *player, struct enemy *enemy, int player_move){
    int temp = random(1, 2);

    switch(player_move){
        case 1:// Spieler greift an
            if(temp == 1){// Gegner greift an
                fight(player, enemy, 1);
            }
            else{// Gegner blockiert
                fight(player, enemy, 2);
            }
            break;
        case 2:// Spieler blockiert
            if(temp == 1){// Gegner greift an
                fight(player, enemy, 3);
            }
            else{// Gegner blockiert
                fight(player, enemy, 4);
            }
            break;
        case 3:// Spieler benutzt Gegenstand
            if(temp == 1){// Gegner greift an
                fight(player, enemy, 5);
            }
            else{// Gegner blockt
                fight(player, enemy, 6);
            }
            break;
        case 4:// Spieler flieht
            if(player->spe > enemy->spe){// Gegner greift an
                fight(player, enemy, 7);
            }
            else{// Gegner blockt
                fight(player, enemy, 8);
            }
            break;
        default:
            exit(EXIT_FAILURE);
    }
};