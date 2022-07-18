#include <iostream>
#include <vector>

using namespace std;

void find_parent(int current_node_index, vector<int> graph[], int parentnode[]);

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);


    int n, temp1, temp2;

    cin >> n;

    vector<int> graph[n + 1];
    int parentnode[n + 1];

    for (int i = 0; i < n - 1; i++) {
        cin >> temp1 >> temp2;
        graph[temp1].push_back(temp2);
        graph[temp2].push_back(temp1);
    }

    find_parent(1, graph, parentnode);

    for (int i = 2; i <= n - 1; i++) {
        cout << parentnode[i] << '\n';
    }

    cout << parentnode[n] << endl;

    return 0;
}

void find_parent(int current_node_index, vector<int> graph[], int parentnode[]) {
    if (!graph[current_node_index].empty()) {
        int temp;
        for (int i = 0; i < graph[current_node_index].size(); i++) {
            parentnode[graph[current_node_index][i]] = current_node_index;

            for (int j = 0; j < graph[graph[current_node_index][i]].size(); j++) {
                if (graph[graph[current_node_index][i]][j] == current_node_index) {
                    temp = j;
                    break;
                }
            }

            graph[graph[current_node_index][i]].erase(graph[graph[current_node_index][i]].begin() + temp);
        }

        for (int i = 0; i < graph[current_node_index].size(); i++) {
            find_parent(graph[current_node_index][i], graph, parentnode);
        }

    }
}
/*
void find_parent(int current_node_index, vector<int> graph[], int parentnode[]) {
    if (!graph[current_node_index].empty()) {
        int temp;
        parentnode[graph[current_node_index].back()] = current_node_index;

        for (int i = 0; i < graph[graph[current_node_index].back()].size(); i++) {
            if (graph[graph[current_node_index].back()][i] == current_node_index) {
                temp = i;
                break;
            }
        }
        graph[graph[current_node_index].back()].erase(graph[graph[current_node_index].back()].begin() + temp);

        if (graph[current_node_index].size() > 1) {
            parentnode[graph[current_node_index].front()] = current_node_index;

            for (int i = 0; i < graph[graph[current_node_index].front()].size(); i++) {
                if (graph[graph[current_node_index].front()][i] == current_node_index) {
                    temp = i;
                    break;
                }
            }
            graph[graph[current_node_index].front()].erase(graph[graph[current_node_index].front()].begin() + temp);
        }
        

        find_parent(graph[current_node_index].back(), graph, parentnode);
        if (graph[current_node_index].size() > 1) {
            find_parent(graph[current_node_index].front(), graph, parentnode);
        }
        
    }   
}

*/