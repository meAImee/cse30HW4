/**
 * Assignment: life
 * Name :TODO
 * PID: TODO
 * Class: UCSD CSE30-SP21
 *
 */
#include "cse30life.h"
#include "board.h"


/**
 * create a new board
 *
 * - malloc a boards structure
 * - set the generation to 0
 * - open the file (if it doesn't exist, return a NULL pointer
 * - read the first line which is the number of rows
 * - read the second line which is the number of cols
 * - set the # of rows and # of cols in the boards structure
 * - malloc bufferA and bufferB 
 * - Set currentBuffer and nextBuffer
 * - clear both board buffers
 * - read the file until done.  each row contains a row and a columns separted by
 *   white space
 *     for each line, set the cell in the current buffer
 * - close the file
 * - return the boards pointer if successfull or NULL ptr otherwise
 */
boards_t * createBoard(char *initFileName){
  // TODO: 
  boards_t *newBoards;
  int gen = 0;
  FILE *fp = fopen(initFileName, "r");
  int numRows;
  int numCols;
  if (fp==NULL){
    return NULL;
  }
  fscanf(initFileName, "%[^\n]", numRows);
  (*newBoards).numRows=numRows;
  fscanf(initFileName, "%[^\n]", numCols);
  (*newBoards).numCols=numCols;
  belem *bufferA = (belem *)malloc(numRows * numCols);
  belem *bufferB = (belem *)malloc(numRows * numCols);
  belem *currentBuffer;
  belem *nextBuffer;
  for (int i=0;i <numCols*numRows; i++){
    currentBuffer[i]=0;
    nextBuffer[i]=0;
  }
  int char1;
  int char2;
  while(fscanf(initFileName, "%d %d", char1, char2)>0){
    int k = numCols*char1+char2;
    currentBuffer[k] = 1;

  }
  fclose(fp);
  return newBoards;

}



/**
 * delete a board
 */
void deleteBoard(boards_t **bptrPtr){
  // TODO:
  free(*bptrPtr);
  *bptrPtr == NULL;
}

/**
 * set all the belems in both buffers to 0
 */
void clearBoards(boards_t *self){
  // TODO:
  for (int i = 0; i<  (*self).numCols*(*self).numRows; i++){
    (*self).currentBuffer[i]=0;
    (*self).bufferB[i]=0;
  }

}

/**
 * swap the current and next buffers
 */
void swapBuffers(boards_t *self){
  // TODO:
  belem temp;
  temp = (*self).currentBuffer;
  (*self).currentBuffer = (*self).nextBuffer;
  (*self).nextBuffer = temp;

}


/**
 * get a cell index
 */
size_t getIndex(size_t numCols, size_t row, size_t col){
  // TODO:
  int index = numCols*row + col ;
}
  
