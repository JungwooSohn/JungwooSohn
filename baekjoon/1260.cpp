#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;




int main(void) {

    int n, m, v;

    scanf("%d%d%d", &n, &m, &v);

    vector<int> graph[n + 1];

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    vector<int> stack;

    while (true) {
        if (graph[v].size() != 0) {
            printf("%d", v);
            int temp;
            printf(" %d", graph[v].back());
            graph[v].pop_back();
            break;
        }
    }
    
    
    

    

    return 0;
}