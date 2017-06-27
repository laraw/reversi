/***********************************************************************
* CPT220 - Programming in C
* Study Period 2 2017 Assignment #1
* Full Name        : Larissa Wilson
* Student Number   : s3342496
* Start up code provided by Paul Miller
***********************************************************************/

#include "reversi_player.h"
#include "reversi_gamerules.h"

/**
 * Initialise the player's data. You should prompt the user for their name,
 * set their token to CC_EMPTY and their score to 0.
 **/
enum input_result reversi_player_init(struct reversi_player* curplayer)
{
    int success = FALSE;
    char name[REVERSI_NAMELEN];

    do {
        printf("Enter your player name: \n");
        fgets(name,REVERSI_NAMELEN,stdin);

        if(name[strlen(name) - 1] != '\n') {
            printf("Input was too long.\n");
            read_rest_of_line();
        }
        else {
            success = TRUE;
        }

    } while (success == FALSE);


    name[strlen(name) - 1] = '\0';
    strcpy(curplayer->name,name);
    curplayer->score = 1;
    curplayer->token = CC_EMPTY;
    return IR_SUCCESS;
    /* return IR_FAILURE */
    /*
        printf("Your name is: %s \n", curplayer->name);
        printf("Your current score is: %i", curplayer->score);
        printf("Your current colour is: %s", curplayer->token);
    */
}



/**
 * Implements the player taking a move in the game. It starts by printing
 * out the player's score (which you will need to calculate by calling
 * the correct function) and their colour. You should then read in the
 * move coordinates and validate them (that there is two ints separated by
 * a comma and no other input on the line). Then you should try to apply
 * the move by calling the appropriate function in the game rules module.
 **/
enum input_result reversi_player_move(struct reversi_player* curplayer,
    reversi_gameboard game_board)
{
    /* CALCULATE CURRENT SCORE - TBI */

    /* PRINT OUT PLAYER INFORMATION */
    print_player_details(curplayer);


    int success = FALSE;
    char coordinates[3];


    /* PROMPT FOR COORDINATES AND VALIDATE INPUT IS NOT TOO LONG AND IS CORRECT FORMAT*/
    do {
        printf("Please enter a move as a comma separated coordinate pair: ");
        fgets(coordinates,3,stdin);

        if(strlen(coordinates) > 3) {
            printf("Input was too long.\n");
            read_rest_of_line();
        }
        else {
            success = TRUE;
        }

    } while (success == FALSE);

    /* TOKENIZE THE COORDINATES ONCE VALIDATED*/


    return IR_SUCCESS;
}

/**
 * Returns the token colour based on the token assigned
**/

const char * get_token_colour(struct reversi_player* curplayer) {
    if(curplayer->token == CC_RED) {
        return ANSI_COLOR_RED "red" ANSI_COLOR_RESET;
    }
    else {
        return ANSI_COLOR_BLUE "blue" ANSI_COLOR_RESET;
    }

}

void print_player_details(struct reversi_player* curplayer) {
    printf("It is %s's turn and their current colour is %s \n", curplayer->name, get_token_colour(curplayer));
    printf("Their score is currently: %i \n", curplayer->score);


}
