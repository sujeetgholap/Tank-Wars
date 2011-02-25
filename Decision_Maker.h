#ifndef DECISION_MAKER_H
#define DECISION_MAKER_H

#include<iostream>

#include "Info.h"
#include "Map.h"
#include "Misc_Classes.h"
/*
 * Various Strategies    -  Aggressive, Defensive, Greedy, Customised
 * Various Action plans  -  Pick up gold, attack enemy tank,
 *                          attack enemy falcon, defend your falcon
 */
class DecisionMaker
{
    public:
    int weightage_table[4][4];
    int difficulty_table[4];
    Info my_info;

    void set_weightage_table(int, int, int, int, int );
    void set_diffculty_table(int, int, int, int);

    int calculate_best_action_plan(int );
    int find_the_maximum(float*);

    Move go_to_gold_move();
    Move attack_enemy_falcon_move();
    Move attack_enemy_tank_move();
    Move defend_my_falcon_move();

    Move return_best_move(int );

    Move get_player_move(int);
}


#endif
