/*
 * Author: James Adams
 * Date: April 20, 2018
 * File: 8.cpp
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include<string>

using namespace std;

int sum(int group, int a[], int c) {
    int large = 0, sum = 0, k = 0, i = 0, moveI = 0;
    for (int y = 0; y < c - group; y++) {
        i = moveI;
      
        for (i; k <= group; i++) {
            sum += a[i];
            k++;
        }
        if (large < sum) {
            large = sum;
        }
        sum = 0;
        k = 0;
        moveI++;
    }
    return large;
}

int main(int argc, char*argv[]) {
    int j = 0;
    int x;
    
    ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1);
    }
    int a[100];
    while (inFile >> x) {
        a[j] = x;
        j++;
    }
    inFile.close();
    
    int c = a[0];
    int list[c];
    for (int i = 0; i < c; i++) {
        list[i] = a[i + 1];
        cout << list[i] << endl;
    }
    cout << endl;
    
    int max = 0;
    for (int i = 1; i < c - 1; i++) {
        int y = sum(i, list, c);
        if (max < y) {
            max = y;
        }
    }
    cout << "Maximum Sum is: " << max << endl;

    return 0;
}