#include <stdio.h>
#include <string.h>

#define MAX_REMIND (50)
#define MSG_LEN (60)

int read_line(char str[], int size);

int main(void) {

    char reminder[MAX_REMIND][MSG_LEN + 13];
    char day_hour_str[13];
    char msg_str[MSG_LEN + 1];
    int day, i, j, k, hour, minute, month;
    int num_remind = 0;

    for(;;) {
        if(num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter month/day and hour and reminder: ");
        scanf("%d", &month);
        if(month == 0) {
            break;
        }
        scanf(" /%d", &day);

        if(!(day <= 31 && day >= 0)) {
            printf("ERROR\n");
            rewind(stdin);
            continue;
        }

        
        scanf("%d :%d", &hour, &minute);

        sprintf(day_hour_str, "%2.2d/%2.2d %.2d:%.2d", month, day, hour, minute);   
        read_line(msg_str, MSG_LEN);

        for(i = 0; i < num_remind; ++i) {
            if(strcmp(day_hour_str, reminder[i]) < 0) {
                break;
            }
        }

        for(j = num_remind; j > i; --j) {
            strcpy(reminder[j], reminder[j-1]);
        }

        strcpy(reminder[i], day_hour_str);
        strcat(reminder[i], msg_str);

        ++num_remind;
    }

    printf("\nDay Hour Reminder\n");
    for(i = 0; i < num_remind; ++i) {
        printf(" %s\n", reminder[i]);
    }

    return 0;
}


int read_line(char str[], int size) {
    int ch;
    int i = 0;

    while((ch = getchar()) != '\n') {
        if(i < size) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';

    return i;
}