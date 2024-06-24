/* name: Emilie Gunti
teacher: Janaka Balasooriya
recitation 2: run times of the sorting algorithms according to the textbook, the following code sorts a random array according to the given size
and sorts each one, returns the running time of each sorted algorithm*/


#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void insertionSort(double array[], int n);
void selectionSort(double array[], int n);
void quickSort(double array[], int n);
void mergeSort(double array[], int n);
void randomGen(double array[], int n);

void insertionSort(double array[], int n){
    for (int i = 1; i < n; i++){
        double k = array[i];
        int j = i-1;
        while (array[j] > k && j>= 0){
            array[j+1] = array[j];
            j--;
        }
    
    array[j+1] = k ;
    }
}
//change
void selectionSort( double array[], int n){
    for ( int i = 0; i < n-1; i++){
        int indexMin = i;
        for (int j = i+1; j<n; j++){
            if(array[j] < array[indexMin]){
                indexMin = j;
            }
        }
        if (indexMin != i) {
            double val = array[i];
            array[i] = array[indexMin];
            array[indexMin] = val;
        }
    }

}
int partition( double array[], int low, int high){
    double s = array[high];
    int i = (low -1);

    for(int j = low; j <= high - 1; j++){
        if ( array[j] < s) {
            i++;
            double var = array[i];
            array[i] = array[j];
            array[j] = var;
        }
    }

    double var = array[i +1];
    array[i +1] = array[high];
    array[high] = var; 
    return i +1;

}


void quickSort( double array[], int low, int high){
    if (low < high){
        int p = partition (array, low, high);

        quickSort(array, low, p-1);
        quickSort(array, p+1, high);
    }

}


void merge(double array[], int left, int mid, int right){
    int num1 = mid - left +1;
    int num2 = right - mid;
    double leftArray[num1], rightArray[num2];

    for (int i = 0; i < num1; i++){
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < num2; j++){
        leftArray[j] = array[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < num1 && j < num2){
        if( leftArray[i] <= rightArray[j]){
            array[k] = leftArray[i];
            i++;
        }
        else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < num1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < num2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort( double array[], int left, int right){
    if (left < right){
        int mid = left + (right - left)/2;
        mergeSort(array, left, mid);
        mergeSort(array, mid +1, right);
        merge(array, left, mid, right);

    }

}

void randomGen( double array[], int n){
    for (int i = 0; i < n; i++){
        array[i] = 100.00 +(rand() % (1000-100 +1));
    }
}


int main() {
    const int arraySize = 10000;
    double array[arraySize];

    //generate random array
    randomGen(array, arraySize);

    //Insertion sort
    double insertionArray[arraySize];
    copy (array, array +arraySize, insertionArray);

    clock_t startInsertion = clock();
    insertionSort(insertionArray, arraySize);
    clock_t endInsertion = clock();

    double insertionTime = (double) (endInsertion - startInsertion)/ CLOCKS_PER_SEC;

    //Selection sort
    double selectionArray[arraySize];
    copy(array, array +arraySize, selectionArray);

    clock_t startSelection = clock();
    selectionSort(selectionArray, arraySize);
    clock_t endSelection = clock();

    double selectionTime = (double)(endSelection - startSelection) / CLOCKS_PER_SEC;

    //Quick sort
    double quickArray[arraySize];
    copy(array, array + arraySize, quickArray);

    clock_t startQuick = clock();
    quickSort(quickArray, 0, arraySize -1);
    clock_t endQuick = clock();

    double quickTime = (double)(endQuick - startQuick) / CLOCKS_PER_SEC;

    //merge sort
    double mergeArray[arraySize];
     copy(array, array + arraySize, mergeArray);

    clock_t startMerge = clock();
    mergeSort(mergeArray, 0, arraySize -1);
    clock_t endMerge = clock();

    double mergeTime = (double)(endMerge - startMerge) / CLOCKS_PER_SEC;

    //output running times
    cout << "Insertion sort time: " << insertionTime * 1000 << " milliseconds" << endl;
    cout << "Selection sort time: " << selectionTime * 1000 << " milliseconds" << endl;
    cout << "Quick sort time: " << quickTime * 1000 << " milliseconds" << endl;
    cout << "Merge sort time: " << mergeTime * 1000 << " milliseconds" << endl;

return 0;

}