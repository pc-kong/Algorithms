#include <stdio.h>

int main() {
    int d1, h1, m1, s1, d2, h2, m2, s2;
    int days, hours, minutes, seconds;
    scanf("Dia %d", &d1);
    scanf("%d : %d : %d", &h1, &m1, &s1);
    getchar();
    scanf("Dia %d", &d2);
    scanf("%d : %d : %d", &h2, &m2, &s2);
    days = d2 - d1;
    hours = h2 - h1;
    minutes = m2 - m1;
    seconds = s2 - s1;
    if(hours < 0) {
        hours += 24;
        days--;
    }
    if(minutes < 0) {
        minutes += 60;
        hours--;
    }
    if(seconds < 0) {
        seconds += 60;
        minutes--;
    }
    printf("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)\n", days, hours, minutes, seconds);
    return 0;
}
