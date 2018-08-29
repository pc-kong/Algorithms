#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<int> grados;
    scanf("%d", &n);
    while(n--) {
        int actual;
        scanf("%d", &actual);
        grados.push_back(actual);
    }
    for(int i: grados) {
        if(i < 38)
            cout << i << endl;
        else if(5-(i%5) < 3)
            cout << i + 5-i%5 << endl;
        else
            cout << i << endl;
    }

    return 0;
}
