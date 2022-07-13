#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int n, m, i, j, count = 0, k, max, hamming_distance = 0;
    char max_dna;
    int dna[4] = {0,};

    scanf("%d%d", &n, &m);

    char **list = (char**) malloc(sizeof(char*) * n);
    char *target_string = (char*) malloc(sizeof(char) * (m + 1));

    int *hamming_distance_list = (int*) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        list[i] = (char*) malloc(sizeof(char) * (m + 1));
    }

    getchar();

    for (i = 0; i < n; i++) {
        scanf("%s", list[i]);
    }

    for (j = 0; j < m; j++) {
        for (i = 0; i < 4; i++) {
            dna[i] = 0;
        }

        for (i = 0; i < n; i++) {
            switch(list[i][j]) {
                case 'A':
                    dna[0]++;
                    break;
                case 'C':
                    dna[1]++;
                    break;
                case 'G':
                    dna[2]++;
                    break;
                case 'T':
                    dna[3]++;
                    break;
            }
        }

        max = dna[0];
        max_dna = 'A';
        count = n - dna[0];
        for (int k = 1; k < 4; k++) {
            if (dna[k] > max) {
                max = dna[k];
                switch(k) {
                    case 1:
                        max_dna = 'C';
                        count = n - dna[1];
                        break;
                    case 2:
                        max_dna = 'G';
                        count = n - dna[2];
                        break;
                    case 3:
                        max_dna = 'T';
                        count = n - dna[3];
                        break;
                    default:
                        break;
                }
            } 
        }

        target_string[j] = max_dna;
        hamming_distance += count;

    }


    
    target_string[m] = '\0';
    printf("%s\n%d", target_string, hamming_distance);



    return 0;
}