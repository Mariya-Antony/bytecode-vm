#include <stdio.h>

enum Op { OP_PUSH, OP_ADD, OP_PRINT, OP_HALT, OP_SUB, OP_MUL };

int main(void) {
    long program[] = {
        OP_PUSH, 10, OP_PUSH, 3, OP_SUB, OP_PRINT,
        OP_PUSH, 6,  OP_PUSH, 7, OP_MUL, OP_PRINT,
        OP_HALT
    };
    long stack[64];
    int sp = 0;
    int ip = 0;

    while (1) {
        int op = program[ip++];
        switch (op) {
            case OP_PUSH: {
                long value = program[ip++];
                stack[sp] = value;
                sp++;
                break;
            }
            case OP_ADD: {
                long b = stack[--sp];
                long a = stack[--sp];
                stack[sp++] = a + b;
                break;
            }
            case OP_SUB: {
                long b = stack[--sp];
                long a = stack[--sp];
                stack[sp++] = a - b;
                break;
            }
            case OP_MUL: {
                long b = stack[--sp];
                long a = stack[--sp];
                stack[sp++] = a * b;
                break;
            }
            case OP_PRINT: {
                long value = stack[--sp];
                printf("%ld\n", value);
                break;
            }
            case OP_HALT:
                return 0;
        }
    }
}