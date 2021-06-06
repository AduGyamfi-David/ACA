/* import required libraries*/
#include <stdio.h>
#include <math.h>

/*determines entire row of elements in pascals triangle*/
int pascalelements(int n, int k, int pr[]){

  int value = 0;

  if (k != 0){

    //for each call, reduce k
    value = pascalelements(n, k - 1, pr) * (n + 1 - k) / k;
    pr[k] = value;

  }
  else{ //BASE CASE

    value = 1;
    pr[k] = value;

  }

  return value; //Could also return pr[k]

}

int main(int argc, char *argv[]){

  int len = atoi(argv[1]) + 1;
  int *pascalrow[len + 1];
  int i;
  int fibsum = 1;
  printf("Fibsum = %d \n", fibsum);
  len -= 1;
  // printf("Suspected length of pascalrow = %d, Actual length of array = %d \n"
  //         , len, sizeof(pascalrow)/sizeof(pascalrow[0]));

  // printarrray(pascalrow);

  printarrray(pascalrow);
  printf(" \n");
  pascalelements(len, len, pascalrow);

  printarrray(pascalrow);

  printf(" \n");
  printf("The Fibonnnaci number for %d is = %d \n", len, calcfib(len, (len - 1) / 2), fibsum);
  return 0;
}

/*Determines a number in the fibonacci sequence
At a certain position in sequence
Position corresponds to row of Pascals*/
int calcfib(int n, int k, int* fibsum){

  int fibpascalrow[n - k];
  //only needs to be as long as elements it will hold

  if (k != 0){

    pascalelements(n - k - 1, n - k - 1, fibpascalrow);

    fibsum = calcfib(n, k - 1, fibsum) + fibpascalrow[k];

  }
  else{ //BASE CASE

    fibsum = 1;

  }
  return fibsum;
}

/*prints the entire contents of an array*/
void printarrray(int paramarray[]){

  int i;
  int len = sizeof(paramarray)/sizeof(paramarray[0]);
  //has to loop through entire length of array

  for (i = 0 ; i < len + 1; i ++){
    printf("Element %d = %d\n", i, paramarray[i]);
  }
}
