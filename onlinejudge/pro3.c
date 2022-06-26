#include <stdio.h>

struct res {
    int breakfast, lunch, dinner;
};

int main (void) {

    int n, i, k = 0, j, l, max, min;

    scanf("%d", &n);

    struct res restlist[10];
    int moneylist[720];

    for (i = 0; i < n; i++) {
        scanf("%d%d%d", &restlist[i].breakfast, &restlist[i].lunch, &restlist[i].dinner);        
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (l = 0; l < n; l++) {
                if (i != j && i != l && j != l) {
                    moneylist[k++] = restlist[i].breakfast + restlist[j].lunch + restlist[l].dinner;
                }
            }
        }
    }

    max = moneylist[0];
    min = moneylist[0];

    for (i = 0; i < k; i++) {
        if (moneylist[i] > max) {
            max = moneylist[i];
        } else if (moneylist[i] < min) {
            min = moneylist[i];
        }
    }

    printf("%d %d", min, max);
    

    return 0;
}   