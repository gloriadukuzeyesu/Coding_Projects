/*
  Author: Daniel Kopta and ??
  July 2017
  
  CS 6010 Fall 2019
  Vector util library definitions
  Complete the functions defined in this file.
  Some basic tests for your library are provided in VectorTest.cpp.
  Compile the tests together with your library using the following command:
  clang++ -std=c++11 VectorTest.cpp VectorUtil.cpp
  Most of the provided tests will fail until you have provided correct
  implementations for the VectorUtil library functions.
  You will need to provide more thorough tests.
*/

#include "VectorUtil.hpp"
#include <iostream>
using namespace std;


/*
 * Determines whether or not a vector contains a certain item.
 *
 * Parameters:
 *   input -- The vector to search
 *   lookFor -- The item to look for
 *
 * Returns:
 *   Whether or not the item is contained in the vector
 */
bool Contains( vector<int> input, int lookFor )
{
  // TODO: Fill in implementation. Do not always return false.
    for(int x: input){
        if(x==lookFor){
            return true;
        }
    }
  return false;
}

/*
 * Determines the minimum value in a vector.
 *
 * Assumes the vector is non-empty.
 *
 * Parameters:
 *   input -- A vector of integers
 *
 * Returns:
 *   The smallest item in the vector
 */
int FindMin( vector<int> input )
{
  // TODO: Fill in implementation. Do not always return 0.
//find a way of creating a var to store the inputs. and loop over the vector and each time compare that value with the value in the var created. If that value is greater than the previous one. updated the number
    int minNumber = input[0];
    for(int x: input){
        
        if (x<minNumber)
        {
            minNumber=x;
        }
    }
  return minNumber;
}

/*
 * Determines the maximum value in a vector.
 *
 * Assumes the vector is non-empty
 *
 * Parameters:
 *   input -- A vector of integers
 *
 * Returns:
 *   The largest item in the vector
 */
int FindMax( vector<int> input )
{
    int MaxNumber = input[0];
    for(int x: input){
        if (x > MaxNumber)
        {
            MaxNumber = x;
        }
    } return MaxNumber;
}

/*
 * Determines the average of all values in a vector
 *
 * Assumes the vector is non-empty
 *
 * Parameters:
 *   input -- A vector of integers
 *
 * Returns:
 *   The (integer) average of all values in the vector
 */
int Average( vector<int> input )
{
  // TODO: Fill in implementation. Do not always return 0.
    // average = sum of all in vector / vector.size()
    
    int sum=0;
    for( int x: input)
    {
        sum=x+sum;
    }
    int average = sum/ int (input.size());
//    std::cout << average<<endl;
  return average;
}


/*
 * Determines whether or not the items in a vector are in non-descending order
 *
 * Non-descending order is similar to ascending order, except that it allows for
 * duplicate items to appear next to each other.
 * i.e., no item appearing at a lower index than another item is greater than that
 * other item.
 *
 * Examples:
 *  {1, 2, 2, 15, 70} is sorted
 *  {2, 3, 0} is not sorted
 *
 * Parameters:
 *   input -- A vector of integers
 *
 * Returns:
 *   True if the vector is sorted in non-descending order, false otherwise
 *   An empty vector is considered sorted, since there are no items out of order
 *   A single-item vector is considered sorted, since there are no items out of order
 */
bool IsSorted( vector<int> input )
{
  // TODO: Fill in implementation. Do not always return false.
// int smallest = input[0]
    // for loop or for each through vector
    // if smallest > next index false
    // else true
    
    int Numb = input[0];
   for( int number : input)
   {
       if (number<Numb) {
           return false;
       }
       Numb = number;
   }
  return true;
}

// for( int i= 0; i<input.size()-1; i++){
//
