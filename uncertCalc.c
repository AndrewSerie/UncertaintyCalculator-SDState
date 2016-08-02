/* Program that calculates uncertainty. Reference pg 97.
Written by: Andrew Serie
Current Build Date: 18JUL2016
*/
#include <stdio.h>
#include <math.h>

//Function Prototypes
void printTitle ();
int printInitDirections ();
void printDirections2 (double* num1, double* num2);
void getUncert2 (double num1, double num2, double* uncert, double* mean);
void printDirections3 (double* num1, double* num2, double* num3);
void getUncert3 (double num1, double num2, double num3, double* uncert, double* mean);


int main (void) {
  //Local Declarations
  double num1, num2, num3, mean, uncert;
  int numTrials;

  //Statements
  printTitle ();
  numTrials = printInitDirections ();

  if (numTrials == 2) {
    printDirections2 (&num1, &num2);
    getUncert2 (num1, num2, &uncert, &mean);
  } else {
    printDirections3 (&num1, &num2, &num3);
    getUncert3 (num1, num2, num3, &uncert, &mean);
  }

  printf("                     Answer\n");
  printf("__________________________________________________\n");
  printf("|The mean is: %lf\n", mean);
  printf("|The uncertainty is: %lf\n", uncert);
  printf("|Answer: %lf +/- %lf\n", mean, uncert);
  printf("|!!Please round to the appropriate decimal place!!\n");
  printf("|_________________________________________________\n");

  return 0;
} //main

//Functions
/* ======================== printTitle =======================
   Displays the welcome screen with version number.
*/
void printTitle () {
  printf("\nWelcome to the Uncertainty Calculator v.0.1.0!\n");
  printf("         Created by Andrew Serie\n\n");
  printf("Note! Currently the calculator only supports 2 & 3 numbers.\n\n");

} //printTitle

/* ======================== printInitDirections =======================
   Displays the directions for what to do.
*/
int printInitDirections () {
  //Local Delcarations
  int num;

  //Statements
  printf("How many numbers do you want to caclulate?\n");
  scanf("%d", &num);

  return num;

} //printInitDirections

/* ======================== printDirections2 =======================
   Displays the directions for what to do.
*/
void printDirections2 (double* num1, double* num2) {

  //Statements
  printf("Enter number 1:\n");
  scanf("%lf", num1);
  printf("Enter number 2:\n");
  scanf("%lf", num2);

} //printDirections

/* ======================== printDirections3 =======================
   Displays the directions for what to do.
*/
void printDirections3 (double* num1, double* num2, double* num3) {

  //Statements
  printf("Enter number 1:\n");
  scanf("%lf", num1);
  printf("Enter number 2:\n");
  scanf("%lf", num2);
  printf("Enter number 3:\n");
  scanf("%lf", num3);

} //printDirections

/* ======================== getUncert2 =======================
   Gets the uncertainty for the numbers entered and returns the value to main.
   Also gets the mean!

*/
void getUncert2 (double num1, double num2, double* uncert, double* mean) {
  //Local Declarations
  double stdDev;
  double stdErrM; //SEM

  //Statements
  *mean = (num1 + num2) / 2.0;

  stdDev = sqrt((pow(*mean - num1, 2) + pow(*mean - num2, 2)) / 1.0);
  stdErrM = (stdDev / sqrt(2));
  *uncert = stdErrM * 12.7;

} //getUncert

/* ======================== getUncert3 =======================
   Gets the uncertainty for the numbers entered and returns the value to main.
   Also gets the mean!

*/
void getUncert3 (double num1, double num2, double num3, double* uncert, double* mean) {
  //Local Declarations
  double stdDev;
  double stdErrM; //SEM

  //Statements
  *mean = (num1 + num2 + num3) / 3.0;

  stdDev = sqrt((pow(*mean - num1, 2) + pow(*mean - num2, 2) + pow(*mean - num3, 2)) / 2.0);
  stdErrM = (stdDev / sqrt(3));
  *uncert = stdErrM * 4.30;

} //getUncert
