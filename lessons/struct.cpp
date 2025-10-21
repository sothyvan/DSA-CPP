#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *next;
};

int main(){
    int n =10;
    // Node *head = nullptr;
    // Node *cur = nullptr;

    // for(int i = n; i > 0; i--){
    //     cur = new Node{i,head};
    //     head = cur;
    // }

    Node *first, *last, *newNode;

    for (int i = 0; i < n; i++){
        newNode = new Node;
        newNode->value = i;
        newNode->next = 
    }
    
    Node *print = first;
    while (print != nullptr){
        cout << print->value << " ";
        print = print->next;
    }

    return 0;
}