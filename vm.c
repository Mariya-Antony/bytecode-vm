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
  
  while(1){
    int op = program[ip++];
    switch (op) {
       case OP_PUSH: {
          long value = program[ip++];
          stack[sp] = value;
          sp++;
          break;
       }
       case OP_ADD: {
          int b = stack[--sp];
          int a = stack[--sp];
          stack[sp++] = a + b;
          break;
       }
       case OP_PRINT: {
           printf("%ld\n", stack[--sp]);
           break;
       }
       case OP_HALT: {
         return 0;
       }
       
    }
  }
  return 0;
};