// git remote add origin https://github.com/justFreds/Lo_Shu_Magic_Square.git
// git branch -M main
// git push -u origin main

//LO SHU MAGIC SQUARE
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define SQUARE_SIZE 3

//PROTOTYPES
int isLoshu(int square[SQUARE_SIZE][SQUARE_SIZE]);
void printSquare(int square[SQUARE_SIZE][SQUARE_SIZE]);
static void createRandomSquare(int square[][SQUARE_SIZE]);



//MAIN
int main() {
    //CREATE TWO 2D ARRAYS
    //LO SHU SQUARE
    int LoShuSquare[][SQUARE_SIZE] = { 
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 6} 
    };
    //NOT LO SHU SQUARE
    int genericSquare[][SQUARE_SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        (7, 8, 9)
    };

    //PASS ARRAYS INTO isLoShu([][]);
    if(isLoshu(LoShuSquare) == 1) {
        printf("Square #1 is a Lo-Shu Magic Square!\n\n");
    }
    else {
        printf("Square #1 is NOT a Lo-Shu Magic Square!\n\n");
    }
    printSquare(LoShuSquare);

    if(isLoshu(genericSquare) == 1) {
        printf("Square #2 is a Lo-Shu Magic Square!\n\n");
    }
    else {
        printf("Square #2 is NOT a Lo-Shu Magic Square!\n\n");
    }
    printSquare(genericSquare);

    
    int found = 0;
    int counter = 0;
    while(!found) {
        createRandomSquare(genericSquare);
        counter++;
        if(isLoshu(genericSquare) == 1) found = 1;
    }

    printf("Total number of attempts: %d\n", counter);
    printSquare(genericSquare);

    return EXIT_SUCCESS;
}

//FUNCTIONS
int isLoshu(int arr[SQUARE_SIZE][SQUARE_SIZE]) {
    int magic = 1;
    // iterate through columns
    for(int i = 0; i < SQUARE_SIZE; i++) {
        int isum = 0;
        for (int j = 0; j < SQUARE_SIZE; j++) {
            isum += arr[i][j];
        }
        if(isum != 15) magic = 0;
    }
    // iterate through rows
    for(int j = 0; j < SQUARE_SIZE; j++) {
        int jsum = 0;
        for (int i = 0; i < SQUARE_SIZE; i++) {
            jsum += arr[i][j];
        }
        if(jsum != 15) magic = 0;
    }
    // iterate through diagonals
    if(arr[0][0] + arr[1][1] + arr[2][2] != 15) magic = 0;
    if(arr[2][0] + arr[1][1] + arr[0][2] != 15) magic = 0;
    //return
    return magic;
} 

//FUNCITON createSquare()
static void createRandomSquare(int square[][SQUARE_SIZE]) {

    int tempArray[9] = {1,2,3,4,5,6,7,8,9};
    int swapValue;

    srand(time(NULL));

    //SHUFFLING VALUES OF TEMP ARRAY
    for(int i = 8; i > 0; i--) {
        int randNum = (rand() % (i + 1));
        swapValue = tempArray[i];
        tempArray[i] = tempArray[randNum];
        tempArray[randNum] = swapValue;
    }
    //POPULATING SHUFFLED ARRAY INTO 2D
    int k = 0;
    for(int i = 0; i < SQUARE_SIZE; i++){
        for(int j = 0; j < SQUARE_SIZE; j++) {
            square[i][j] = tempArray[k++];
        }
    }
}

void printSquare(int square[SQUARE_SIZE][SQUARE_SIZE])
{
    for(int i = 0; i < SQUARE_SIZE; i++) {
        for(int j = 0; j < SQUARE_SIZE; j++) {
            if(j == 0)
                printf("[ ");
            printf("%d ", square[i][j]);            
        }
        printf("]\n");
    }
    printf("\n");

}
