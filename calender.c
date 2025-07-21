#include <stdio.h>
#include <stdlib.h>

// Function to calculate the day of the week for January 1st of a given year
int get_1st_weekday(int year) {
    int d;
    d = (((year - 1) * 365)
       + ((year - 1) / 4)
       - ((year - 1) / 100)
       + ((year) / 400)
       + 1) % 7;
    return d; // 0 = Sunday, 1 = Monday, ..., 6 = Saturday
}

// Function to check for leap year
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    system("Color 3F");

    int year, month, day, daysInMonth, weekDay = 0, startingDay;

    printf("\nEnter your desired year: ");
    scanf("%d", &year);

    // Month names
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Days in each month
    int monthDays[] = {31, 28, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31};

    // Adjust February for leap years
    if (is_leap_year(year)) {
        monthDays[1] = 29;
    }

    startingDay = get_1st_weekday(year);

    for (month = 0; month < 12; month++) {
        daysInMonth = monthDays[month];

        printf("\n\n  ------------%s %d-------------\n", months[month], year);
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print initial spaces for the first week
        for (weekDay = 0; weekDay < startingDay; weekDay++) {
            printf("     ");
        }

        // Print all days of the month
        for (day = 1; day <= daysInMonth; day++) {
            printf("%5d", day);

            if (++weekDay > 6) {
                printf("\n");
                weekDay = 0;
            }
        }

        // Save starting day for next month
        startingDay = weekDay;
    }

    printf("\n\n");
    return 0;
}
