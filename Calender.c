#include <stdio.h>

// Struct to store month details
typedef struct {
    int monthNumber;
    char name[10];
    int days;
} Month;

// Function prototypes
int isLeapYear(int year);
int getFirstDayOfYear(int year);
void printMonthHeader(char* name, int year);
void printCalendar(int year);

int main() {
    int year;
    char choice;

    printf("===== Complex Calendar Generator =====\n");
    do {
        printf("\nEnter a year to generate the calendar: ");
        scanf("%d", &year);
        printf("\nGenerating calendar for %d...\n", year);
        printCalendar(year);

        printf("\nDo you want to generate another calendar? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using the Calendar Generator!\n");
    return 0;
}

// Function to check if a year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// Function to calculate the first day of a given year
// 0 = Sunday, 1 = Monday, ..., 6 = Saturday
int getFirstDayOfYear(int year) {
    int day = (year - 1 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    return day;
}

// Function to print the header for a month
void printMonthHeader(char* name, int year) {
    printf("\n\n  ------------ %s %d ------------\n", name, year);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
}

// Function to print the entire calendar for a given year
void printCalendar(int year) {
    Month months[] = {
        {1, "January", 31}, {2, "February", 28}, {3, "March", 31},
        {4, "April", 30},   {5, "May", 31},      {6, "June", 30},
        {7, "July", 31},    {8, "August", 31},   {9, "September", 30},
        {10, "October", 31},{11, "November", 30},{12, "December", 31}
    };

    if (isLeapYear(year)) {
        months[1].days = 29; // February has 29 days in a leap year
    }

    int dayOfWeek = getFirstDayOfYear(year);

    // Iterate through each month
    for (int i = 0; i < 12; i++) {
        printMonthHeader(months[i].name, year);

        // Print initial spaces for the first week
        for (int space = 0; space < dayOfWeek; space++) {
            printf("     ");
        }

        // Print days of the month
        for (int day = 1; day <= months[i].days; day++) {
            printf("%5d", day);

            // Move to the next line after Saturday
            if ((day + dayOfWeek) % 7 == 0) {
                printf("\n");
            }
        }

        // Update the starting day for the next month
        dayOfWeek = (dayOfWeek + months[i].days) % 7;
        printf("\n");
    }
}

