/**
 * Assignment: life
 * Name: Aimee He
 * PID: A16503864
 * Class: UCSD CSE30-SP21
 *
 */
#include "sim.h"

#define CIMP
extern void asm_doRow(belem *, belem *, size_t, size_t, size_t);

/**
 * gets x mod N (works for negative numbers as well! Use this instead of %)
 */
size_t getModVal(int x, size_t N){
     size_t adj = x/N;

     return((x+adj*N)%N);
}

/**
 * process one row of the board
 */
static void doRow(belem *dest, belem *src, size_t row, size_t rows, size_t cols){
  // TODO: 
  int initCell = cols * row;
  int upperRow = cols * ((row-1+rows)%rows);
  int lowerRow = cols * ((row+1)%rows);
  for (int i = 0; i< cols; i++){
    int numAlive = src[initCell+(i-1+cols) %cols] + src[initCell+(i+1) %cols]+ src[upperRow+(i-1+cols) %cols] + src[upperRow+i %cols] + src[upperRow+(i+1) %cols]+src[lowerRow+(i-1+cols) %cols] + src[lowerRow+i %cols] + src[lowerRow+(i+1) %cols];
    if(numAlive == 2){
      dest[initCell+i]=src[initCell+i];
      continue;
    }
    if(numAlive == 3){
      dest[initCell+i]=1;
    } 
    else{
      dest[initCell+i]=0;
    }
  }
}


/**
 * perform a simulation for "steps" generations
 *
 * for steps
 *   calculate the next board
 *   swap current and next
 */
void simLoop(boards_t *self, unsigned int steps){
  // TODO:
  for(int i=0; i<steps; i++){
    for(int j= 0; j<(*self).numRows;j++){
      doRow((*self).nextBuffer, (*self).nextBuffer, j, (*self).numRows, (*self).numCols);
    }
    swapBuffers(self);
  }
}
