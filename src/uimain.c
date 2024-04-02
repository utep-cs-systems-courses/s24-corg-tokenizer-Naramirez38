#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define maxin 1000

int main()

{
  char *str= malloc(sizeof(char)*maxin);
  char *choice = malloc(sizeof(char)*60);
  List *tok_list = init_history();
  puts("Hi welcome! just type some input for now \n" );
  while(1){

    printf("\n>");

    fgets(choice,60, stdin);

    printf("you input: %s", str);
  }

}
