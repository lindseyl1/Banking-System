#ifndef BANKING_H
#define BANKING_H

class Banking {
private:
    double m_totalAmount;
    double m_monthlyDeposit;
    double m_yearlyTotalInterest;
    int m_numberOfYears;
public:
    void SetInitialInvestment(double);
    void SetMonthlyDeposit(double);
    void SetInterestRate(double);
    void SetNumberOfYears(int);

    double GetInitialInvestment() const;
    double GetMonthlyDeposit() const;
    double GetInterestRate() const;
    int GetNumberOfYears() const;

    double calcBalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_yearlyTotalInterest, int t_numberOfYears);
    double calcBalanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_yearlyTotalInterest, int t_numberOfYears);
};

#endif