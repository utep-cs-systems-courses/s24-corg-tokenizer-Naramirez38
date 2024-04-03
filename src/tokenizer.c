#include <stdio.h>

#include <stdlib.h>



#include "tokenizer.h"

#include "history.h"

//changing this so it commits

int space_char(char c){

  //if c = space return 1 if not 0

  if(c == '\t' || c == ' '){

    return 1;

  }

  return 0;

}



int zero_char(char c){

  if (c =='\0'){

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

char *token_start_better_version(char *str){
  char *begin = str;
  
  //This portion of code handles consecutive characters (a-z) until there is a space char or '\0'
 same_word:  
  if(non_space_char(*(str))){
    str++;
  } else if (space_char(*(str))){
    str++;
    goto next_word; //go to next goto with next postion in memory
  } else{
    //return original pointer from beginning
    return begin;
  }
  goto same_word;
 next_word:
  if(zero_char(*(str))){ // checks if current char is '\0'
    return begin; //rtns start of prev token
  }
  else if(non_space_char(*(str))){ //checks if current char is char (a-z) rtn our pointer 
    return str;
  }
  else if(space_char(*(str))){ //checks if next char is a space
    str++; // INCREMENT to next point in memory for the array
  }
  else { //if pointer goes outside array rtn begin
    return begin;
  }
  goto next_word;
  
  return 0;  
}
char *token_start(char *str){
  while(space_char(*(str)) && (!(zero_char(*(str)))) ){
    str++;
  }
  
  if(non_space_char(*(str))){
    return str;
  }
  
  return 0;
}

char *token_terminator(char *token){
  while(non_space_char(*(token))){
    token++;
  }
  if(!(zero_char(*(token)))){
    return token;
  }
  return 0;
}

int count_tokens(char *s){
  int total = 0;
  char *dif = s;
  
  if(zero_char(*(s))){
    return 0;
  }
  
  top:
  s = token_start_better_version(*(s));
  
  //checks if pointer is '\0' or outside array memory
  if(((zero_char(*(s))) == 1) || (s == 0)){
    return total;
  }
  if(s == dif){ // compares point in memory if same rtn total
    return total;
  }
  
  if(s != dif){ // compares point in memory if diff increment total by 1 
    total++;
    dif = s;
  }
  
  goto top;

}

char *copy_str(char *inStr, short len){
  
  char *ostr = malloc((len + 1) * sizeof(char));

    for(int i = 0; i < len; i++){
      * (ostr + i) = * (inStr + i);
    }
  
  * (ostr + len) = '\0';

  return ostr;
}

int str_len(char *str){
  
  int len = 0;
  while(non_space_char(*(str))){
    len++;
    str++;
  }
  
  return len;
}

char **tokenize(char* str){
  char **token_bunch = malloc( (count_tokens(str) + 1) * sizeof(char *) );
  char *token = token_start(str);
  int mark = 0;
  while(!zero_char(*(token))){
      char *end = token_terminator(token);
      *(token_bunch + mark) = copy_str(token, end - token);
      token = token_start(end);
      mark++;
    }
    *(token_bunch + mark) = (copy_str("\0",1));
    return token_bunch;
}

void print_tokens(char **tokens){
  while (!zero_char(**tokens)){
      printf("%s\n", *tokens);
      tokens++;
    }
}
void free_tokens(char **tokens){
  while (!zero_char(**tokens)){
      free(*tokens);
      tokens++;
    }
}
