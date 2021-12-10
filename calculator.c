#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculator.h"
#include "src/algebra.h"
#include "src/vectors.h"
#include "src/trigonometrics.h"
#include "src/functions.h"

/* int is_number(char n[100]){
	int j = 0;
	int is_digit = 0;

	while (j<strlen(n)){
		is_digit = isdigit(n[j]);
		if (is_digit == 0) break;
		j++;
	}
	return 0;
}*/

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

			if(strcmp(Operation, "help") == 0){
				printf("help\n");
			}

			else if(strncmp(Operation, "ans", 3) == 0 || strncmp(Operation, "vans", 4) == 0 || Operation[0] == ':' || Operation[0] == '[' 
					|| (Operation[0] >= '0' && Operation[0] <= '9' || Operation[0] == '-')){
					
					if (strncmp(Operation, "ans", 3) == 0){
						sscanf(Operation, "%c%c%c%c%lf", &trash[0],&trash[1],&trash[2], &oper, &val2);
						
						switch (oper){
							case '+':
								result = algeb_sum(ans, val2);
							break;
							case '-':
								result = algeb_subs(ans, val2);
							break;
							case '*':
								result = algeb_mult(ans, val2);
							break;
							case '/':
								result = algeb_divs(ans, val2);
							break;
							case '^':
								result = algeb_power(ans, val2);
							break;
							case '|':
								result = algeb_square(ans, val2);
							break;
							default:
								printf("Operation not recognized, type help to view sintax...\n");
							break;
						}
						printf("= %lf\n", result);
					}

					else if(strncmp(Operation, "vans", 4) == 0){
						sscanf(Operation,"%c%c%c%c%c%c%f%c%f%c%f%c",&trash[0],&trash[1],&trash[2],&trash[3],&oper,&trash[4], &v[0],&trash[5],&v[1],&trash[6],
										&v[2],&trash[7]);

						switch (oper){
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
								printf("Unknown Operation\n");
							break;
							}
						PrintVector(w);
					}

					else if (Operation[0] == ':'){
						sscanf(Operation, "%c%c%c%c%c%lf%c", &trash[0],&trash[1],&trash[2],&trash[3], &trash[4], &val1, &trash[5]);

							if(strncmp(Operation, ":lna", 4) == 0){
								result = ln(val1);
								printf("= %lf\n", result);
							}

							if(strncmp(Operation, ":log", 4) == 0){
								result = loga(val1);
								printf("= %lf\n", result);
							}
							else {
								printf("Operation not recognized...\n");
						}
					}

					else if(Operation[0] == '['){
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
								printf("Unknown Operation\n");
								exit(0);
							}
						PrintVector(w);
					}

					else if(Operation[0] >= '0' && Operation[0] <= '9' || Operation[0] == '-'){
						sscanf(Operation, "%lf%c%lf", &val1, &oper, &val2);

						switch (oper) {
							case '+':
								result = algeb_sum(val1, val2);
							break;
							case '-':
								result = algeb_subs(val1, val2);
							break;
							case '*':
								result = algeb_mult(val1, val2);
							break;
							case '/':
								result = algeb_divs(val1, val2);
							break;
							case '^':
								result = algeb_power(val1, val2);
							break;
							case '|':
								result = algeb_square(val1, val2);
							break;
							default:
								printf("Operation not regonized, type help to view sintax...\n");
							break;
						}
						printf("= (result) %lf\n", result);
					}
			}
			else{
				printf("Operation not recognized, type help to view syntax...\n");
			}
		}while(Operation[0] != 's');
		return 0;
}
