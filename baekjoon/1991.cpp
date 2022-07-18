#include <iostream>

using namespace std;

typedef char T;
typedef struct node {
    T value;
    struct node *left;
    struct node *right;
} Node;


Node* makenode(T newvalue);
void push_node(Node *parentnode, T newvalue, T key, int count);
void preorderfind(Node *parentnode, Node **pos_node ,T key);
void Printpreorder(Node *parentnode);
void Printpostorder(Node *parentnode);
void PrintInorder(Node *parentnode);

int main(void) {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    char temp = '\0', parent_value;
    int n;
    cin >> n;

    cin >> parent_value;
    Node* parentnode = makenode(parent_value);


    for (int i = 0; i < n; i++) {
        if (i != 0) {
            cin >> parent_value;
        }
        
        for (int j = 0; j < 2; j++) {
            cin >> temp;
            if (temp != '.') {
                push_node(parentnode, temp, parent_value, j);
            }
        }
    }

    Printpreorder(parentnode);
    cout << '\n';
    PrintInorder(parentnode);
    cout << '\n';
    Printpostorder(parentnode);
    cout << endl;
    


    return 0;
}

Node* makenode(T newvalue) {
    Node* newnode = new Node;
    newnode->value = newvalue;
    newnode->left = nullptr;
    newnode->right = nullptr;

    return newnode;
}

void push_node(Node *parentnode, T newvalue, T key, int count) {
    Node *pos_node = parentnode;


    preorderfind(parentnode, &pos_node, key);
    if (pos_node->value == key) {
        if (count == 0) {
            pos_node->left = makenode(newvalue);
        } else {
            pos_node->right = makenode(newvalue);
        }
    }
}

void preorderfind(Node *parentnode, Node **pos_node, T key) {
    static bool found;
    if (parentnode == *pos_node) {
        found = false;
    }
    

    if (parentnode) {
        if (parentnode->value == key) {
            found = true;
            *pos_node = parentnode;
            return;
        } else {
            if (!found) {
                preorderfind(parentnode->left, pos_node, key);
            }
            if (!found) {
                preorderfind(parentnode->right, pos_node, key);
            }
        }
    }
}

void Printpreorder(Node *parentnode) {
    if (parentnode) {
        cout << parentnode->value;
        Printpreorder(parentnode->left);
        Printpreorder(parentnode->right);
    }
}

void Printpostorder(Node *parentnode) {
    if (parentnode) {
        Printpostorder(parentnode->left);
        Printpostorder(parentnode->right);
        cout << parentnode->value;
    }
}

void PrintInorder(Node *parentnode) {
    if (parentnode) {
        PrintInorder(parentnode->left);
        cout << parentnode->value;
        PrintInorder(parentnode->right);
    }
}