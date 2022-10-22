// git remote add origin https://github.com/justFreds/Lo_Shu_Magic_Square.git
// git branch -M main
// git push -u origin main

//LO SHU MAGIC SQUARE
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define SQUARE_SIZE 3
#define LO_SHU_NUMBER 15

//PROTOTYPES
static bool isLoshu(int square[][SQUARE_SIZE]);
static int sumOfRows(int square[][SQUARE_SIZE]);
static int sumOfCols(int square[][SQUARE_SIZE]);
static int sumOfDiag1(int square[][SQUARE_SIZE]);
static int sumOfDiag2(int square[][SQUARE_SIZE]);
static void createRandomSquare(int (*squarePtr)[SQUARE_SIZE][SQUARE_SIZE]);
// static void printSquare(int *square[SQUARE_SIZE][SQUARE_SIZE]); 

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
    if(isLoshu(LoShuSquare)) {
        printf("Square #1 is a Lo-Shu Magic Square!\n\n");
    }
    else {
        printf("Square #1 is NOT a Lo-Shu Magic Square!\n\n");
    }
    if(isLoshu(genericSquare)) {
        printf("Square #2 is a Lo-Shu Magic Square!\n\n");
    }
    else {
        printf("Square #2 is NOT a Lo-Shu Magic Square!\n\n");
    }

    //createSquare()
    int randSquare[SQUARE_SIZE][SQUARE_SIZE];
    memset(randSquare, 0, sizeof(randSquare));
    createRandomSquare(&randSquare);

    return EXIT_SUCCESS;
}

//FUNCTIONS
static int sumOfRows(int square[][SQUARE_SIZE]) {
    int total;
    for(int row = 0; row < SQUARE_SIZE; row++) {
        total = 0;
        for(int column = 0; column < SQUARE_SIZE; column++) {
            total += square[row][column];            
        }     
    }
    return total;
}
static int sumOfCols(int square[][SQUARE_SIZE]) {
    //columns
    int total;
    for(int column = 0; column < SQUARE_SIZE; column++) {
        total = 0;
        for(int row = 0; row < SQUARE_SIZE; row++) { 
            total += square[row][column];
        }
    }
    return total;
}
static int sumOfDiag1(int square[][SQUARE_SIZE]) {
    //DIAGONAL 1
        // [x][][]   [0][0]
        // [][x][]   [1][1]
        // [][][x]   [2][2]
    int total = 0;
    for(int i = 0; i < SQUARE_SIZE; i++) {
        total += square[i][i];
    }
    return total;
}
static int sumOfDiag2(int square[][SQUARE_SIZE]) {
    //DIAGONAL 2
        // [][][x]   [0][2]
        // [][x][]   [1][1]
        // [x][][]   [2][0]    
    int total = 0;
    for(int row = 0, column = (SQUARE_SIZE - 1); row < SQUARE_SIZE; row++, column--) {
         total += square[row][column];
    }
    return total;    
}
static bool isLoshu(int square[][SQUARE_SIZE]) {
    if(sumOfRows(square)    ==      15      &&
       sumOfCols(square)    ==      15      &&
       sumOfDiag1(square)   ==      15      &&
       sumOfDiag2(square)   ==      15
       )
       return true;
    else
        return false;


    // return true ? sumRows == 15 && sumColumns == 15 && sumDiagonal_1 == 15 && sumDiagonal_2 == 15 : false;
}

//FUNCITON createSquare()
static void createRandomSquare(int (*squarePtr)[SQUARE_SIZE][SQUARE_SIZE]) {

    int tempArray[9] = {1,2,3,4,5,6,7,8,9};
    int swapValue, counter = 0;

    srand(time(NULL));
    do
    {   
        //SHUFFLING VALUES OF TEMP ARRAY
        for(int i = 0; i < 9; i++) {
            int randNum = (rand() % (i + 1));
            swapValue = tempArray[i];
            tempArray[i] = tempArray[randNum];
            tempArray[randNum] = swapValue;
        }
        //POPULATING SHUFFLED ARRAY INTO 2D
        int k = 0;
        for(int i = 0; i < SQUARE_SIZE; i++){
            for(int j = 0; j < SQUARE_SIZE; j++) {
                *squarePtr[i][j] = tempArray[k++];
            }
        }
        counter++;
    } while (!isLoshu(*squarePtr));
    printf("Total number of attempts: %d\n", counter);
    for(int i = 0; i < SQUARE_SIZE; i++) {
        for(int j = 0; j < SQUARE_SIZE; j++) {
            if(j == 0)
                printf("[ ");
            printf("%d ", *squarePtr[i][j]);            
        }
        printf("]\n");
    }
    printf("\n");
}