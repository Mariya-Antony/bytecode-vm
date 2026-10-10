#include <stdio.h>

enum Oper{
    OP_PUSH,
    OP_ADD,
    OP_PRINT,
    OP_HALT
};

int main(void){
  long program[] = {OP_PUSH,2,OP_PUSH,3,OP_ADD,OP_PRINT,OP_HALT };
  long stack[] = {64};
  int sp = 0;
  int ip = 0;
  return 0;
};