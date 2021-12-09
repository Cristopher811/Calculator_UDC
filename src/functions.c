#include "functions.h"
#include "algebra.h"

double power(double base, double exponent)
{
    double acum;

    if (base)
    {
        double result = 1;
	    int cont;

	    for(cont = 0; cont<(int)exponent; cont++){
		    result *=  base;
	    }
	return result;
    }
}

double ln(double x) //Serie de Maclaurin para logaritmo natural adaptada para |x| > 1 //: functions
{
    double q, deriv2= 1, deriv = 1, result = 0, resp = 0, res= 0, resfinal, x_mc = x-1,y, step = 1, resu=0;
    int l, i, countln = 0 ,order = 100;

    if(x < 2)
    {
        for (i = 1; i <= order; i++)
            {
                result+=deriv*power(x_mc, i)/i;
                deriv*=-1;
            }
        return result;
    }
    else
    {
        while (x > 1)
        {
            x /= 1.5;
            countln ++;
        }
        x_mc = x-1;
        for (i = 1; i <= order; i++)
            {
                result+=deriv*power(0.5, i)/i;
                deriv*=-1;
            }
        for (l = 1; l <= order; l++)
            {
                resu+=deriv*power(x_mc, l)/l;
                deriv*=-1;
            }

        resfinal = resu + result*(countln);
        return resfinal;
    }
}

double loga(double a) //:functions
{
    double step=1, result=0, y;
    double b = 10;

    while (step>TOLERANCE)
    {
        do
        {
            result += step;
            y = algeb_power(b, result);
        }    
        while (y < a);

        if(y==a) 
        break;

        result-=step;
        step/= 10;
    }
    return result;
}
