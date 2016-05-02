#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstring>

using namespace std;

#define NO_OF_RUNS 10000
#define NO_OF_LINES 100
#define FILE_NAME "Avg_x^2(10^4).dat"

int main() {

	ofstream f1;
	int avg[NO_OF_LINES];
	int num;
	char file[20];

	for(int i = 0; i< NO_OF_LINES; i++){		//To initialize all to zero

		avg[i] = 0;

	}

	for(int j = 1; j<=NO_OF_RUNS; j++){

		int x = 0;

		for(int i= 0; i<= NO_OF_LINES; i++) {

			if( rand() < RAND_MAX/2) {
				x++;
			}
			else {
				x--;
			}

			avg[i] += x*x;

		}


	}


	ofstream f2;

	f2.open(FILE_NAME);

	for(int i = 0; i<NO_OF_LINES; i++) {

		avg[i] /= NO_OF_RUNS;

		f2<<avg[i]<<endl;
	}

	f2.close();

	return 0;
}