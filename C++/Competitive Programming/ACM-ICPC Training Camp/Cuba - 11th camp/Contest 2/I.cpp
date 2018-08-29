#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>


using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	while(n) {
		vector<int> fence;
		int especial = 0;
		while(n--) {
			int post;
			scanf("%d", &post);
			fence.push_back(post);
			especial+=post;			
		}
		
		int i=0;
		int postes = 0;
		int prim_ceros = 0;
		for(int j=0; j<fence.size(); j++) {
			if(fence[j] == 1) {
				i = j;
				break;
			}	
			prim_ceros++;
		}
		int fin = 0;
		int ultimos_ceros = 0;
		for(int j=fence.size()-1; j>=0; j--) {
			if(fence[j] == 1) {
				fin = j;
				break;
			}	
			ultimos_ceros++;
		}

		int ceros = 0;
		while(i <= fin) {
			if(fence[i] == 1) {
				postes += ceros/2;			
				ceros = 0;
			} else
				ceros++;
			i++;
		}

		postes+= (ultimos_ceros+prim_ceros)/2;

		if(especial == 0) {
			
			if(fence.size()%2 == 0)
				printf("%d\n", (int)(fence.size()/2));
			else
				printf("%d\n", (int)((fence.size()/2) + 1));
		} else 
			printf("%d\n", postes);
		scanf("%d", &n);
	}
	return 0;
}