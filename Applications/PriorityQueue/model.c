#include <stdio.h>
#include <stdlib.h>

long f(int n);
float getPercentIdleTime(int lambda, int mu, int servers);
float getAveragePeopleInSystem(float P0, int lambda, int mu, int servers);
float power(float a, int n);
float getAverageTimeTaken(float L, int lambda);
float getAverageSizeQueue(float L, int lambda, int mu);
float getAverageTimeInQueue(float Lq, int lambda);
float getUtilizationFactor(int lambda, int mu, int servers);


float getUtilizationFactor(int lambda, int mu, int servers){
	return (float)(lambda/(float)(servers*mu));
}

float getPercentIdleTime(int lambda, int mu, int servers){
	float ratio = (lambda/(float)mu);
	float sum = 0;
	int i = 0;
	for(i = 0; i<servers; i++){
		sum += (1/(float)f(i))*(power(ratio, i));
	}
	float p = (1/(float)f(servers))*power(ratio, servers);
	p *= servers;
	p *= mu;
	p /= (servers*mu - lambda);
	sum += p;
	return 1/sum;
}

float power(float a, int n){
	float x;
	if(n==0)return 1.0;
	if(n==1)return a;
	else {
		x = power(a, n/2);
		x = x*x;
	}
	if(n%2==0){
		return x;
	}else {
		return x*a;
	}
}

long f(int n){
	int i = 1;
	long prod = 1;
	for(i = 1; i<=n; i++)prod*=i;
	return prod;
}

float getAveragePeopleInSystem(float P0, int lambda, int mu, int servers){	
//	printf("HERE:%f\n", P0);	
	float ratio = (lambda/(float)mu);
	float product = mu*power(ratio, servers)*lambda*P0;
	//return product;
	product /= f(servers-1);
	product /= servers*mu-lambda;
	product /= servers*mu-lambda;
	product += ratio;
	return product;
}

float getAverageTimeTaken(float L, int lambda){	
	return L/(float)lambda;
}

float getAverageSizeQueue(float L, int lambda, int mu){
	float ratio = (lambda/(float)mu);
	return L - ratio;
}

float getAverageTimeInQueue(float Lq, int lambda){
	return Lq/(float)lambda;
}

