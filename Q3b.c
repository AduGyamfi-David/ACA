/* import required libraries*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Add a bit onto the string of bits
Returns string of bits (as char array)*/
char *addbit2string(char bit, char bitstring[]){

  //must first convert bit (as char) into a string
  char str_bit[2];
  str_bit[0] = bit;
  //add null character to form string
  str_bit[1] = '\0';


  //declare string for new string of bits
  //string are immutable, so declare new string
  //length of both strings + 1 for null char
  char *resultstring = (char *) calloc(strlen(str_bit)
                                 + strlen(bitstring)
                                 + 1, sizeof(char));

  //concatenate parameter strings into new strings
  strcat(resultstring, str_bit);
  strcat(resultstring, bitstring);

  return resultstring;
}

/*Validation for if string entered contains only 1s & 0s*/
int stringcheck(char instring[]){

  int flag = 0; //acts as boolean flag
  int i;

  for (i = 0; i < (sizeof(instring)/sizeof(char)); i ++){
    if ((instring[i] == 48) || (instring[i] == 49)){
    }
    else{
      flag = 1;
      return flag;
    }
  }
  return flag;
}

int main(int argc, char *argv[]){

  if (argc != 3){ //if more than 2 strings provided
    printf("\nError: 2 arguments required!\n");
    return 1;
  }
  else if ((sizeof(argv[1]) / sizeof(char) != 8)
           || (sizeof(argv[2]) / sizeof(char) != 8)){
    //if strings are not 8 bits
    printf("\nError: Must provide 8 bit strings!\n");
    return 1;
  }
  else if ((stringcheck(argv[1]) == 1) || (stringcheck(argv[2]) == 1)){
    //if strings don't contain only 1s & 0s
    //printf("%s, %d \n", instring, (sizeof(instring)/sizeof(char)));
    printf("\nError: Invalid bit strings!\n");
    return 1;
  }

  //declare variables
  char *firstbyte = argv[1];
  char *secbyte = argv[2];
  char *tempresult = "\0";
  char carry = 48;
  int i;

  //iterate through each string
  for (i = 7; i > -1; i --){

    //print current state, position & calculation
    printf("No of bits from LSB = %d. \n",
            "Carry bit = %c, current bits are: %c & %c \n", i,
            carry, firstbyte[i], secbyte[i]);
    printf("%c + %c + %c = ", firstbyte[i], secbyte[i], carry);

    switch((int)(firstbyte[i]) + (int)(secbyte[i])){
      //decide course of action based on state of bytes
      //if statements inc. to consider affect of carry
      case (96): //Case of 00
        if (carry == 48){
          printf("%c \n", 48);
          tempresult = addbit2string(48, tempresult);
        }
        else{
          printf("%c \n", 49);
          tempresult = addbit2string(49, tempresult);
          carry = 48;
        }
        printf("\n");
        break;

      case (97): //Case of 10 or 01
        if (carry == 48){
          printf("%c \n", 49);
          tempresult = addbit2string(49, tempresult);
        }
        else{
          printf("%c%c, CARRY! \n", 49, 48);
          tempresult = addbit2string(48, tempresult);
        }
        printf("\n");
        break;

      case (98): //Case of 11
        if (carry == 48){
          printf("%c%c, CARRY! \n", 49, 48);
          tempresult = addbit2string(48, tempresult);
          carry = 49;
        }
        else{
          printf("%c%c, CARRY! \n", 49, 49);
          tempresult = addbit2string(49, tempresult);
        }
        printf("\n");
      break;
    }
  }

  //declare new str for result
  char *result = addbit2string(carry, tempresult);
  printf("Result = %s \n", result);
  return 0;
}
