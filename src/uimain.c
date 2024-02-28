#include <stdio.h>
#define maxin 1000
int main()
{
  char *arrpoint;
  char str[maxin];
  char *arrpoint = &str[0]// pointer str[0]
  puts("Hi welcome! just type some input for now \n" );
  //Put 1 inside while-loop to ensure no termination
  while(1){
    printf("\n>");
    fgets(str,maxin, stdin);
    printf("you input: %s", str);
    
  }
}

