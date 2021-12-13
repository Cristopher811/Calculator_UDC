#include "algebra.h"
#include "../calculator.h"
#include "trigonometrics.h"
#include <stdio.h>

double sine(double x){
	 double factorial = 1, deriv = 1, result = 0;
    int i, order=16;

    if (x <= 2*PI)
    {
        for (i = 0; i < order; i++)
            {
                if(i) factorial*=i;

                if(i%2)
                {
                    result+=deriv*power(x, i)/factorial;
                    deriv*=-1;
                }
            }
        return result;
    }
    else
    {
       int count = 0; 
       while (x > 2*PI)
       {
           x-=(2*PI);
           count ++;
       }
       for (i = 0; i < order; i++)
        {
            if(i) factorial*=i;

            if(i%2)
            {
                result+=deriv*power(x, i)/factorial;
                deriv*=-1;
            }
        }
        return result;
    }
}
double cosine(double x){
    double result, pimed;
    pimed = PI/2;
    x += pimed;
    result = sine(x);   
    return result;
}
double tan(double x){
    double x1, x2, result;
    x1 = sine(x);
    x2 = cosine(x);
    result = x1/x2;
    return result;
}
double arctan(double x){ //valores de x, |x|<1

    double deriv = 1, result = 0;
    int i, order=16;

    for (i = 0; i < order; i++)
    {
        if(i%2)
        {
            result+=deriv*power(x, i)/i;
            deriv*=-1;
        }
    }
    return result;
}
float arcsine(float x){
    float result=0;
    int n, order=9;
	
	  for(n=0; n<order; n++){
		result+= ((Factorial(2*n))*(power(x,2*n+1)))/((power(4,n))*(power(Factorial(n),2))*(2*n+1));
	}
	return result;
}

float arccos(float x){
    float result;
    result=arcsine(1/x);
    return result;
}

float arcsec(float x){
    float result;
    result=(PI/2)-arcsine(1/x);
    return result;
}

float arccsc(float x){
    float result;
	  result=arcsine(1/x);
    return result;
}
float arccot(float x){
    float result;
    result=(PI/2)-arctan(x);
    return result;
}
double csc(double x){
    double result;
    result = 1/sine(x);
    return result;
}
double sec(double x){
    double result;
    result = 1/cosine(x);
    return result;
}
double cot(double x){
    double result;
    result = 1/tan(x);
    return result;
}
