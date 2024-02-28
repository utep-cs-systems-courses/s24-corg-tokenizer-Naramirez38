#include <stdio.h>
#include <stdlib.h>

#include "tokenizer.h"
#include "history.h"

int space_char(char c){
  //if c = space return 1 if not 0
  if(c == '\t' || c == ' '|| c == '\0'){
    return 1; 
  }
  return 0;
}

int non_space_char(char c){
  if(!( (c == '\t') || ( c == ' ') || (c == '\0') ) ){
      return 1;
  }
  return 0;
}

char *token_start(char *str){
  while(non_space_char(*(str))){
    str++;
  }
  if(non_space_char(*(str++))){
    str++;
    return str;
  }
  return 0;
}
