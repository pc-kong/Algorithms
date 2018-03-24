#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

void print_array(int array[], string name) {
    for(int i = 0; i < 5; i++)
        cout << name << "[" << i << "]" << " = " << array[i] << endl;
}

int main() {
    int even[5];
    int odd[5];
    int number;
    int cases = 15;
    int index_even = 0, index_odd = 0;
    while(cases--) {
        scanf("%d", &number);
        if(number % 2 == 0) {
            if(index_even == 5) {
                print_array(even, "par");
                index_even = 0;
            }
            even[index_even++] = number;
        }
        else {
            if(index_odd == 5) {
                print_array(odd, "impar");
                index_odd = 0;
            }
            odd[index_odd++] = number;
        }
    }
    if(index_odd != 5)
        for(int j = 0; j < index_odd; j++)
            printf("impar[%d] = %d\n", j, odd[j]);
    if(index_even != 5)
        for(int j = 0; j < index_even; j++)
            printf("par[%d] = %d\n", j, even[j]);
    return 0;
}
