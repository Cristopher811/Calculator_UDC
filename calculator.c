#include <stdio.h>
#include <string.h>

double power(double base, double exponent){
	double result = 1;
	int cont;

	for(cont = 0; cont<(int)exponent; cont++){
		result *=  base;
	}
	return result;
}

double sin(double x){
	double factorial = 1, deriv = 1, result = 0;
	int n, order = 30;

	for(n = 0; n < order; n++){
		if(n) factorial *= n;

		if(n%2){
			result += deriv*power(x, n)/factorial;
			deriv *= -1;
		}
	}
	return result;
}

int main(){
	double val1, val2, result;
	char operator;
	char function[100], trash[7];

	printf("Ingresa la operación: ");
	scanf("%s", &function[0]);

	if(function[0] == ':'){
			sscanf(function, "%c%c%c%c%c%lf%c", &trash[0], &trash[1], &trash[2], &trash[3], &trash[4], &val1, &trash[5]);
			trash[6] = '\x0';
	
			if(strncmp(function, ":sin", 4) == 0){
			result = sin(val1);
			printf("= %.12lf\n", result);
		}
	}	
	else{
		sscanf(function, "%lf%c%lf", &val1, &operator, &val2);
		switch (operator){
			case '+':
				result = val1 + val2;
				printf("= %lf\n", result);
			break;
		}
	}
}
