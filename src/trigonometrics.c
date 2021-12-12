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
