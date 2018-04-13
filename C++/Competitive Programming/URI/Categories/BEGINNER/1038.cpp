#include <stdio.h>
#include <map>
using namespace std;

int main() {
    map<int,double> code_price;
    code_price.insert(pair<int,double> (1,4.00));
    code_price.insert(pair<int,double> (2,4.50));
    code_price.insert(pair<int,double> (3,5.00));
    code_price.insert(pair<int,double> (4,2.00));
    code_price.insert(pair<int,double> (5,1.50));

    int selection, quantity;
    scanf("%d %d", &selection, &quantity);
    double to_pay = code_price[selection] * quantity;
    printf("Total: R$ %.2lf\n", to_pay);
    return 0;
}
