#include <ctype.h>
#include <stdio.h>

int main(void) {

    int n, i, ch, ch_streak = 0, num_streak = 0, max_ch_streak = 0, max_num_streak = 0;
    scanf("%d", &n);

    getchar();
    for (i = 0; i < n; i++) {
        ch = getchar();
        if (isalpha(ch)) {
            num_streak = 0;
            ch_streak++;
            if (ch_streak > max_ch_streak) {
                max_ch_streak = ch_streak;
            }
        } else if (isdigit){
            ch_streak = 0;
            num_streak++;
            if (num_streak > max_num_streak) {
                max_num_streak = num_streak;
            }
        }
    }


    printf("%d\n%d", max_ch_streak, max_num_streak);
    return 0;
}