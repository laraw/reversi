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

    /* MY CODE*/
    int failure = FALSE;
    int randomnumber;

    reversi_gameboard_init(board);
    printf("Welcome to Reversi \n");
    /*reversi_player_init(current_player);
    reversi_player_init(other_player);*/
    reversi_player_init(current_player);
    reversi_player_init(other_player);
    reversi_gameboard_display(board);

    /* Generate a random token for the player */

    randomnumber = reversi_random_number();
    current_player->token = randomnumber == 1 ? CC_RED : CC_BLUE;
    other_player->token = current_player->token == CC_RED ? CC_BLUE : CC_RED;

    reversi_player_move(current_player, board);


}

int reversi_random_number() {
    int randomnumber;
    time_t t;
    srand((unsigned) time(&t));
    randomnumber = rand() % 2;
    return randomnumber;
}

