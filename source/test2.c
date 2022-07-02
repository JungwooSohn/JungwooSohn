#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct bsearchnode {
    int value;
    struct bsearchnode *left, *right;
} Bsearchnode;

int cordinate[1000000] = {0,}; // 전부 저장
int compressed_cordinate[1000000] = {0,}; // 겹치지 않게 저장 <- 정렬되어야 함

bool insertvalue(Bsearchnode **list, int value);
int comparefunc(const void* p, const void* q);

int main(void) {

    int n, i, j, buffer, compressed_cordinate_index = 0, zero_flag = 0, first = 0, last, mid;

    Bsearchnode *list = NULL;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &buffer);
        cordinate[i] = buffer;

        if (zero_flag == 0 && buffer == 0) {
            zero_flag++;
            compressed_cordinate_index++;
        }
        
        if (buffer != 0 && insertvalue(&list, buffer)) {
            compressed_cordinate[compressed_cordinate_index++] = buffer;
        }
        
    }

    qsort(compressed_cordinate, compressed_cordinate_index, sizeof(int), comparefunc);

    

    i = 0;
    first = 0;
    last = compressed_cordinate_index - 1;
    while (first <= last) {
        mid = (first + last) / 2;
        if (cordinate[i] == compressed_cordinate[mid]) {
            break;
        } else if (cordinate[i] < compressed_cordinate[mid]) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }
    printf("%d", mid);

    for (i = 1; i < n; i++) {
        first = 0;
        last = compressed_cordinate_index - 1;

        while (first <= last) {
            mid = (first + last) / 2;
            if (cordinate[i] == compressed_cordinate[mid]) {
                break;
            } else if (cordinate[i] < compressed_cordinate[mid]) {
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }
        printf(" %d", mid);

    }

    return 0;
}


bool insertvalue(Bsearchnode **list, int value) {
    int i = 1;
    Bsearchnode *p;
    Bsearchnode *newnode = (Bsearchnode*) malloc(sizeof(Bsearchnode));
    newnode->value = value;
    newnode->left = NULL;
    newnode->right = NULL;

    if (*list == NULL) {
        *list = newnode;
        return true;
    }

    p = *list;

    while (true) {

        if (p->value == value) {
            return false;
        } else if (p->value < value) {
            if (p->right == NULL) {
                p->right = newnode;
                return true;
            } else {
                p = p->right;
            }
        } else {
            if (p->left == NULL) {
                p->left = newnode;
                return true;
            } else {
                p = p->left;
            }
        }
    }
    
}




int comparefunc(const void* p, const void* q) {
    return *(int*)p - *(int*)q;
}

