#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    string h = "";
    h += s[0];
    h += s[1];
    string min = "";
    min += s[3];
    min += s[4];
    string sec = "";
    sec += s[6];
    sec += s[7];
    int hora = stoi(h);
    int minutos = stoi(min);
    int segundos = stoi(sec);
    string m = "";
    m += s[8];
    m += s[9];
    string resultado = "";
    if(m == "PM") {
        if(hora != 12){
            hora += 12;
        }
    } else {
        if(hora == 12)
            hora = 0;
    }
    if(hora < 10)
        resultado += "0";
    resultado += to_string(hora);
    resultado += ":";
    if(minutos < 10)
        resultado += "0";
    resultado += to_string(minutos);
    resultado += ":";
    if(segundos < 10)
        resultado += "0";
    resultado += to_string(segundos);
    return resultado;

}

int main()
{

    string s = "";
    cin >> s;
    string result = timeConversion(s);

    cout << result << "\n";
    return 0;
}
