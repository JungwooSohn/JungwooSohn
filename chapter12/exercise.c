/*
1.
a) 12
b) 34
c) 4
d) true
e) false

3.reversed
*/
/*
4.
int *top_ptr;

void make_empty(void)
{
  top_ptr = &contents[0];
}

bool is_empty(void)
{
  return top_ptr == &contents[0];
}

bool is_full(void)
{
  return top_ptr == &contents[STACK_SIZE];
}

5.
a, ilegal
b, legal, true
c, legal, true
d, legal
*/


int sum_array(const int a[], int n) {
    int sum = 0;
    int *p;

    for(p = a; p < a + n, p++) {
        sum += *p;
    }

    return sum;

}

bool search(const int a[], int n, int key) {
    int *p;

    for(p = a; p < a + n; p++) {
        if (*p == key) {
            return true;
        }
    }
    return false;
}

void store_zeros(int a[], int n) {
    int *p;

    for(p = a; p < a + n; p++) {
        *p = 0;
    }
}


double inner_product(const double *a, const double *b, int n) {
    int sum = 0;
    int *p = a;
    
    for(;p < a + n;) {
        sum += *p++ * *b++;
        
    }

    return sum;
}

int* find_middle(int arr[], int size)
{
    return (arr + size / 2);
}


int find_largest(int array[], int size)
{
    int max;
    int *p = array;

    max = *array;
    for (p = array;p < array + size; array++) {
        if (*p > max) {
            max = *p;
        }
    }

    return max;
}

void find_two_largest(const int* a, int n, int *largest, int *second_largest) {
    int *p;
    *largest = *p;
    *second_largest = *p;
    for(p = a; p < a + n; p++) {
        if(*p >= *largest) {
            *second_largest = *largest;
            *largest = *p;
        } else if (*p >= *second_largest) {
            *second_largest  = *p;
        }
    }
}

search(temperature[0], 24 * 7, 32);

int *p;

for(p = &temeperature[i];p < temperature[i][0] + 24; p++){
    printf("%d ", *p++);
}

for(i = 0, i < 7; ++i)
find_largest(temperatures[i], 24);

int sum_two_dimensional_array(const int a[][LEN], int n) {
    int sum = 0;
    int *p;

    for(p = a[0];p < a + n * LEN; p++) {
        sum += *p;
    }

    return sum;
}
