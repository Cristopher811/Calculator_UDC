#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define PI 3.14159265359
#define SQ(X) (X)*(X)
#define TOLERANCE 1.e-6
#define DIM 3

//algebraic functions
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

//vector functions
void PrintVector(float *v){
	int i;
	printf("= [");
	
	for(i=0;i<DIM;i++){
		printf("%f,",*v++);
	}
	printf("\b]\n");
}
void SumVectors(float *v1, float *v2, float *sum){
	int i;
	for(i=0;i<DIM;i++){
		sum[i]=v1[i]+v2[i];
	}
}
void SusVectors(float *v1, float *v2, float *sus){
	int i;
	for(i=0;i<DIM;i++){
		sus[i]=v1[i]-v2[i];
	}
}
void ProVectors(float *v1, float *v2, float *pro){
	int i;
	for(i=0;i<DIM;i++){
		pro[i]=v1[i]*v2[i];
	}
}
void DivVectors(float *v1, float *v2, float *Div){
	int i;
	for(i=0;i<DIM;i++){
		if(v2[i]!=0){
			Div[i]=v1[i]/v2[i];
		}
		else{
			printf("Undefined Operation");
			exit(0);
		}
	}
}
void copiArray(float w[], float wans[]){
	for(int i = 0; i<3; i++){
		wans[i] = w[i];
	}
}
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
			result+=deriv*power(x,n)/factorial;
			deriv*=-1;
		}
	}
	return result;
}

int main(int argc, char *argv[]){
	//initialize general variables
	double val1, val2, result, ans;
	char oper;
	char Operation[100], trash[10];
	//initialize vector variables
	float u[3];
	float v[3];
	float w[3];
	float wans[3];

		do{
			copiArray(w, wans);
			ans = result;
			printf("Enter operation: ");
			scanf("%s", &Operation[0]);

			if(strncmp(Operation, "ans", 3) == 0){//--> ans operations
				sscanf(Operation, "%c%c%c%c%lf", &trash[0], &trash[1], &trash[2], &oper, &val1);
					switch (oper) {
						case '+':
							result = sum(ans, val2);
						break;
						case '-':
							result = subs(ans, val2);
						break;
						case '*':
							result = mult(ans, val2);
						break;
						case '/':
							result = divs(ans, val2);
						break;
						case '^':
							result = power(ans, val2);
						break;
						case '|':
							result = square(ans, val2);
						break;
						default:
							printf("Operation not regonized, type help to view sintax...\n");
						break;
					}
					printf("= (result) %lf\n", result);
			} 			

			else if(strncmp(Operation, "vans", 4) == 0){
				sscanf(Operation,"%c%c%c%c%c%c%f%c%f%c%f%c",&trash[0],&trash[1],&trash[2],&trash[3],&oper,&trash[4],
				&v[0],&trash[5],&v[1],&trash[6],&v[2],&trash[7]);

				switch (oper) {
						case '+':
							SumVectors(wans,v,w);
						break;
						case '-':
							SusVectors(wans,v,w);
						break;
						case '*':
							ProVectors(wans,v,w);
						break;
						case '/':
							DivVectors(wans,v,w);
						break;
						default:
							printf("Unknown Operation");
							exit(0);
					}
					PrintVector(w);
			}

			else if(Operation[0] == ':'){
					sscanf(Operation, "%c%c%c%c%lf%c", &trash[0],&trash[1],&trash[2],&trash[3], &val1, &trash[4]);
					//some trigonometric stuff
				}
			
			else if(Operation[0] == '['){ //--> vector operations
				sscanf(Operation,"%c%f%c%f%c%f%c%c%c%f%c%f%c%f%c",&trash[0],&u[0],&trash[1],&u[1],&trash[2],&u[2],&trash[3],&oper,&trash[5],
						&v[0],&trash[6],&v[1],&trash[7],&v[2],&trash[8]);

						switch (oper) {
							case '+':
								SumVectors(u,v,w);
							break;
							case '-':
								SusVectors(u,v,w);
							break;
							case '*':
								ProVectors(u,v,w);
							break;
							case '/':
								DivVectors(u,v,w);
							break;
							default:
								printf("Unknown Operation");
								exit(0);
							}
						PrintVector(w);
					}

			else { //aritmetic operations
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
						default:
							printf("Operation not regonized, type help to view sintax...\n");
						break;
					}
					printf("= (result) %lf\n", result);
				} 
			}while(Operation[0] != 's');
		return 0;
}
