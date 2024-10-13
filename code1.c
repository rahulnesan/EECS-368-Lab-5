#include <stdio.h>
#include <string.h>

#define MONTHS 12

// Function prototypes
void monthlySalesReport(double sales[]);
void salesSummaryReport(double sales[]);
void sixMonthMovingAverageReport(double sales[]);
void salesReportDescending(double sales[]);

// Helper functions
void printMonth(int monthIndex);
void sortSalesDescending(double sales[], int months[], int size);

int main() {
    double sales[MONTHS] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 
                            60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 
                            80950.34, 95225.22};
    
    printf("Monthly Sales Report for 2024\n");
    monthlySalesReport(sales);
    
    printf("\nSales Summary Report\n");
    salesSummaryReport(sales);
    
    printf("\nSix-Month Moving Average Report\n");
    sixMonthMovingAverageReport(sales);
    
    printf("\nSales Report (Highest to Lowest)\n");
    salesReportDescending(sales);
    
    return 0;
}

// Function to print the monthly sales report
void monthlySalesReport(double sales[]) {
    printf("Month\t\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printMonth(i);
        printf("\t$%.2f\n", sales[i]);
    }
}

// Function to print the sales summary report
void salesSummaryReport(double sales[]) {
    double min = sales[0], max = sales[0], sum = 0;
    int minMonth = 0, maxMonth = 0;
    
    for (int i = 0; i < MONTHS; i++) {
        if (sales[i] < min) {
            min = sales[i];
            minMonth = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxMonth = i;
        }
        sum += sales[i];
    }
    
    printf("Minimum sales: $%.2f (", min);
    printMonth(minMonth);
    printf(")\n");
    
    printf("Maximum sales: $%.2f (", max);
    printMonth(maxMonth);
    printf(")\n");
    
    printf("Average sales: $%.2f\n", sum / MONTHS);
}

// Function to print the six-month moving average report
void sixMonthMovingAverageReport(double sales[]) {
    for (int i = 0; i <= MONTHS - 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%s-", (i == 0 ? "January" : ""));
        printMonth(i + 5);
        printf("\t$%.2f\n", sum / 6);
    }
}

// Function to print sales report in descending order
void salesReportDescending(double sales[]) {
    int months[MONTHS];
    for (int i = 0; i < MONTHS; i++) {
        months[i] = i;
    }
    
    sortSalesDescending(sales, months, MONTHS);
    
    printf("Month\t\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printMonth(months[i]);
        printf("\t$%.2f\n", sales[i]);
    }
}

// Helper function to print the month names
void printMonth(int monthIndex) {
    const char *months[] = {"January", "February", "March", "April", "May", "June", 
                            "July", "August", "September", "October", "November", "December"};
    printf("%s", months[monthIndex]);
}

// Function to sort sales in descending order and keep track of months
void sortSalesDescending(double sales[], int months[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (sales[j] < sales[j + 1]) {
                double tempSales = sales[j];
                sales[j] = sales[j + 1];
                sales[j + 1] = tempSales;
                
                int tempMonth = months[j];
                months[j] = months[j + 1];
                months[j + 1] = tempMonth;
            }
        }
    }
}
