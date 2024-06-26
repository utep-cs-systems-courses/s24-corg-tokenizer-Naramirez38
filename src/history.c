#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"


List* init_history(){
  List *list = malloc(sizeof(List));
  list -> root = 0;
  return list;
}

void add_history(List *list, char *str){
  
  Item *item = malloc(sizeof(Item));
  item->str = str;
  item->next = 0;
  int num_ = 0;
  if (list->root == 0) {
    item->id = 1;
    list->root = item;
  } else {
    Item *last = list->root;
  another_one:
    while (last->next != 0) {
      last = last->next;
    }
    item->id = last->id + 1;
    last->next = item;
    num_++;
    if(*(str + num_) != '\0'){
      goto another_one;
    }
  }
}

char *get_history(List *list, int id){
  
  Item *item = list->root;
  while (item != 0){
    if (item->id == id){
      return item -> str;
    }
    item = item->next;
  }
  return 0;
}

void print_history(List *list){

  Item *item = list->root;
  
  while (item != 0){
    printf("%d: %s\n", item->id, item->str);
    item = item->next;
  }
  
}

void free_history(List *list){
  
  Item *item = list->root;
  
  while (item != 0) {
    Item *next = item->next;
    free(item->str);
    free(item);
    item = next;
  }
}
