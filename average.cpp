#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstring>

using namespace std;

#define NO_OF_RUNS 10
#define NO_OF_LINES 100

void to_string(int n, char a[]){	   //To convert number to string

	int i = 0;

	while( n> 0){
		
		a[i] = 48 + n%10;
		n = n/10;
		i++;
	}

	a[i] = '\0';

	int len = i;

	for(i = 0; i<len/2; i++){

		char t = a[i];
		a[i] = a[len-i-1];
		a[len-i-1] = t;

	}

}


void name(int n, char text[]) {     //To make the name in form walk{num}.dat

	char num[10];
	to_string(n,num);
	char walk[10] = "walk";

	strcat(walk, num);
	strcat(walk, ".dat");

	strcpy(text,walk);

}

int main(){

	ifstream f1;
	int avg[NO_OF_LINES];
	int num;

	char file[20];

	for(int i = 0; i< NO_OF_LINES; i++){

		avg[i] = 0;

	}

	for(int j = 1; j<=NO_OF_RUNS; j++){
		
		name(j, file);					 //To make the name of file walk{num}.dat

		f1.open(file);

		int i = 0;

		while(f1>>num){
			
			avg[i] += num;

		}

		f1.close();

	}

	for(int i = 0; i<NO_OF_LINES; i++) {

		avg[i] /= NO_OF_RUNS;
		cout<<avg[i]<<endl;
	}

	return 0;
}