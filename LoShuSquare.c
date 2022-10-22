// git remote add origin https://github.com/justFreds/Lo_Shu_Magic_Square.git
// git branch -M main
// git push -u origin main

//LO SHU MAGIC SQUARE
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SQUARE_SIZE 3
#define LO_SHU_NUMBER 15

//PROTOTYPES
static bool isLoshu(int square[][SQUARE_SIZE]);
static void createRandomSquare(void); 

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
        printf("Square #1 is a Lo-Shu Magic Square!\n");
    }
    else {
        printf("Square #1 is NOT a Lo-Shu Magic Square!\n");
    }
    if(isLoshu(genericSquare)) {
        printf("Square #2 is a Lo-Shu Magic Square!\n");
    }
    else {
        printf("Square #2 is NOT a Lo-Shu Magic Square!\n");
    }
    //createSquare()
    createRandomSquare();
    //isLoShu()    
    //printSquare()


    return EXIT_SUCCESS;
}

//FUNCTIONS
static bool isLoshu(int square[][SQUARE_SIZE]) {
    int sumRows = 0, sumColumns = 0, sumDiagonal_1 = 0, sumDiagonal_2 = 0;
    //rows
    for(int row = 0; row < SQUARE_SIZE; row++) {
        for(int column = 0; column < SQUARE_SIZE; column++) {
            sumRows += square[row][column];
        }
        if(sumRows == 15)
            return true;
    }
    //columns
    for(int column = 0; column < SQUARE_SIZE; column++) {
        for(int row = 0; row < SQUARE_SIZE; row++) { 
            sumColumns += square[row][column];
        }
        if(sumColumns == 15)
            return true;
    }
    //DIAGONAL 1
        // [x][][]   [0][0]
        // [][x][]   [1][1]
        // [][][x]   [2][2]
    for(int i = 0; i < SQUARE_SIZE; i++) {
        sumDiagonal_1 += square[i][i];
        if(sumDiagonal_1 == 15)
            return true;
    }

    //DIAGONAL 2
        // [][][x]   [0][2]
        // [][x][]   [1][1]
        // [x][][]   [2][0]
    int column = (SQUARE_SIZE - 1); // 3 - 1 = 2
    for (int row = 0; row < SQUARE_SIZE; row++)
    {
        sumDiagonal_2 += square[row][column];
        column--;
        if(sumDiagonal_2 == 15) {
            return true;
        }
    }
    return false;
}

//FUNCITON createSquare()
static void createRandomSquare(void) {

    int tempArray[9] = {1,2,3,4,5,6,7,8,9};
    int swapValue;
    int randSquare[SQUARE_SIZE][SQUARE_SIZE] = {    
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    srand(time(NULL));
    for(int i = 0; i < 9; i++) {
        int randNum = (rand() % (i + 1));
        swapValue = tempArray[i];
        tempArray[i] = tempArray[randNum];
        tempArray[randNum] = swapValue;
    }
    int k = 0;
    for(int i = 0; i < SQUARE_SIZE; i++) {
        for(int j = 0; j < SQUARE_SIZE; j++) {
            randSquare[i][j] = tempArray[k];
            printf("randSquare[%d][%d] %d\n", i, j, randSquare[i][j]);
            k++;
        }
    }
}
        
        //FUNCITON printSquare([][])
            //Print two things:
            // a.	The total number of squares generated and tested before success, the count.
            // b.	Print the square and show the placement of values in the following format:
            // [a b c]
            // [d e f]
            // [g h i]
