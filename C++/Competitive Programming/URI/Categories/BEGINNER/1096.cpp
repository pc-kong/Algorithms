#include <stdio.h>

int main() {
    int I = 1, J = 7;
    while(I <= 9) {
        J = 7;
        for(int i = 0; i < 3; i++) {
            printf("I=%d J=%d\n", I, J);
            if(i == 2)
                I += 2;
            J--;
        }
    }
    return 0;
}
