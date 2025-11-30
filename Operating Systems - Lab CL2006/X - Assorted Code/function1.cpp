#include "header.h"
using namespace std;

int largestNumber(int nVariables, int numbers[]) //pass number of variables and number array
{
    int largest = numbers[0]; //initiate largest as the number at index 0
    
    for (int i = 0; i <= nVariables; i++) { //for loop to iterate through the numbers array that is nVariables long
        largest = (largest<numbers[i]?numbers[i]:largest);
      	//^ternary operator same as:
      	/*
        	if(largest < numbers[i]){
            	largest = numbers[i]; //sets largest as numbers[current iteration of i]
            }
            else{
            	largest = largest; // stays same
            }
        */
    }
    
    return largest;
}