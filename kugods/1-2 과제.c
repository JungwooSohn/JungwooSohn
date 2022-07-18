#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void* data;
    struct node* next;
} Node;

int main(){
    Node* n1 = (Node*)malloc(sizeof(Node));
    Node* n2 = (Node*)malloc(sizeof(Node));
    // TODO

    int data1;
    char data2;

    scanf("%d %c", &data1, &data2);

    n1->data = &data1;
    n2->data = &data2;

    printf("%d %c", *(int*)n1->data, *(char*)n2->data);

    free(n1);
    free(n2);

    return 0;
}