#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define RVcount 50 //Number of random variables

//Function that returns the value of x into the pdf of the Laplace distribution
double pdf(double x, double m, double b) {
	double r;
	r = exp(fabs(x - m) / (-b)) / (2 * b);//Pdf of Laplace distribution
	return r;
}

//A function that converts rv of uniform distribution to rv of Laplace distribution
double translate(double un, double m, double b) {
	double result;

	if (un > 0.5) { result = m - b * log(2 - un * 2); } //Conversion function at 0.5 <un <1
	else if (un < 0.5) { result = m + b * log(2 * un); } //Conversion function at 0<un <0.5
	else { result = m; } // un = 0.5

	return result;
}

int main() {
	srand((unsigned int)time(NULL));

	//Input of mean and standard deviation
	double m, b;
	printf("Average = ");
	scanf_s("%lf", &m);
	printf("Standard Deviation = ");
	scanf_s("%lf", &b);
	printf("\n");


	//uniform random variable create
	printf("uniform distribution random variable\n");
	double max = 32767; //The maximum value of the rand function to create a real random number
	double uninum[RVcount]; //Array containing random variables of uniform distribution
	for (int i = 0; i < RVcount; i++) {	//Random variable create
		uninum[i] = rand() / max;//Generate random numbers from 0 to 1(Divide by maximum)
		printf("%f \n", uninum[i]);
	}


	//Convert uniform distribution RV to laplace distribution RV
	printf("\n\n\nlaplace distribution random variable\n");
	double lapnum[RVcount];//Array containing random variables of Laplace distribution
	for (int i = 0; i < RVcount; i++) {
		lapnum[i] = translate(uninum[i], m, b);
		printf("%f \n", lapnum[i]);
	}


	//Returns the converted variable into the Laplace pdf function
	printf("\n\n\npdf value\n");
	double lap[RVcount];//array of result values of laplace distribution pdf with lapnum
	for (int i = 0; i < RVcount; i++) {
		lap[i] = pdf(lapnum[i], m, b);
		printf("%f \n", lap[i]);
	}

	return 0;
}