#include <stdio.h>  // for printf
#include <stdlib.h> // for rand and srand
#include <time.h>   // for time and clock

// PLEASE DON'T CHANGE THESE DEFINES!
#define ROWS 5000
#define COLS 5000
#define NUMOFROUNDS 7

long addition(int **table) {
  long sum = 0;
  for (int i = 0; i < ROWS; i++) { // Change the order of loops
    for (int j = 0; j < COLS; j++) {
      sum += (long)table[i][j];
    }
  }

  return sum;
}
void printTable(int **table) {
  for (int i = 0; i < ROWS; i++) { 
    for (int j = 0; j < COLS; j++) {
      printf("%d ", table[i][j]);
    }
    printf("\n");
    
  }
  
}

// PLEASE DON'T CHANGE THIS FUNCTION!
int **createTable() {
  int **table = (int **)malloc(ROWS * sizeof(int *));
  for (int i = 0; i < ROWS; i++) {
    table[i] = (int *)malloc(COLS * sizeof(int));
    for (int j = 0; j < COLS; j++) {
      table[i][j] = (rand() % 100) + 1;
    }
  }
  return table;
}

void deleteTable(int **table) {
  for (int i = 0; i < ROWS; i++) {
    free(table[i]);
  }
  free(table);
}

int main() {
  srand((unsigned int)time(0));

  int **table = createTable();
  // printTable(table);

  clock_t start_time = clock(); // start the timer

  long sum = 0;
  for (int i = 0; i < NUMOFROUNDS; i++) {
    sum = addition(table);
  }

  clock_t end_time = clock(); // end the timer
  double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

  printf("sum is %ld\n", sum);
  printf("elapsed time: %f seconds\n", elapsed_time);

  deleteTable(table);

  return 0;
}