/*
  This work is licensed under the Creative Commons Attribution-NonCommercial-   NoDerivatives 4.0 International License. To view a copy of this license, vi   si t http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/
/*! \mainpage Concurrency Projet
 * \author Peter Lucan, 4th Year Software Development student at IT Carlow, C00228946, c00228956@itcarlow.ie
 * \date 25/02/2021
 * \copyright Creative Commons Attribution-NonCommercial- NoDerivatives 4.0 International License
 * \section desc_sec Decription
 *
 * Description: Concurrency Project. A parrallel Program which find and prints the twin prime numbers from 0 to a given number and also calculates the amount of prime numbers up to the given number. The user is first asked to input the number and then to input how many tasks they would like to execute the program with. This Program uses tasks. The functions used in this poject are in the utility.h header file and the rest is in the main.cpp file.
 *
 * \section dep_Sec Dependencies
 * gcc v 7.5.0 or greater
 * -pthread
 * Make
 *
 * \section install_sec Installation
 * run "make" in directory with code.
 *
 */

#include <iostream>
#include <thread>
#include <bits/stdc++.h>
#include <chrono>

#include "utility.h"

using namespace std;


int main(){
    // Variable Decelration and Initialisation
    uint64_t n = 0;
    uint64_t numOfThreads = 0;
    uint64_t numberOfPrimes = 0;
    double time = 0;
    double timeTwo = 0;
    double hr = 0;
    double min = 0;
    double sec = 0;
    uint64_t divider = 0;
    vector<future<uint64_t>> threads;

    
    // Enter the number and also the amount of threads you would like the program to run with.
    cout << "Enter Number N: " << endl;
    cin >> n;
    cout << "How many threads would you like to use? (Enter 0 for Sequential) " << endl;
    cin >> numOfThreads;

    //If 0 is entered for the number of threads this section containing sequential code is executed.
    if (numOfThreads == 0){

        auto start = chrono::steady_clock::now(); auto startTwo = chrono::steady_clock::now(); //Time that is now is saved in nano and miliseconds
        findPrimePairs(n);
        countPrimesSequential(n);
        auto end = chrono::steady_clock::now(); auto endTwo = chrono::steady_clock::now(); //Time that is now is saved in nano and miliseconds
        time = uint64_t (chrono::duration_cast<chrono::milliseconds>(end - start).count()); timeTwo = uint64_t (chrono::duration_cast<chrono::nanoseconds>(endTwo - start).count()); //Time is calulated in milliseconds and naoseconds for Sequential Code.
    }
    //Otherwise the parallel code is executed
    else { 
        
        auto start = chrono::steady_clock::now(); auto startTwo = chrono::steady_clock::now(); //Time that is now is saved in nano and miliseconds
        divider = n / numOfThreads;
        
        for (uint64_t i = 0; i < numOfThreads; i++){
            threads.push_back(async(countPrimes, i * divider, (i + 1) * divider));
        }   


        for (auto &t : threads){ 
            numberOfPrimes += t.get();
        }

        findPrimePairs(n);

        cout << "The Number of Prime Numbers up to: " << n << " is: " << numberOfPrimes << endl;
        auto end = chrono:: steady_clock::now(); auto endTwo = chrono::steady_clock::now(); //Time that is now is saved in nano and miliseconds
        time = uint64_t (chrono::duration_cast<chrono::milliseconds>(end - start).count()); timeTwo = uint64_t (chrono::duration_cast<chrono::nanoseconds>(endTwo - start).count()); //Time is calulated in milliseconds and naoseconds for Paralled code.
    }

    //Calculations to dispaly time in Hours, Minutes and Seconds
    hr = (time / (60 * 60 * 1000));
    min = time / 60000;
    sec = time / 1000;
    cout << "Execution time in: Hrs: "  << hr << endl; 
    cout << "Execution time in: Mins: "<< min << endl;
    cout << "Execution time in: Secs: "<< sec << endl;
    cout << "Execution time in: Miliseconds: " << time << endl;
    cout << "Execution time in: Nanoseconds: " << timeTwo << endl;
    return 0;
}