/*! \class utility
    \brief Functions for the program.

   Contains all the functions for the program,

*/
#ifndef UTILITY_H
#define UTILITY_H
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <bits/stdc++.h>

using namespace std;


/*! \fn findPrimePairs
    \brief Finds and Prints the Twin Prime Pairs.

   Finds and Prints the Twin Prime Pairs using two for loops and two if statements.

*/
/*! displays the Twin Prime Pairs up to n*/
/**
 * The findPrimePairs function
 *
 * The number inputted by the user is supplied as a parameter to this function. Then the Twin Prime Pairs are found and printed.
 *
 * @param n Then number inputted by the user.
 */
void findPrimePairs(uint64_t n){
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    uint64_t count = 0;

    for (uint64_t i = 2; i * i <= n; i++){

        if (prime[i] == true) {

            for (uint64_t j = i * 2; j <= n; j += i){
                prime[j] = false;
                
            }
            
        }    
    }
    cout << "Twin Prime Pairs: \n";
    for (uint64_t i = 2; i <= n - 2; i++){
        if (prime[i] && prime[i + 2])
        cout << "(" << i << ", " << i + 2 << ")" ;
    }
    cout << "\n";

}

/*! \fn checkPrime
    \brief Checks which numbers are prime.

   Checks which numbers are prime and returns true for them.

*/
/*! checks for Prime Numbers up to n*/
/**
 * The checkPrime function
 *
 * The number inputted by the user is supplied as a parameter to this function. Then the numbers are checked up to n and true is returned for the ones that are prime.
 *
 * @param n Then number inputted by the user.
 */
bool checkPrime(uint64_t n){
        if (n <= 1){
            return false;
        }

        for (uint64_t i = 2; i < n; i++){
            if (n % i == 0){
                return false;
            }
        }
        return true;
    }
    
/* This method is a lot faster to calucate the prime Numbers but reqiures to change the code to use long long variabes.
bool checkPrime(uint64_t n){
        if (n <= 1){
            return false;
        }
        if (n <= 3){
            return true;
        }

        if(n % 2 == 0 || n % 3 == 0){
            return false;
        }

        for (uint64_t i = 5; i * i <= n; i = i + 6){
            if (n % i == 0 || n % (i + 2) == 0){
                return false;
            }
        }
        return true;
    }
*/


/*! \fn countPrimes
    \brief Checks which numbers are prime (Used by Parallel Code).

   Counts numbers that are prime and returns the total.

*/
/*! Counts the prime numbers from start to end*/
/**
 * The countPrimes function
 *
 * This function is run in parallel as each tasks specifies where calculation should start and finish counting the prime numbers of a given input. This splits having to count the primes of a large number into tasks where each task checks and counts a part of the large input number.
 *
 * @param start Specifies where calculation of Prime Numbers should Begin.
 * @param end Specifies where calculation of Prime Numbers should End.
 */
uint64_t countPrimes(uint64_t start, uint64_t end){
    uint64_t total = 0;

    if (start == 0){
        start = 2;
    }

    for (uint64_t i = start; i <= end; i++){
        if(checkPrime(i)){
            total++;
        }
    }

    return total;
}


/*! \fn checkPrimeSequential
    \brief Checks which numbers are prime. (Used by Sequential code).

   Checks which numbers are prime and returns true for them.

*/
/*! checks for Prime Numbers up to n*/
/**
 * The checkcheckPrimeSequentialPrime function
 *
 * The number inputted by the user is supplied as a parameter to this function. Then the numbers are checked up to n and true is returned for the ones that are prime.
 *
 * @param n Then number inputted by the user.
 */
bool checkPrimeSequential(uint64_t n){
        if (n <= 1){
            return false;
        }

        for (uint64_t i = 2; i < n; i++){
            if (n % i == 0){
                return false;
            }
        }
        return true;
    }


/*! \fn checkPrimeSequential
    \brief Checks which numbers are prime (Used by Sequential Code).

   Counts numbers that are prime and returns the total.

*/
/*! Counts the prime numbers up to n*/
/**
 * The checkPrimeSequential function.
 *
 * This function Counts the prime numbers up to n and prints the total.
 *
 * @param n Then number inputted by the user
 */
void countPrimesSequential(uint64_t n){
    uint64_t total = 0;

    for (uint64_t i = 2; i <= n; i++){
        if(checkPrime(i)){
            total++;
        }
    }

    cout << "The Number of Prime Numbers up to: " << n << " is: " << total << endl;
}
#endif