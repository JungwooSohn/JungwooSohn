#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>

using namespace std;

bool comparefunc(int i, int j);

int main(void) {

    int n, m, v, current_point, temp;

    scanf("%d%d%d", &n, &m, &v);

    vector<int> graph[n + 1];
    vector<int> graph2[n + 1];

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
        graph2[a].push_back(b);
        graph2[b].push_back(a);
    }

    int *is_printed = (int*) calloc(n + 1, sizeof(int));

    vector<int> stack;

    current_point = v;

    printf("%d", current_point);
    stack.push_back(current_point);
    is_printed[current_point] = true;
    sort(graph[current_point].begin(), graph[current_point].end(), comparefunc);

    if (graph[current_point].empty()) {
        stack.pop_back();
        current_point = 0;
    } else {
        temp = graph[current_point].back();
        graph[current_point].pop_back();
        current_point = temp;
    }

    while (current_point != 0) {
        
        if (!is_printed[current_point]) {
            printf(" %d", current_point);
            stack.push_back(current_point);
            is_printed[current_point] = true;
            sort(graph[current_point].begin(), graph[current_point].end(), comparefunc);
        }
        
        while (true) {
            if (graph[current_point].empty()) {
                if (!stack.empty()) {
                    current_point = stack.back();
                    stack.pop_back();
                    break;
                } else {
                    current_point = 0;
                    break;
                }
            }

            if (is_printed[graph[current_point].back()]) {
                graph[current_point].pop_back();
            } else {
                stack.push_back(current_point);
                temp = graph[current_point].back();
                graph[current_point].pop_back();
                current_point = temp;
                break;
            }
        }

    }

    free(is_printed);
    queue<int> queue;
    printf("\n%d", v);
    current_point = v;
    int *is_printed2 = (int*) calloc(n + 1, sizeof(int));
    is_printed2[v] = true;



    while (current_point != 0) {
        sort(graph2[current_point].begin(), graph2[current_point].end(), comparefunc);
        while (!graph2[current_point].empty()) {
            if (!is_printed2[graph2[current_point].back()]) {
                is_printed2[graph2[current_point].back()] = true;
                queue.push(graph2[current_point].back());
                printf(" %d", graph2[current_point].back());
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
    

    return 0;
}

bool comparefunc(int i, int j) {
    return i > j;
}