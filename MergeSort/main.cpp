//
//  main.cpp
//  A recursive MergeSort algorithm
//
//  Created by Melinda Fernandes on 24/03/2017.
//  Copyright © 2017 Melinda Fernandes. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>
using std::srand;
using std::rand;

#include <ctime>
using std::time;

#include <vector>
using std::vector;

// function declarations
// & passing my reference to allow modifications
void mergeSort(vector<int> &);
void merge(vector<int> &, vector<int> &, vector<int> &);

int main(){
    
    // declare a vector of size 10
    const int size = 10;
    vector<int> a(size);

    srand(time(0));     // seed random no. generator using current time
    
    // fill vector with random elements 0 - 99
    cout << "original vector: ";
    for (int i = 0; i < size; i++){
        a[i] = (rand() % 100);
        
        // print elements of array on one line
        cout << a[i] << "  ";
    }
    
    cout << endl;
    
    // sort vector using mergesort
    mergeSort(a);
    
    cout << "sorted vector: ";
    // print out sorted vector on one line
    for (int i = 0; i <size; i++)
        cout << a[i] << "  ";
    
    cout << endl;
    
    return 0;
    
} // end main

void mergeSort(vector<int> &myVector){
    
    int n = myVector.size();   // use iterator functions to determine length of vector
    
    if(n<2)
        return;     // base case, n=1, sorted
    
    int mid = n/2;          // identify midpoint
    vector<int> left(mid);     // intialise empty vector for first half and
    vector<int> right(n-mid);    // second half
    
    // fill left vector with first half of full vector
    for(int i = 0; i < mid; i++){
        left[i] = myVector[i];
    }
    // fill right vector with second half of full vector
    int k = 0;
    for(int i = mid; i < n; i++){
        right[k] = myVector[i];
        k++;
    }
    
    // recursive calls executing mergesort(splitting vectors into L and R)
    // previous states of execution are paused while this is done
    mergeSort(left);
    mergeSort(right);
    
    merge(left, right, myVector);      // once mergesort executions have reached the end of their paths, merge executes
    
} // end mergesort function

// function that performs merge, bottom-up
void merge(vector<int> &left, vector<int> &right, vector<int> &vec){
    
    int sizeOfL = left.size();
    int sizeOfR = right.size();
    int i = 0;      // index of smallest unpicked in left
    int j = 0;      // index of smallest unpicked in right
    int k = 0;      // index of position to be filled in vector
    
    // traverse through left and right vectors, comparing and merging
    while(i < sizeOfL && j < sizeOfR){
        if(left[i] <= right[j]){
            vec[k] = left[i];     // overwrite value at k in original vector w/ smallest value
            i++;        // increment i
        }
        else{
            vec[k] = right[j];    // as above but if right value is smallest
            j++;        // increment j
        }
        k++;    // position at k has been filled, increment k
    } // end while
    
    // if one half is unfinished at the end of above comparisons,
    // overwrite rest of vector with rest of values in unfinished half.
    // At most, one of the nest two while loops will execute
    while(i < sizeOfL){
        vec[k] = left[i];     // overwrite rest of vector
        i++;    // increment i
        k++;    // increment k
    }
    while(j < sizeOfR){
        vec[k] = right[j];    // overwrite rest of vector
        j++;    // increment j
        k++;    // increment k
    }
    
} // end merge








