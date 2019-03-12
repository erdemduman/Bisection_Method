## BISECTION METHOD

Program accepts 5 main arguments.

argv[0] = name of the executable
argv[1] = starting point 
argv[2] = ending point
argv[3] = error type ("DISTANCE_TO_ROOT", "ABSOLUTE_ERROR" or "RELATIVE ERROR")
argv[4] = epsilon

You can test your equation at the line where equationHandler function is called.

### PARAMETERS OF equationHandler FUNCTION 

double x: variable of the equation.
int equationDegree: degree of the equation.
other parameters: constant of the variable.

for example, if you want to find the result of 2x^2 - 6x + 4 equation for
x = 3, you will call the function like 
equationHandler((double)3,2,(double)2,(double)-6,(double)4)

### EXAMPLES

4x^3 + 9x + lnx - 1 for x = 2;
equationHandler((double)2,3,(double)4,0,(double)9,log(2)-1)

x - cos(x) + 5 for x = 60;
equationHandler((double)1,1,(double)1,cos(degreeToRadian(60))+5);

x^2 + 5x + 6;
((double)4,2,(double)1,(double)5,(double)6)


NOTE: parameters need to be casted to double to work correctly.
