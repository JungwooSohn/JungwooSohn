#include <stdio.h>
#include <stdlib.h>
int compare(const void* argu1, const void* argu2){
return *(int*)argu1 - *(int*)argu2;
}
int main(){
int arr[10] = {5, 2, 9, 7, 8, 1, 3, 4, 2, 0};
for(int i = 0; i < sizeof(arr) / sizeof(int); ++i){
printf("%d ", arr[i]);
}
printf("\n");
qsort(arr, 10, sizeof(int), compare);
for(int i = 0; i < sizeof(arr) / sizeof(int); ++i){
printf("%d ", arr[i]);
}
printf("\n");
return 0;
}