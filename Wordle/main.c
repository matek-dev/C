#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordle.h"
#include <stdbool.h>
#include <ctype.h>

// Function to check if value is in array --> Bool (0, 1)
bool includes(char *array, char value){
    if (array == NULL){
        return 0;
    }
    for (int i=0; array[i]!=0; i++){
        if (array[i]==value){
        return 1;
        }
    }
    return 0;
}

// char lower(char *array){
//     for (int i=0; array[i]; i++){
//         array[i] = tolower(array[i]);
//     }
//     return array;
// }

int main()
{
    // generate the random word 
    char word[6];
    genword(word);
    // char word[] = "chart";

    // Initialize varilables:
    // Alphabet to itterate through
    char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 0};
    // Pointers to arrays that keep tabs on the letters guessed
    char *red = NULL;
    char *blue = NULL;
    char *yellow = NULL;
    // Initialize iteration count to reallocate memory to pointers and append guessed letter
    int r = 1;
    int b = 1;
    int y = 1;
    // Initialize numtries
    int numtries = 1;

    while (numtries <= 6) {
        //get the input guess
        printf("Enter guess: ");
        char guess[10];
        fgets(guess, 10, stdin);

        // Overwrites the default '\n' newline character to NULL terminator
        guess[5]=0;

        // guess = lower(guess)
        
        // Compares guess to word and completes game if correct
        if (strcmp(guess, word)==0)
        {
            printf("You guessed the word in %d tries\n", numtries);
            exit(1);
        }
        // Itereates through guess and prints out the letter Red if in
        // the correct positon, Blue if in the wrong position, and 
        // white if not in the word. 
        for (int i = 0; i<5; i++)
        {
            if (guess[i]==word[i]){
                print_red(guess[i]);
                // TYP: Reallocates memory to array of one char size bigger
                // Inserts letter to array
                red = realloc(red, r*sizeof(char));                
                red[r-1] = guess[i];
                r++;
            }
            else if (includes(word, guess[i])){
                print_blue(guess[i]);            
                blue = realloc(blue, b*sizeof(char));
                blue[b-1] = guess[i];
                b++;
            }
            else {
                printf("%c", guess[i]);
                yellow = realloc(yellow, y*sizeof(char));
                yellow[y-1] = guess[i];
                y++;
            }
        }
        printf("\n");
        // Debugging print statements to see functionality of arrays
        // printf("red: %s\n", red);
        // printf("blue: %s\n", blue);
        // printf("yellow: %s\n", yellow);

        // Iterates through alphabet and checks if letter is in Red, Blue, 
        // or Yellow collection and prints out in signigicant color
        for (int i = 0; alphabet[i]!=0; i++){
            if (includes(red, tolower(alphabet[i]))){
                print_red(alphabet[i]);
                printf(" ");
            }
            else if (includes(blue, tolower(alphabet[i]))){
                print_blue(alphabet[i]);
                printf(" ");
            }
            else if (includes(yellow, tolower(alphabet[i]))){
                print_yellow(alphabet[i]);
                printf(" ");
            }
            else {
                printf("%c", alphabet[i]);
                printf(" ");
            }
        }
        printf("\n");

        numtries++;
    }
    printf("Sorry you couldn't guess the word %s in 6 tries\n", word);
}