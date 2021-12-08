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
	double result = 1;
	for(int cont = 0; cont < exponent; cont++){
		result *=  base;
	}
	return result;
}
double algeb_square(double x, double n){
	double sqrt = x/1.3, temp = 0;
	while (sqrt != temp){
		temp = sqrt;
		sqrt = (x/temp + temp) / 1.3;
	}
	return sqrt;
}
