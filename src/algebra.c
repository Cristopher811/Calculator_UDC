#include "functions.h"
#include <stdio.h>
//algebraic functions
double algeb_sum(double val1, double val2){
	double result;
	result = val1 + val2;
	return result;
}
double algeb_subs(double val1, double val2){
	double result;
	result = val1 - val2;
	return result;
}
double algeb_divs(double val1, double val2){
	double result;
	result = val1 / val2;
	return result;
}
double algeb_mult(double val1, double val2){
	double result;
	result = val1 * val2;
	return result;
}
double algeb_power(double base, double exponent){
	
    double potn, result = 0, step = 1, y;
    potn = exponent*(ln(base));
    if (base > 0){
        while (step>TOLERANCE)
        {
            do
            {
                result += step;
                y = ln(result);
            }    
            while (y < potn);

            if(y==potn) 
            break;

            result-=step;
            step/= 10;
        }
        return result;
    }
    else{
        if (exponent - (int)exponent>0 || (exponent>0 && exponent<1)||exponent - (int)exponent<0){
            printf("error");
        }
        else{
            if ((int)exponent%2)
            {
                base*= -1;
                potn = exponent*(ln(base));
                
                while (step>TOLERANCE)
                {
                    do
                    {
                        result += step;
                        y = ln(result);
                    }    
                    while (y < potn);

                    if(y==potn) 
                    break;

                    result-=step;
                    step/= 10;
                }
                result *= -1;
                return result;   
            }   
            else{
                base*= -1;
                potn = exponent*(ln(base));
                while (step>TOLERANCE)
                {
                    do
                    {
                        result += step;
                        y = ln(result);
                    }    
                    while (y < potn);

                    if(y==potn) 
                    break;

                    result-=step;
                    step/= 10;
                }
                return result;   
            }
        }
    }
}
double algeb_square(double b, double x){
	double result = 0;
    double y, step = 1;

    while (step>TOLERANCE)
    {
        do
        {
            result += step;
            y = algeb_power(result, x);
        } 
        while (y<b);

        if(y==b)
        break;
        result -=step;
        step/=10;
        
    }
    return result;
}
