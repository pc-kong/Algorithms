#include <stdio.h>

int main() {
    int init_hour, init_minute, end_hour, end_minute;
    int duration_hours, duration_minutes;
    scanf("%d %d %d %d", &init_hour, &init_minute, &end_hour, &end_minute);
    duration_hours = ((end_hour - init_hour) + 24) % 24;
    if(end_hour == init_hour)
        duration_hours = 24;
    duration_minutes = end_minute - init_minute;
    if(duration_minutes < 0) {
        duration_hours--;
        duration_minutes += 60;
    }
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", duration_hours, duration_minutes);
    return 0;
}
