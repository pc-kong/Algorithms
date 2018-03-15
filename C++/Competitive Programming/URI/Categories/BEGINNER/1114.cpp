#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    string password;
    while(cin >> password) {
        if(password != "2002") {
            printf("Senha Invalida\n");
            continue;
        }
        printf("Acesso Permitido\n");
        break;
    }
    return 0;
}
