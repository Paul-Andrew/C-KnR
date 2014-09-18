#include <stdio.h>
#define swap(t,x,y)  t temp = x;x=y;y=temp;

int main(){

  int a = 5;
  int b = 12;
  printf("a is %i and b is %i, swapping.\n",a,b);
  swap(int,a,b);
  printf("a is %i and b is %i after swap.\n",a,b);
  return 0;
}