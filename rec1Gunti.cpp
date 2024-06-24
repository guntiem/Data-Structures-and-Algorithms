/*Author: Emilie Gunti , CSE310
Date: 05/22/2023
Assignment description: This is recitation 1 assignment of a linked list that takes user input to add city name, population, and income and adds it to a record, adds to head, adds to tail, 
displays largest city income, displays all city records, and finally exits.*/


#include <iostream>
#include <string>
#include <limits>
using namespace std;

//Node class
struct Node{
    string name;
    int pop;
    int inc;
    Node* next;

};

//Linked list class with the head and tail, and all the methods that are used.
class Linkedlist{
    private:
    Node* head;
    Node* tail;

    public: 
    Linkedlist() {
        head = NULL;
        tail = NULL;

    }

    void insertNodeTail( string name, int pop, int inc);
    void insertNodeHead( string name, int pop, int inc);
    void displayLargest();
    void printAll();
};

//method to insert the name, population, and income at the tail of the linked list.
void Linkedlist::insertNodeTail( string name, int pop, int inc) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->pop = pop;
    newNode->inc = inc;
    
    if (head == NULL){
       // head = newNode;
        tail = newNode;
    }
    else {
    newNode->name = name;
    newNode->pop = pop;
    newNode->inc = inc;
    Node* temp = head;

    

    while( temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    tail = newNode;

    
    }
    cout << "Record added at the tail." << endl;
}

//method to insert the name, population, and income at the head of the linked list.
void Linkedlist:: insertNodeHead( string name, int pop, int inc){
    Node* newNode = new Node;
    newNode-> name = name;
    newNode-> pop = pop;
    newNode-> inc= inc;
    newNode-> next = head;
    head = newNode;

    if (tail == NULL) {
        tail = newNode;
    }
    else {
        head->next = tail;
    }

    cout << "Record added at the head." << endl;
}

//method to display the largest city population wise
void Linkedlist::displayLargest(){
    if (head == NULL) {
        cout << "No city records." << endl;
        return;
    }

    Node* temp = head;
    int hold = temp->pop;
    Node* x = temp;

    

    while ( temp->next != NULL){
        if (temp->next->pop > hold){
            hold = temp->next->pop;
            x = temp->next;
        }
        temp = temp->next;
    }
    
    cout << "Largest city record: " << x->name << ", " << x->pop << ", $" << x->inc << endl;
}

//method to print all records
void Linkedlist::printAll(){
    if (head == NULL && tail == NULL) {
        cout << "No city records" << endl;

        return;
    }

    cout << "All city records:" << endl;

    Node* curr = head;
    if (curr == NULL){
        cout<<"Entered here";
        curr = tail;
        cout << "City: " << curr->name << endl;
        cout << "Population: " << curr->pop << endl;
        cout << "Income: $" << curr->inc << endl;
         
    }
    else{

    while (curr != NULL) {
        cout << "City: " << curr->name << endl;
        cout << "Population: " << curr->pop << endl;
        cout << "Income: $" << curr->inc << endl;

        curr = curr->next;
    }
    }
}
//main method which takes input user and accordingly goes to the method in the Linkedlist.
int main() {
    Linkedlist recordList;
    int number;
    string name;
    int pop, income;

    //while loop to take the input user as long as it is true, with if-statements directing to each method in the Linkedlist.
    while (1) {
        cout << "Select an option below:" << endl;
        cout << "1. Add city record at the tail." << endl;
        cout << "2. Add city record at the head." << endl;
        cout << "3. Display the city with largest population." << endl;
        cout << "4. Display all the city records. " << endl;
        cout << "5. Exit." << endl;

        cin >> number;

        if (number == 1) {
            cout << "Enter city name: ";
            cin >> name;

            cout << "Enter the city's population (just numbers): ";
            cin >> pop;
            while (std::cin.fail() == true){
                cout<< "Invalid input, please enter a number." << endl;
                cin.clear();
                while(cin.get() != '\n'){
                continue;
                }
            }
            cout << "Enter the median income (just numbers): ";
            cin >> income;
            while (std::cin.fail() == true){
                cout<< "Invalid input, please enter a number." << endl;
                cin.clear();
                while(cin.get() != '\n'){
                continue;
                }
            }
            recordList.insertNodeTail(name, pop, income);
            


        }
        else if (number == 2){
            cout << "Enter city name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter the city's population (just numbers): ";
            cin >> pop;
            while (std::cin.fail() == true){
                cout<< "Invalid input, please enter a number.";
                cin.clear();
                while(cin.get() != '\n'){
                break;
                }
            }
            
            cout << "Enter the median income (just numbers): ";
            cin >> income;
            while (std::cin.fail() == true){
                cout<< "Invalid input, please enter a number." << endl;
                cin.clear();
                while(cin.get() != '\n'){
                break;
                }
            }
            
            recordList.insertNodeHead(name, pop, income);
            
        }
        else if ( number == 3) {
            recordList.displayLargest();

        }
        else if ( number == 4) {
            recordList.printAll();

        }
        else if ( number == 5) {
            cout << "Exiting program... ";
            break;

        }
        else {
            cout << "Invalid option. Please enter a valid number." << endl;
            cin.clear();
            while(cin.get() != '\n'){
            continue;
            }
        }
    }

    return 0;
}