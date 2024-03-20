#include <stdio.h>
#include <stdlib.h>

#include "tokenizer.h"
#include "history.h"

int space_char(char c){
  //if c = space return 1 if not 0
  if(c == '\t' || c == ' '){
    return 1; 
  }
  return 0;
}

int zero_char(char c){
  if (c =='/0'){
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  if (!(space_char(c)) && (!(zero_char(c)))){
    return 1;
  }
  return 0;
}			       
char *token_start(char *str){
  char *begin = str;
  same_word:
  if(non_space_char(*(str))){
    str++;
  } else if (space_char(*(str))){
    str++;
    goto next_word;
  } else{
    return begin;
  }
  goto same_word;
  next_word:
  if(zero_char(*(str))){
    return begin;
  }
  else if(non_space_char(*(str))){
    return str;
  } else {
    goto next_word;
  }
  return 0;
}
char *token_terminator(char *token){
  return 0;
 }
