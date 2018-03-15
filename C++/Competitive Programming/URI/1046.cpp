#include <stdio.h>

int main() {
    int begin, end, duration;
    scanf("%d %d", &begin, &end);
    if(begin == end)
        duration = 24;
    else if(begin > end)
        duration = (24 - begin) + end;
    else
        duration = end - begin;
    printf("O JOGO DUROU %d HORA(S)\n", duration);
    return 0;
} 
