#include <stdio.h>
#include <stdlib.h>
#include "../calculator.h"
#include "algebra.h"

void PrintVector(float *v){
	int i;
	printf("\n= [");
	
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
float SEVectors(float *sev){
	int i=0; 
	float sum;
	sum=sev[i]+sev[i+1]+sev[i+2];
	return sum;
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
void CrossPro(float *v1, float *v2, float *cross){
	int l;
	float i[]={1,0,0};
	float j[]={0,1,0};
	float k[]={0,0,1};
	
	i[0]=v1[1]*v2[2]-v1[2]*v2[1];
	j[1]=v1[2]*v2[0]-v1[0]*v2[2];
	k[2]=v1[0]*v2[1]-v1[1]*v2[0];
	
	for(l=0;l<DIM;l++){
		cross[l]=i[l]+j[l]+k[l];
	}
}
void copiArray(float w[], float wans[]){
	for(int i = 0; i<3; i++){
		wans[i] = w[i];
	}
}
