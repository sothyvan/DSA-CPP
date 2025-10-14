#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;

        //Constructor
        Node(int value){
            data = value;
            next = nullptr;
        }
};

class Linkedlist{
    private:
        Node *head, *tail;
        int counter;
    
    public:
        //Constructor
        Linkedlist(){
            head = nullptr;
            tail = nullptr;
            counter = 0;
        }
        // Destructor (prevents memory leaks)
        ~Linkedlist() {
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }

        //Methods = functions
        //Challenge 1
        void insertFront(int value){
            Node* newNode = new Node{value};
            newNode->next = head;
            head = newNode;

            //if the list is empty
            if(tail == nullptr){
                tail = newNode;
            }
            counter++;
        }

        //Challenge 2
        void insertEnd(int value){
            Node* newNode = new Node{value};
            if (head == nullptr){
                //First Node
                head = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
            counter++;
        }

        //Challenge 3
        void insertAtPosition(int value, int pos){
            if (pos < 0 || pos > counter){
                cout << "Out of Bound!!" << endl;
                return;
            }
            if (pos == 0){
                insertFront(value);
                return;
            }
            if (pos == counter) {
                insertEnd(value);
                return;
            }
            Node *newNode = new Node{value};
            Node *cur = head;
            for(int i = 0; i < pos-1; i++){
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
            counter++;
        }

        //Challenge 4
        void deleteFront(){
            if (head == nullptr) {
                cout << "Empty!!" << endl;
                return;
            }
            Node *cur = head;
            head = head->next;
            if (head == nullptr) tail = nullptr; // if list becomes empty
            delete cur;
            counter--;
        }

        //Challenge 5
        void deleteEnd(){
            if (head == nullptr){
                cout << "Empty!!" << endl;
                return;
            }
            if (counter == 1){
                delete head;
                head = nullptr;
                tail = nullptr;
                counter--;
                return;
            }
            Node *cur = head;
            //Traverse to second to last Node
            while (cur->next != tail){
                cur = cur->next;
            }
            delete tail;
            tail = cur;
            tail->next = nullptr;
            counter--;
        }

        //Challenge 6
        void deleteAtPosition(int pos){
            if (pos < 0 || pos >= counter){
                cout << "Out of Bound!!" << endl;
                return;
            }
            if (head == nullptr){
                cout << "Empty!!" << endl;
                return;
            }
            if (pos == 0) {
                deleteFront();
                return;
            }

            Node *cur = head;
            for(int i = 0; i < pos-1; i++){
                cur = cur->next;
            }
            Node *temp = cur->next;
            cur->next = temp->next;

            //Update tail if we're deleting the last node
            if (temp == tail){
                tail = cur;
            }
            delete temp;
            counter--;
        }

        //Challenge 7
        void printList(){
            if(counter == 0){
                cout << "Empty!!" << endl;
                return;
            }
            Node *cur = head;
            while(cur != nullptr){
                cout << cur->data << "->";
                cur = cur->next; 
            }
            cout << "nullptr" << endl;
        }

        //Challenge 8
        void swapNodes(int pos1, int pos2){
            if (pos1 < 0 || pos2 < 0 || pos1 >= counter || pos2 >= counter){
                cout << "Out of bound!!" << endl;
                return;
            }
            if (pos1 == pos2){
                return;
            }
            //Find nodes and their previous nodes
            Node *node1 = head, *prev1 = nullptr;
            Node *node2 = head, *prev2 = nullptr;

            for (int i = 0; i < pos1; i++){
                prev1 = node1;
                node1 = node1->next;
            }
            for (int i = 0; i < pos2; i++){
                prev2 = node2;
                node2 = node2->next;
            }

            //If node1 or node2 is head
            if (prev1 != nullptr){
                prev1->next = node2;
            }else{
                head = node2;
            }

            if(prev2 != nullptr){
                prev2->next = node1;
            }else{
                head = node1;
            }

            //Swap pointers
            Node *temp = node1->next;
            node1->next = node2->next;
            node2->next = temp;

            //Update tail if needed
            if (node1->next == nullptr){
                tail = node1;
            }
            if (node2->next == nullptr){
                tail = node2;
            }
        }

        //Challenge 9
        void searchValue(int target){
            Node *cur = head;
            bool found = 0;
            for(int i = 0; i < counter; i++){
                if(cur->data == target){
                    cout << "Target Found!! At index " << i << endl;
                    found = 1;
                    return;
                }
                cur = cur->next;
            }
            if (!found){
                cout << "Target Not Found!!" << endl;
            }
        }

};

int main (){
    Linkedlist list;
    int arr[4] = {1,2,3,4};

    list.insertFront(1);
    list.insertFront(2);
    list.insertFront(3);
    list.insertFront(4);
    list.insertAtPosition(5,2);
    list.swapNodes(3,2);
    list.searchValue(5);
    list.deleteAtPosition(2);
    list.deleteFront();
    list.deleteEnd();
    list.printList();


    return 0;
}
