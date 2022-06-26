#include <stdio.h>
#include <stdlib.h>

struct point {
    int x, y;
};

int comparefunc(const void *p, const void *q);

int main(void) {

    int n, i;
    scanf("%d", &n);

    struct point *list = (struct point *) malloc(sizeof(struct point) * n);

    for (i = 0; i < n; i++) {
        scanf("%d%d", &list[i].x, &list[i].y);
    }

    qsort(list, n, sizeof(struct point), comparefunc);

    for (i = 0; i < n; i++) {
        printf("%d %d", list[i].x, list[i].y);
        if (i != n - 1) {
            putchar('\n');
        }
    }

    return 0;
}

int comparefunc(const void *p, const void *q) {
    if ((*(struct point*) p).x == (*(struct point*) q).x) {
        return ((*(struct point*) p).y - (*(struct point*) q).y);
    } else {
        return (*(struct point*) p).x - (*(struct point*) q).x;
    }
}