#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>
#define PI 3.1415926
#define degreeToRadian(angleDegree) (angleDegree * PI / 180.0)

double equationHandler(double x, int equationDegree, ...);
void bisectionMethod(int iterationNumber, double start, double end, double prevMid, double E, int errorCase);

/*There will be 5 arguments. Unless, you will get an error.*/

int main(int argc, char* argv[]){

	double start;
	double end;
	char errorCase[50] = "";
	double E;

	if(argc != 5)
		perror("\nThere is a problem with argument number. 4 expected.\n");
	else{
		start = atof(argv[1]);
		end = atof(argv[2]);
		E = atof(argv[4]);
		strcpy(errorCase,argv[3]);
		printf("\nn     a\t          f(a)\t        b\t   f(b)\t        p\t    f(p)\n");
		printf("----------------------------------------------------------------------------\n");
		if(strcmp(errorCase,"DISTANCE_TO_ROOT") == 0)
			bisectionMethod(1,start,end,E+1,E,1);
		else if(strcmp(errorCase,"ABSOLUTE_ERROR") == 0)
			bisectionMethod(1,start,end,E+1,E,2);
		else if(strcmp(errorCase, "RELATIVE_ERROR") == 0)
			bisectionMethod(1,start,end,E+1,E,3);
		else
			perror("\nThere is no stop criteria like this.\n");
	}
	

	return 0;
}

/*This function gets changeable number of parameters according to degree*/
/*of the function that you will calculate. "x" parameter is an unknown variable,*/
/*equationDegree is the degree of equation, and the other parameters are constants*/
/*of the x variable. For example, if you want to calculate x^2 + 5x + 6 with x = 4,*/
/* you will call the function like: (4,2,(double)1,(double)5,(double)6)*/
/* 4 is the value of x, 2 is the degree of the equation, 1 is the constant of x^2,*/
/*5 is the constant of x and 6 is the constant of x^0*/

/*IMPORTANT NOTE: constants need to be casted to double, because I get them double*/
/*as parameters*/ 

double equationHandler(double x, int equationDegree, ...){
	
	int counter = equationDegree + 1;
	int exponantial = equationDegree;
	va_list list;
	int a;
	double result = 0;

	va_start(list,equationDegree);

	for(a = 0; a < counter; a++){
		result += va_arg(list,double)*(pow(x,exponantial));
		
		exponantial--;
	}

	va_end(list);

	return result;
	
}

void bisectionMethod(int iterationNumber, double start, double end, double prevMid, double E, int errorCase){

	double midPoint = (double)(start+end)/2;
	/* in here, I wrote "x^2 - 4x + 4 + lnx" equation*/
	double fStart = equationHandler(start,2,(double)1,(double)-4,(double)4-log(start));
	double fEnd = equationHandler(end,2,(double)1,(double)-4,(double)4-log(end));
	double fMidPoint = equationHandler(midPoint,2,(double)1,(double)-4,(double)4-log(midPoint));

	printf("%d  %.8f  %.8f  %.8f  %.8f  %.8f  %.8f\n",iterationNumber,start,fStart,end,fEnd,midPoint,fMidPoint);

	if(errorCase == 1){
		if(fabs(fMidPoint) < E || iterationNumber == 100){
		printf("\n\nIt is done!\n\n");
		return;
		}	
	}
	
	else if(errorCase == 2){
		if(fabs(midPoint - prevMid) < E || iterationNumber == 100){
			printf("\n\nIt is done!\n\n");
			return;
		}
	}

	else if(errorCase == 3){
		if((fabs(midPoint - prevMid))/fabs(midPoint) < E || iterationNumber == 100){
			printf("\n\nIt is done.\n\n");
			return;
		}
	}

	
	if(fStart*fMidPoint < 0){
		bisectionMethod(iterationNumber+1,start,midPoint,midPoint,E,errorCase);
	}
	else if(fEnd*fMidPoint < 0){
		bisectionMethod(iterationNumber+1,midPoint,end,midPoint,E,errorCase);
	}
	else{
		perror("\nThere is no root between these points.\n");
		return;
	}
}
