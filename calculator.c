#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calculator.h"
#include "src/algebra.h"
#include "src/vectors.h"
#include "src/trigonometrics.h"
#include "src/functions.h"

int main(int argc, char *argv[]){
	FILE * help = fopen("help.txt", "r");
	char line[200];
	//initialize general variables
	double val1, val2, result, ans;
	char oper;
	char Operation[100], trash[10];
	//initialize vector variables
	float u[3];
	float v[3];
	float w[3];
	float wans[3];
	
	printf("\nWelcome, if you don't know where to start, type help\n");
		do{
			copiArray(w, wans);
			ans = result;
			printf("\nEnter operation: ");
			scanf("%s", &Operation[0]);

			if(strcmp(Operation, "clear") == 0){
#ifdef __unix__
				system("clear");
#endif
#ifdef __WIN32__
				system("cls");
#endif
			}

			else if(strcmp(Operation, "help") == 0){
				while (fgets(line, sizeof(line), help)){
					printf("%s", line);
				}
				rewind(help);
			}

			else if(strncmp(Operation, "ans", 3) == 0 || strncmp(Operation, "vans", 4) == 0 || Operation[0] == ':' || Operation[0] == 
							'[' || (Operation[0] >= '0' && Operation[0] <= '9' || Operation[0] == '-')){
					
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
								printf("\nOperation not recognized, type help to view syntax...\n");
							break;
						}
						printf("\n= %lf\n", result);
					}

					else if(strncmp(Operation, "vans", 4) == 0){
						sscanf(Operation,"%c%c%c%c%c%c%f%c%f%c%f%c",&trash[0],&trash[1],&trash[2],&trash[3],&oper,&trash[4], &v[0],&trash[5],
										&v[1],&trash[6],&v[2],&trash[7]);

						switch (oper){
							case '+':
								SumVectors(wans,v,w);
								result = SEVectors(w);
								printf("\n= %lf\n", result);
							break;
							case '-':
								SusVectors(wans,v,w);
								result = SEVectors(w);
								printf("\n= %lf\n", result);
							break;
							case '*':
								ProVectors(wans,v,w);
								result = SEVectors(w);
								printf("\n= %lf\n", result);
							break;
							case '/':
								DivVectors(wans,v,w);
								result = SEVectors(w);
								printf("\n= %lf\n", result);
							break;
							case 'x':
								CrossPro(u, v, w);
								PrintVector(w);
							break;
							default:
								printf("\nUnknown Operation...\n");
							break;
							}
					}

					else if (Operation[0] == ':'){
						sscanf(Operation, "%c%c%c%c%c%c%lf%c", &trash[0], &trash[1], &trash[2],&trash[3],&trash[4], &trash[5], &val1, &trash[6]);

							if(strncmp(Operation, ":logn", 5) == 0){
								result = ln(val1);
								printf("\n= %lf\n", result);
							}

							else if(strncmp(Operation, ":sine", 5) == 0){
								result = sine(val1);
								printf("\n= %lf\n", result);
							}

							else if (strncmp(Operation, ":cosi", 5) == 0){
								result = cosine(val1);
								printf("\n= %lf\n", result);
							}

							else if(strncmp(Operation, ":tang", 5) == 0){
								result= tan(val1); 
								printf("\n= %lf\n", result);
							}

							else if(strncmp(Operation, ":actg", 5) == 0){
								result = arctan(val1);
								printf("\n= %lf\n", result);
							}

							else if(strncmp(Operation, ":csct", 5) == 0){
								result = csc(val1);
								printf("\n= %lf\n", result);
							}

							else if(strncmp(Operation, ":sect", 5) == 0){
								result = sec(val1);
								printf("\n= %lf\n", result);
							}

							else if(strncmp(Operation, ":cotg", 5) == 0){
								result = cot(val1);
								printf("\n= %lf\n", result);
							}

							else if(strncmp(Operation, ":acsi", 5) == 0){
								result = arcsine(val1);
								printf("\n= %lf\n", result);
							}

							else if(strncmp(Operation, ":acos", 5) == 0){
								result = arccos(val1);
								printf("\n= %lf\n", result);
							}

							else if(strncmp(Operation, ":asec", 5) == 0){
								result = arcsec(val1);
								printf("\n= %lf\n", result);
							}

							else if(strncmp(Operation, ":acsc", 5) == 0){
								result = arccsc(val1);
								printf("\n= %lf\n", result);
							}

							else if(strncmp(Operation, ":acct", 5) == 0){
								result = arccot(val1);
								printf("\n= %lf\n", result);
							}

							else if(strncmp(Operation, ":logd", 5) == 0){
								result = loga(val1);
								printf("\n= %lf\n", result);
							}
							else {
								printf("\nOperation not recognized...\n");
						}
					}

					else if(Operation[0] == '['){
						sscanf(Operation,"%c%f%c%f%c%f%c%c%c%f%c%f%c%f%c",&trash[0],&u[0],&trash[1],&u[1],&trash[2],&u[2],&trash[3],&oper,
								&trash[5], &v[0],&trash[6],&v[1],&trash[7],&v[2],&trash[8]);

						switch (oper) {	
							case '+':
								SumVectors(u,v,w);
								result = SEVectors(w);
								printf("\n= %lf\n", result);
							break;
							case '-':
								SusVectors(u,v,w);
								result = SEVectors(w);
								printf("\n= %lf\n", result);
							break;
							case '*':
								ProVectors(u,v,w);
								result = SEVectors(w);
								printf("\n= %lf\n", result);
							break;
							case '/':
								DivVectors(u,v,w);
								result = SEVectors(w);
								printf("\n= %lf\n", result);
							break;
							case 'x':
								CrossPro(u, v, w);
								PrintVector(w);
							break;
							default:
								printf("\nUnknown Operation...\n");
							break;
							}
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
								printf("\nOperation not regonized, type help to view sintax...\n");
							break;
						}
						printf("\n= (result) %lf\n", result);
					}
			}
			else if(strncmp(Operation, "s", 1) == 0){
				printf("\nSee you soon...\n");
			}
			else{
				printf("\nOperation not recognized, type help to view syntax...\n");
			}
		}while(Operation[0] != 's');
		return 0;
}
