#include<stdio.h>

struct Week {
    char day[100];
    int date;
    char actdisp[100];
};

void read(struct Week day[], int numDays) {
    for (int i = 0; i < numDays; i++) {
        printf("Enter the date for day %d:\n", i + 1);
        scanf("%d", &day[i].date);

        printf("Enter the Day for day %d:\n", i + 1);
        scanf("%s", day[i].day);

        printf("Enter the activity description for day %d:\n", i + 1);
        scanf("%s", day[i].actdisp);
    }
}

void display(struct Week day[], int numDays) {
    printf("------------Calendar---------\n");

    for (int i = 0; i < numDays; i++) {
        printf("Date:%d, \t Day:%s, \t Activity Description:%s \n", day[i].date, day[i].day, day[i].actdisp);
    }
}

int main() {
    int numDays;
    printf("How many days of activity list do you want? (up to 7): ");
    scanf("%d", &numDays);

    if (numDays > 7 || numDays < 1) {
        printf("Invalid number of days. Please choose between 1 and 7.\n");
        return 1;
    }

    struct Week day[7];

    read(day, numDays);
    display(day, numDays);

    return 0;
}
