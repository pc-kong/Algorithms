#include <bits/stdc++.h>

using namespace std;

int main() {
	int n = 0;
	cin >> n;
	vector<int> numeros;
	while(n--) {
		int act;
		cin >> act;
		numeros.push_back(act);
	}
	sort(numeros.begin(), numeros.end());
	int min = 1000000000;
	for(int i=0; i<numeros.size()-1; ++i){
		int act = numeros[i];
		int act2 = numeros[i+1];
		if(abs(act-act2) < min)
			min = abs(act-act2);
	}
	cout << min << "\n";
	return 0; 
}

palloc_free_page (file_name);
  thread_current()->padre->load = success;
  sema_up(thread_current()->padre->wait);