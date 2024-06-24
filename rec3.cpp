/* 
Name: Emilie Gunti 
Class: CSE310 Janaka Balasooriya
Description: this .cpp file implements a Priority Queue that has a flight landing system for recitation 3. Here, it uses the min_heap method to implement the program 
where landing requests are are added and removed. It also prints from the plane landing queue. Lastly, it exits the program. 
*/

#include <iostream>
#include <string>
using namespace std;

struct Plane{
    string flightNum;
    int waitTime;

    //default constructor
    Plane() {

    } 
    
    //overloaded constructor
    Plane( string num, int time) {
        flightNum = num;
        waitTime = time;
    }
};

class priorityQueue {

private:
    Plane* heap;
    int load;
    int size;
    

public:
    
    
    priorityQueue(int load) {
        load = load;
        size = 0;
        heap = new Plane[load];

    }

    ~priorityQueue() {
        delete[] heap;
    }

    //adds landing requests to queue 
    void addQueue (const Plane& flight) {
        if (size == load) {
            cout << "Queue is full, cannot add more plans to the queue. \n";
            return;
        }

        int ind = size;
        heap[ind] = flight;
        size++;

        while ( ind > 0 && (heap[parent(ind)].waitTime > heap[ind].waitTime) ) {
            Plane temp = heap[ind];
            heap[ind] = heap[parent(ind)];
            heap[parent(ind)] = temp;
            ind = parent(ind);


        }
    }
    //is used to remove landing requests from the queue
    Plane removeQueue() {
        if (size == 0) {
            cout << "Priority queue is currently empty, no element to remove from the queue. \n";
            return Plane("", 0);

        }

        Plane flight = heap[0];
        heap[0] = heap[size -1];
        size--;

        min_heapify(0);

        return flight;
    }

    //checks whether or not if the size is 0 or not
    bool isEmpty() {
        return size == 0;
    }


private:
    int parent(int val) {
        return (val - 1) / 2;
    }

    int leftC( int val) {
        return (2* val) + 1; 
    }

    int rightC (int val) {
        return (2 * val) + 2;
    }

    //heapify method to implement the program according to the algorithm
    void min_heapify( int val) {
        int least = val;
        int left = leftC(val);
        int right = rightC(val);

        if (left < size && heap[left].waitTime < heap[least].waitTime) {
            least = left;

        }

        if( right < size && heap[right].waitTime < heap[least].waitTime) {
            least = right;
        }

        if (least != val) {
            Plane temp = heap[val];
            heap[val] = heap[least];
            heap[least] = temp;
            min_heapify(least);
            
        }
    }
};

int main() {
    int load;
    cout << "Enter load for the queue: ";
    cin >> load;

    priorityQueue landQueue(load);

    int number;

    while(1) {
    cout << "          Welcome to the Plane Landing System          " << endl;
    cout << "1. Make a landing request" << endl;
    cout << "2. Land a Plane" << endl;
    cout << "3. List all the landing requests" << endl;
    cout << "4. Exit" << endl;
    cout << "Select your option: ";

    cin >> number;

    if ( number == 1) {
        string flightNum;
        int waitTime;
        cout << "Enter flight number: ";
        cin >> flightNum;
        cout << "Enter wait time, in minutes: ";
        cin >> waitTime;

        Plane flight(flightNum, waitTime);
        landQueue.addQueue(flight);
        
        

    }
    else if ( number == 2){
        if(landQueue.isEmpty()){
            cout << "No planes in the queue to land" << endl;
        }
        else{
            Plane nextFlight = landQueue.removeQueue();
            cout << "Landing plane " << nextFlight.flightNum << ", with waiting time " << nextFlight.waitTime << " minutes." << endl;
            
        }

        

    }
    else if( number == 3){
        if(landQueue.isEmpty()){
            cout << "No planes in the queue to land" << endl;
        }
        else{
            cout << "All landing requests:" << endl;
            priorityQueue queue = landQueue;
            while( !queue.isEmpty()){
                Plane plane = queue.removeQueue();
                cout << "Flight number, " << plane.flightNum << " with waiting time of " << plane.waitTime << " minutes" << endl;
            }
        }

    }
    else if (number == 4){
        cout << "Exiting program...";
        break;
        

    }
    else{ 
        cout << "Invalid option. Choose a valid option." << endl;
        cin.clear();
        while (cin.get() != '\n'){
            continue;
        }
    }

    }

    return 0;

}



