#include <stdio.h>
#include <stdlib.h>

typedef struct Perceptron{
	int inputs_qtd;
	float *wheights;
	float bias;
}Perceptron;


int recognize(Perceptron p, float *data, int batch_size);

void train_perceptron(Perceptron *p, float **data, int batch_size, int num_epochs);

int step_function(float x);


int main(){
	int epochs = 100, num_nodes = 10;
	float learn_rate = 0.01;



	return 0;
}

int step_function(float x){
	return x > 0? 1: 0;
}

int recognize(Perceptron p, float *data, int batch_size){
	int i, result = 0;
	for (i = 0; i < batch_size, i++){
		result += p.wheights[i] * data[i];
	}
	result += bias;
	return step_function(result);
}

void train_perceptron(Perceptron *p, float **data, int batch_size, int num_epochs){



	
}