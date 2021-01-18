#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


struct  Vector {
	int sz;
	double* elem;
};

void vector_init(Vector& v, int s)
{       
        v.elem = new double[s];
        v.sz = s;
}       

double read_and_sum(int s)
{       
        Vector v;
        vector_init(v,s);
        for (int i=0; i!=s; ++i)
                cin>>v.elem[i];
        double sum = 0;
        for (int i=0; i!=s; ++i)
                sum+=v.elem[i];
	printf("Sum is %f", sum);
        return sum;
}
int main(int argc, char ** argv)
{	
	if (argc != 2 ){
		fprintf(stderr, "Try to choose another amount of argument");
		return 1;
	}
	else {
		int number = atoi(argv[1]);
		read_and_sum(number);
	}

	return 0;
}
