#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time calculateDifference(struct Time t1, struct Time t2) {
    struct Time diff;
    
    // Convert both time periods to seconds
    int t1Seconds = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int t2Seconds = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    // Calculate the absolute difference in seconds
    int difference = t1Seconds - t2Seconds;
    if (difference < 0)
        difference = -difference;

    // Convert the difference back to hours, minutes, and seconds
    diff.hours = difference / 3600;
    diff.minutes = (difference % 3600) / 60;
    diff.seconds = (difference % 3600) % 60;

    return diff;
}

int main() {
    struct Time time1, time2, difference;

    printf("Enter the first time period:\n");
    printf("Hours: ");
    scanf("%d", &(time1.hours));
    printf("Minutes: ");
    scanf("%d", &(time1.minutes));
    printf("Seconds: ");
    scanf("%d", &(time1.seconds));

    printf("\nEnter the second time period:\n");
    printf("Hours: ");
    scanf("%d", &(time2.hours));
    printf("Minutes: ");
    scanf("%d", &(time2.minutes));
    printf("Seconds: ");
    scanf("%d", &(time2.seconds));

    difference = calculateDifference(time1, time2);

    printf("\nDifference: %d hours, %d minutes, %d seconds\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}
