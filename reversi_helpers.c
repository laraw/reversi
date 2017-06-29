/***********************************************************************
* CPT220 - Programming in C
* Study Period 2 2017 Assignment #1
* Full Name        : Lara Wilson
* Student Number   : s3342496
* Start up code provided by Paul Miller
***********************************************************************/

#include "reversi_helpers.h"
#define LSIZE 1024
#define EXTRACHARS 2

/**
 * required for correct buffer handling. If you detect buffer overflow
 * you should call this function. See the examples in
 * ~e70949/shared/examples especially AdvIO and BasicIO
 **/
void read_rest_of_line(void)
{
    int ch;
    while(ch = getc(stdin), ch != EOF && ch != '\n')
        ;
    clearerr(stdin);
}


BOOLEAN reversi_quit_game(char * input) {

    BOOLEAN terminate = FALSE;
    char textInput[LSIZE + EXTRACHARS];

    /* NEEDS TO CHECK IF INPUT IS EOF EG CTRL + D OR ENTER THEN QUIT THE GAME */
    if(strcmp(input,"\n") || strcmp(input,"\0")) {
        do {
            printf("really quit (y/n) ?");

            fgets(textInput, LSIZE + EXTRACHARS, stdin);

            if(strcmp(textInput,"y")) {
                terminate = TRUE;
            }
            else {
                printf("Exiting the program...");

            }
        } while(terminate == FALSE);
    }


}


