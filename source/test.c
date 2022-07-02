#include <stdio.h>
#include <stdlib.h>


int cordinate[1000000] = {0,}; // 전부 저장
int compressed_cordinate[1000000] = {0,}; // 겹치지 않게 저장 <- 정렬되어야 함


int comparefunc(const void* p, const void* q);
void creheap(int *arr2, int key, int input);

int main(void) {

    int n, i, j, buffer, compressed_cordinate_index = 0, zero_flag = 0, first = 0, last, mid;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &buffer);
        cordinate[i] = buffer;

        if (zero_flag == 0 && buffer == 0) {
            zero_flag++;
            compressed_cordinate_index++;
        }

        // 기존에 겹치는 게 있는지 검사
        for (j = 0; j < compressed_cordinate_index; j++) {
            if (compressed_cordinate[j] == buffer) {
                break;
            }
        }

        // 겹쳤다면 넣지 않고, 안 겹쳤다면 넣음
        if (j == compressed_cordinate_index) {
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

int comparefunc(const void* p, const void* q) {
    return *(int*)p - *(int*)q;
}

void creheap(int *arr2, int key, int input) {
	arr2[key] = input;
	while (key > 1) {
		if (arr2[key] < arr2[key / 2]) {
			swap(arr2[key], arr2[key / 2]);
			key /= 2;
		}
		else break;
	}
}