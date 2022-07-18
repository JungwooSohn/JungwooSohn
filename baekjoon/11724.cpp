#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>

using namespace std;

bool comparefunc(int i, int j);

int main(void) {

    int n, m, v = 1, current_point, temp, count = 0, a, b;

    scanf("%d%d", &n, &m);

    vector<int> graph2[n + 1];

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        graph2[a].push_back(b);
        graph2[b].push_back(a);
    }




    queue<int> queue;

    current_point = 1;
    int *is_printed2 = (int*) calloc(n + 1, sizeof(int));


    for (int i = 1; i <= n; i++) {
        if (!is_printed2[i]) {
            count++;
            current_point = i;
            is_printed2[current_point] = true;
            while (current_point != 0) {
                sort(graph2[current_point].begin(), graph2[current_point].end(), comparefunc);
                while (!graph2[current_point].empty()) {
                    if (!is_printed2[graph2[current_point].back()]) {
                        is_printed2[graph2[current_point].back()] = true;
                        queue.push(graph2[current_point].back());
                        graph2[current_point].pop_back();
                    } else {
                        graph2[current_point].pop_back();
                    }
                }

                if (!queue.empty()) {
                    current_point = queue.front();
                    queue.pop();
                } else {
                    break;
                }
            }
        }
    }





    
    printf("%d", count);
    return 0;
}

bool comparefunc(int i, int j) {
    return i > j;
}