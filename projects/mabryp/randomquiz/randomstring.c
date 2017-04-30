for testing the testme function of testme.c I used the rand() function generate random
numbers. For the inputChar() function I generated a value between 32 and 125, and returned it as a char. For the inputString() function I used a for loop to generate a random value between 97 and 122 and assign one to each element 0-4, and added \0 at the end.

The random tester finds the values by inputing random characters and strings until the string reads "reset\0", and the state is 9.
