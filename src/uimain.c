#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define maxin 1000

int main(){
  
  char *str= malloc(sizeof(char)*maxin);
  char *choice = malloc(sizeof(char)*60);
  List *tok_list = init_history();
  puts("Hi welcome! just type some input for now \n" );
  while(1){//to start loop
    puts("input t to type a string, ! to check history, f to free history and q to quit ");
    printf("\n>");
    while(1){//for switch case
    fgets(choice,60, stdin);
    switch(*choice){
    case 't':
      fgets(str,maxin,stdin);
      printf("you input: %s", str);
      add_history(tok_list,tokenize(str));
      break;
    case '!':
      puts("What Token would you like printed(int)");
      fgets(choice,60,stdin);
      print_history(get_history(tok_list,*choice));
      break;
    case 'f':
      puts("You chose free history, dont care if it was an accident... too bad");
      free_history(tok_list);
      break;
    case 'q':
      puts("Whatever bro, I didnt want to keep the program going anyways ");
      goto finale;
         }// switch case par
      }// whileloop par end
   }// other while loop end
 finale:
  puts("Bye bye");
}// closes main
