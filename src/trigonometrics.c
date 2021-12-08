#include "algebra.h"
#include "../calculator.h"
#include "trigonometrics.h"
#include <stdio.h>
float sine(float x){
	float factorial=1, deriv=1, result=0, mod, cont;
	int n, order=20;
	
	while(x>2*PI){
		x=x-2*PI;
	}
	
	printf("%f\n",x);
	
	for(n=0; n<order; n++){
		if (n!=0){
			factorial*=n;
		}
		
		if ((n%2)!=0){
			result+=deriv*algeb_power(x,n)/factorial;
			deriv*=-1;
		}
	}
	return result;
}
