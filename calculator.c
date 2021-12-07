#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

double sum(double val1, double val2){
	double result;
	result = val1 + val2;
	return result;
}
double subs(double val1, double val2){
	double result;
	result = val1 - val2;
	return result;
}
double divs(double val1, double val2){
	double result;
	result = val1 / val2;
	return result;
}
double mult(double val1, double val2){
	double result;
	result = val1 * val2;
	return result;
}
double power(double base, double exponent){
	double result = 1;
	int cont;
	for(cont = 0; cont<(int)exponent; cont++){
		result *=  base;
	}
	return result;
}
double square(double x, double n){
	double sqrt = x/1.3, temp = 0;
	while (sqrt != temp){
		temp = sqrt;
		sqrt = (x/temp + temp) / 1.3;
	}
	return sqrt;
}


int main(int argc, char *argv[]){
	//initialize general variables
	double val1, val2, result, ans;
	char oper;
	char Operation[100], trash[10];

		do{
			printf("Enter operation: ");
			scanf("%s", &Operation[0]);
			if(Operation[0] == ':'){
				sscanf(Operation, "%c%c%c%c%lf%c", &trash[0],&trash[1],&trash[2],&trash[3], &val1, &trash[4]);
			}
			else if(Operation[0] == '['){
				//some vectors stuff
			}
			else {
				sscanf(Operation, "%lf%c%lf", &val1, &oper, &val2);
				switch (oper) {
					case '+':
						result = sum(val1, val2);
					break;
					case '-':
						result = subs(val1, val2);
					break;
					case '*':
						result = mult(val1, val2);
					break;
					case '/':
						result = divs(val1, val2);
					break;
					case '^':
						result = power(val1, val2);
					break;
					case '|':
					result = square(val1, val2);
					break;
					}
				} 
			}while(Operation[0] != 's');
			printf("= %lf\n", result);
			ans = result;
			printf("=%lf\n",ans);
		return 0;
}
