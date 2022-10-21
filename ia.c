#include "types.h"



// To be modified.

void inputIA (color c, int size, color** board, int* x, int* y) {
    for (int i = 0; i < size; i++)
      for (int j = 0; j <size; j++)
	if (board[i][j] == GREY) {
	  *x = i ;
	  *y = j ;
	  i = size ;
	  j = size ;
	}
}



