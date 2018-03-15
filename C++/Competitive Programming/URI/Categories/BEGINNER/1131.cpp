#include <stdio.h>

int main() {
    int grenais = 0, inter = 0, gremio = 0, draws = 0, answer;
    int goals_inter, goals_gremio;
    
    scanf("%d %d", &goals_inter, &goals_gremio);
    grenais++;
    if(goals_inter == goals_gremio) draws++;
    if(goals_inter > goals_gremio) inter++;
    else gremio++;

    while(1) {
        printf("Novo grenal (1-sim 2-nao)\n");
        scanf("%d", &answer);
        if(answer == 2) {
            printf("%d grenais\n", grenais);
            printf("Inter:%d\n", inter);
            printf("Gremio:%d\n", gremio);
            printf("Empates:%d\n", draws);
            if(inter == gremio) printf("Não houve vencedor\n");
            if(inter > gremio) printf("Inter venceu mais\n");
            else printf("Gremio venceu mais\n");
            break;
        }
        scanf("%d %d", &goals_inter, &goals_gremio);
        grenais++;
        if(goals_inter == goals_gremio) draws++;
        if(goals_inter > goals_gremio) inter++;
        else gremio++;
    }
    return 0;
}
