/*
@author: Lindsey Langston
@date: 06-07-2025
@version: 1.0
@description: This code implements functions and private members for main file
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "Banking.h"
using namespace std;



// Function to calculate balance WITHOUT monthly deposits

    double Banking::calcBalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_yearlyTotalInterest, int t_numberOfYears) {
    double m_totalAmount = t_initialInvestment;
    double m_interestAmount = 0.0;
    cout << endl << "     Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << string(66, '=') << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << string(66, '-') << endl;

    for (int i = 0; i < t_numberOfYears; i++) {
        m_interestAmount = m_totalAmount * (t_yearlyTotalInterest / 100);
        m_totalAmount = m_totalAmount + m_interestAmount;
        cout << " " << left << setw(5) << (i + 1) << "\t\t$" << fixed << setprecision(2) << m_totalAmount << "\t\t\t\t$" << m_interestAmount << endl;
    }
    return m_totalAmount;
}
// Function to calculate balance WITH monthly deposits

double Banking::calcBalanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_yearlyTotalInterest, int t_numberOfYears) {
    double m_totalAmount = t_initialInvestment;
    double m_interestAmount = 0.0;

    cout << endl << "     Balance and Interest With Additional Monthly Deposits" << endl;
    cout << string(66, '=') << endl;
    cout << "Year          Year End Balance          Year End Earned Interest" << endl;
    cout << string(66, '-') << endl;

    for (int i = 0; i < t_numberOfYears; i++) {
        for (int j = 0; j < 12; j++) { // Monthly deposits
            m_totalAmount += t_monthlyDeposit;
        }
        m_interestAmount = m_totalAmount * (t_yearlyTotalInterest / 100);
        m_totalAmount += m_interestAmount;
        cout << " " << left << setw(5) << (i + 1) << "\t\t$" << fixed << setprecision(2) << m_totalAmount << "\t\t\t\t$" << m_interestAmount << endl;
    }
    return m_totalAmount;
}





