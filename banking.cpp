/*
@author: Lindsey Langston
@date: 06-07-2025
@version: 1.0
@course: Programming Languages CS 210   
@description: This program uses object-oriented programming to create a banking system.
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include "Banking.h" // Include the header file for the Banking class
using namespace std;

Banking myInvestment;
double initialInvestment;
double monthlyDeposit;
double annualInterest;
int numberOfYears;
char user_input = 'a'; // Initialize user_input to a character other than 'q'

void printHomeScreen(){
    try {
        cout << "--------------------------------------------" << endl;
        cout << "--------DATA INPUT----------" << endl;
        cout << "Initial Investment Amount: $" << endl;
        cin >> initialInvestment;
        if (initialInvestment < 0) {
            throw runtime_error("Invalid entry. Initial investment cannot be negative.");
        }
        myInvestment.SetInitialInvestment(initialInvestment);
        cout << "Monthly Deposit: $" << endl;
        cin >> monthlyDeposit;
        if (monthlyDeposit < 0) {
            throw runtime_error("Invalid entry. Monthly deposit cannot be negative.");
        }
        myInvestment.SetMonthlyDeposit(monthlyDeposit);
        cout << "Annual Interest Rate: %" << endl;
        cin >> annualInterest;
        if (annualInterest < 0) {
            throw runtime_error("Invalid entry.");
        }
        myInvestment.SetInterestRate(annualInterest);
        cout << "Number of Years: " << endl;
        cin >> numberOfYears;
        if (numberOfYears < 0) {
            throw runtime_error("Invalid entry. Number of years cannot be negative.");
        }
        myInvestment.SetNumberOfYears(numberOfYears);

        system("PAUSE"); // Pause to allow user to read input

        
    }
    catch (runtime_error& excpt) {
        cout << excpt.what() << endl;
        cout << "Cannot compute with negative values." << endl;
        system("PAUSE");
        system("CLS"); // Clear the screen
        printHomeScreen(); // Call the function again to re-enter data
    }
}
int main(){
	cout << "Welcome to the Banking System!" << endl;
    cout << "PRESS ANY KEY TO CONTINUE. PRESS 'q' TO QUIT." << endl;
    cin >> user_input; // Get user input to continue or quit
 	while (user_input != 'q') { //while user doesn't quit program
		printHomeScreen();

		myInvestment.calcBalanceWithoutMonthlyDeposit(myInvestment.GetInitialInvestment(), myInvestment.GetInterestRate(), myInvestment.GetNumberOfYears());
		myInvestment.calcBalanceWithMonthlyDeposit(myInvestment.GetInitialInvestment(), myInvestment.GetMonthlyDeposit(), myInvestment.GetInterestRate(), myInvestment.GetNumberOfYears());

		cout << "Please enter 'q' to quit. Enter any other character or number to run another report. ";
		cin >> user_input;
	}   
    return 0;
}