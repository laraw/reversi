/***********************************************************************
* CPT220 - Programming in C
* Study Period 2 2017 Assignment #1 
* Full Name        : Larissa Wilson
* Student Number   : s3342496
* Start up code provided by Paul Miller
***********************************************************************/

#include "reversi_gameboard.h"
#include "reversi_player.h"

/** 
 * required to be implemented as part of the assignment. See the assignment
 * specification for further details
 **/
BOOLEAN reversi_rules_applymove(reversi_gameboard, struct reversi_player *,
    const struct reversi_coordinate*);

BOOLEAN reversi_rules_gameover(reversi_gameboard, 
    struct reversi_player *);

void reversi_player_calc_score(reversi_gameboard, struct reversi_player*);


