	#include <bits/stdc++.h>

	using namespace std;

	int main(int argc, char const *argv[])
	{
		double d;
		scanf("%lf", &d);
		double alpha;  
		if(d < 1)
			printf("%.12lf\n", (sqrt(2))*d );
		else {
			for(double i= 1; i<=10; i++){
				alpha = sqrt((i*i)+1);
				double lado = floor((sqrt(2))*d);
				double c = (sqrt(2))*d;
				double ladomasuno =  (lado+1)+(sqrt(d*d-((lado+1)*(lado+1))));
				double ladonormal = lado+(sqrt(d*d-lado*lado));

				if(i <= d && d < alpha)
					printf("%.12lf\n", max(c, max(ladonormal, max(i+1, ladomasuno) )));
				else if (alpha <= d && d < i+1) {
					
					printf("%.12lf\n",  max(c, max(ladonormal, ladomasuno)));
				}
			}
		}
		return 0;
	}