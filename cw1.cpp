#include <iostream>
using namespace std;

void menu();
void create_array(int *&arr, int &n);
void display_array(int *arr, int n);
void insert_element(int *&arr, int &n);
void delete_element(int *&arr, int &n);

int main(){
    
    int *arr = nullptr;   
    int num_element = 0;
    int option = 0;

    do{
        menu();
        cout << "Select an option: ";
        cin >> option;
        switch (option)
        {
            case 1:
                create_array(arr, num_element);
                break;
            case 2:
                display_array(arr, num_element);
                break;
            case 3:
                insert_element(arr, num_element);
                break;
            case 4:
                delete_element(arr, num_element);
                break;
            case 5:
                cout << "Bye bye";
                break;
            
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }while (option != 5);

    delete[] arr;

    return 0;
}

void menu(){
    cout << "\n1. Create a New Array.\n";
    cout << "2. Display Array.\n";
    cout << "3. Insert New Element.\n";
    cout << "4. Delete an Element.\n";
    cout << "5. Exit.\n";
}

void create_array(int *&arr, int &n){

    //to make sure that there is only 1 array
    if (arr != nullptr){
        delete[] arr;
    }

    cout << "Enter the size of the array: ";
    cin >> n;
    if (n <= 0){
        cout << "Invalid size! Size must be positive and greater than 0!";
        n = 0;
        return;
    }

    arr = new int[n];
    for(int i = 0; i < n; i++){
        cout << "Enter the number for index " << i << ": ";
        cin >> arr[i];
    }
}

void display_array(int *arr, int n){
    if (arr == nullptr || n == 0){
        cout << "Array is empty!\n";
        return;
    }

    cout << "Array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

void insert_element(int *&arr, int &n){
    int value, pos;
    cout << "Enter the value: ";
    cin >> value;
    cout << "Enter the position (0 to "<< n <<"): ";
    cin >> pos;

    if (pos > n || pos < 0){
        cout << "Invalid position!\n";
        return;
    }
    int *new_arr = new int[n+1];
    for (int i = 0; i < n+1; i++){
        if (i < pos){
            new_arr[i] = arr[i];
        } else if(i == pos){
            new_arr[i] = value;
        } else{
            new_arr[i] = arr[i-1];
        }
    }
    delete[] arr;
    arr = new_arr;
    n++;
}

void delete_element(int *&arr, int &n){
    if (n == 0){
        cout << "Array is empty!";
        return;
    }

    int pos;
    cout << "Enter the position to delete (0 to "<< n-1 <<"): ";
    cin >> pos;

    if (pos > n-1 || pos < 0){
        cout << "Invalid position!";
        return;
    }

    int *new_arr = new int[n-1];
    for (int i = 0; i < n; i++){
        if (i < pos){
            new_arr[i] = arr[i];
        } else if (i == pos){
            continue;
        } else{
            new_arr[i-1] = arr[i];
        }
    }
    delete[] arr;
    arr = new_arr;
    n--;
}