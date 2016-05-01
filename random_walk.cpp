#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstring>

using namespace std;

void to_string(int n, char a[]){	   //To convert number to string

	int i = 0;

	while( n> 0){
		
		a[i] = 48 + n%10;
		n = n/10;
		i++;
	}

	a[i] = '\0';

	int len = i;
	i--;

	for( ; i>len/2; i--){

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


int main() {

	ofstream f1;
	char file[20];

	for(int j = 0; j<10; j++){


		name(j, file);              //To make the name of file walk{num}.dat

		f1.open(file);

		int x = 0;

		for(int i= 0; i<= 100; i++) {

			if( rand() < RAND_MAX/2) {
				x++;
			}
			else {
				x--;
			}

			f1<<x<<endl;

		}

		f1.close();

	}

	return 0;
}