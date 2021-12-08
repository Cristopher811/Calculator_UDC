#include <stdio.h>
#include <stdlib.h>
#include "../calculator.h"
#include "algebra.h"

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
