#include <stdio.h>
double calculateRepayment(double loan, double interestRate, int years, double installment) {
    if (loan <= 0 || years == 0) {
        return 0;
    }

    loan = loan + (loan * interestRate);
    loan = loan - installment;
    if (loan < 0) {
        loan = 0;
    }
    int currentYear = years;
    printf("Year %d: Remaining loan = %.2f\n", (4 - years), loan);
    return installment + calculateRepayment(loan, interestRate, years - 1, installment);
}

int main() {
    double loan = 100000;
    double interestRate = 0.05;
    int years = 3;
    double installment = 35000;

    printf("Loan repayment schedule:\n");
    printf("-------------------------\n");

    double totalPaid = calculateRepayment(loan, interestRate, years, installment);

    printf("\nTotal repayment over %d years = %.2f\n", years, totalPaid);

    return 0;
}
