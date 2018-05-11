#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Perceptron{
	int inputs_qtd;
	float *weights;
	float bias;
}Perceptron;


int recognize(Perceptron p, float *data, int batch_size);

void train_perceptron(Perceptron *p, float **data, int batch_size, int num_epochs, float learn_rate);

int step_function(float x);


int main(){
	int epochs = 100, num_nodes = 10;
	float learn_rate = 0.01;
	srand(time(NULL));
	printf("%f\n", (float)rand()/RAND_MAX);

	return 0;
}

int step_function(float x){
	return x > 0? 1: 0;
}

int recognize(Perceptron p, float *data, int batch_size){
	int i, result = 0;
	for (i = 0; i < batch_size; i++){
		result += p.weights[i] * data[i];
	}
	result += p.bias;
	return step_function(result);
}

void train_perceptron(Perceptron *p, float **data, int batch_size, int num_epochs, float learn_rate){
	int i, j, k, result = 0;
	for(i = 0; i < p->inputs_qtd; i++){
		srand(time(NULL)); //seeding the rand
		(*p).weights[i] = (float)rand()/RAND_MAX; //generates a weight between 0 and 1
	}
	for(i = 0; i < num_epochs; i++){
		for(j = 0; j < p->inputs_qtd; j++){
			result = recognize(*p, data[i], batch_size);
			if(result != data[i][p->inputs_qtd - 1]){
				for(k = 0; k < p->inputs_qtd; k++){
					(*p).weights[k] += learn_rate*(data[i][p->inputs_qtd - 1] - result)*data[i][k];
				}

			}
		}
	}

}