/***********************************************************************
 * CPT220 - Programming in C
 * Study Period 2 2017 Assignment #1
 * Full Name        : Larissa Wilson
 * Student Number   : s3342496
 * Start up code provided by Paul Miller
 ***********************************************************************/

#include "reversi_player.h"
#include "reversi_gamerules.h"
#define LSIZE 1024
#define EXTRACHARS 2
#define MAX_COORDINATES_LENGTH 3
#define MIN_COORDINATES_LENGTH 3
#define MIN_COORDINATE 1
#define MAX_COORDINATE 8
#define DELIM " ,"

/**
 * Initialise the player's data. You should prompt the user for their name,
 * set their token to CC_EMPTY and their score to 0.
 **/
enum input_result reversi_player_init(struct reversi_player * curplayer) {
    int success = FALSE;
    char name[REVERSI_NAMELEN + 1];

    do {
        printf("Enter your player name: \n");
        fgets(name, REVERSI_NAMELEN + 1, stdin);

        if(name[0] == '\n') {
            printf("Error - Input was empty. ");
            read_rest_of_line();
        }
        else if (name[strlen(name) - 1] != '\n') {
            printf("Error - Input was too long. Input should be less than %i.\n", REVERSI_NAMELEN);
            read_rest_of_line();
        } else {
            success = TRUE;
        }

    } while (success == FALSE);

    /* Overwrite the \n character with \0. */
    name[strlen(name) - 1] = '\0';
    strncpy(curplayer->name, name,strlen(name));
    curplayer->score = 1;



    return IR_SUCCESS;

}

/**
 * Implements the player taking a move in the game. It starts by printing
 * out the player's score (which you will need to calculate by calling
 * the correct function) and their colour. You should then read in the
 * move coordinates and validate them (that there is two ints separated by
 * a comma and no other input on the line). Then you should try to apply
 * the move by calling the appropriate function in the game rules module.
 **/
enum input_result reversi_player_move(struct reversi_player * curplayer,
    reversi_gameboard game_board) {

    /* CALCULATE CURRENT SCORE */
    reversi_player_calc_score(game_board, curplayer);

    /* PRINT OUT PLAYER INFORMATION */
    print_player_details(curplayer);

    /* DECLARE LOCAL VARIABLES */
    BOOLEAN success;
    success = FALSE;
    char textInput[LSIZE + EXTRACHARS];
    int x,y;

    /* PROMPT FOR COORDINATES AND VALIDATE INPUT IS NOT TOO LONG AND IS CORRECT FORMAT*/
    do {
        printf("Please enter a move as a comma separated coordinate pair: ");

        fgets(textInput, LSIZE + EXTRACHARS, stdin);
        textInput[strlen(textInput) - 1] = '\0';

        if (strlen(textInput) > MAX_COORDINATES_LENGTH || strlen(textInput) < MIN_COORDINATES_LENGTH) {
            printf("Error - Input was too short or too long. Minimum input is %i, maximum is %i \n",
                MIN_COORDINATES_LENGTH, MAX_COORDINATES_LENGTH);
            read_rest_of_line();

        } else if (textInput[0] == '\n') {
            printf("Error - Input was empty.");
            read_rest_of_line();

        } else {
            if (tokenize_input(textInput, &x, &y) == IR_SUCCESS) {

                /* PASS THE COORDINATES X & Y INTO THE APPLY MOVE */
                /* SET reversi_coordinate->y = y; reversi_coordinate->x -> x) */
                struct reversi_coordinate coordinates;
                coordinates.y = y;
                coordinates.x = x;
                reversi_rules_applymove(game_board, curplayer, &coordinates);
                return IR_SUCCESS;
            }

        }

    } while (success == FALSE);


    return IR_SUCCESS;
}

/**
 * Returns the token colour based on the token assigned
 **/

const char * get_token_colour(struct reversi_player * curplayer) {
    if (curplayer->token == CC_RED) {
        return ANSI_COLOR_RED "red"
        ANSI_COLOR_RESET;
    } else {
        return ANSI_COLOR_BLUE "blue"
        ANSI_COLOR_RESET;
    }

}

void print_player_details(struct reversi_player * curplayer) {
    printf("It is %s's turn and their current colour is %s \n", curplayer->name, get_token_colour(curplayer));
    printf("Their score is currently: %i \n", curplayer->score);
}

enum input_result tokenize_input(char * input, int * x, int * y) {
    int i = 0;
    char * token;
    int tempInteger = 0;
    char * tmpPtr;
    int cnt_coordinates = 1;

    token = strtok(input, DELIM);

    while (token != NULL) {

        i++;

        if (strlen(token) > 1) {
            printf("Error - Input was invalid - ensure your coordinates include a comma separator");
            read_rest_of_line();
            return IR_FAILURE;
        } else {

            tempInteger = (int) strtol(token, & tmpPtr, 10);

            if ((tempInteger >= MIN_COORDINATE || tempInteger <= MAX_COORDINATE)) {
                if (cnt_coordinates == 1) {
                    *x = tempInteger;
                    cnt_coordinates++;

                }
                if (cnt_coordinates == 2) {
                    *y = tempInteger;

                }

            } else {
                printf("Error - Coordinates are out of range.");
                read_rest_of_line();
                return IR_FAILURE;

            }

        }
        token = strtok(NULL, DELIM);

    }

    return IR_SUCCESS;
}
