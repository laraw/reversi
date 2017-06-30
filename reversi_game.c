/***********************************************************************
* CPT220 - Programming in C
* Study Period 2 2017 Assignment #1
* Full Name        : Lara Wilson
* Student Number   : s3342496
* Start up code provided by Paul Miller
***********************************************************************/

#include "reversi_game.h"

/**
 * you need to swap the player pointers for the two pointers to pointers
 * passed in here. Note: this requires relatively little code but it does
 * require a good understanding of pointers. This is considered a HD
 * requirement so there may be some of you who cannot figure this one out.
 **/
static void swap_players(struct reversi_player ** lhs,
    struct reversi_player ** rhs)
{

    struct reversi_player* tmp_player;
    tmp_player = *lhs;
    *lhs = *rhs;
    *rhs = tmp_player;
}

/**
 * implements the game loop for the game. Please see the assignment
 * specification for the full discussion of the algorithm you need to
 * implement here.
 **/
void reversi_play_game(struct reversi_player players[])
{
    int player_count;
    struct reversi_player_pair result_pair;
    struct reversi_player * current_player, *other_player;
    reversi_gameboard board;

    /* Initialise the Game */
    BOOLEAN continue_game;

    continue_game = TRUE;
    int randomnumber;

    reversi_gameboard_init(board);
    printf("Welcome to Reversi \n");
    printf("--------------------- \n");

    reversi_player_init(current_player);
    reversi_player_init(other_player);

    /* Generate a random token for each player */
    current_player->token = reversi_random_number();
    other_player->token = current_player->token == CC_RED ? CC_BLUE : CC_RED;
    reversi_gameboard_display(board);




    BOOLEAN input_result;
    input_result = FALSE;
    /* Commence game - current player making first move */

    do{

        if(current_player->token == CC_BLUE) {
            reversi_player_move(current_player, board);
        }
        else {
            reversi_player_move(other_player, board);
        }

        swap_players(current_player, other_player);


    }
    while(continue_game);




}




