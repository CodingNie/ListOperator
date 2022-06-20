
// ecListFuncs.h
// CSCI 455 Spring 2022, Extra Credit assignment
// You do not need to modify or submit this file.

#ifndef EC_LIST_FUNCS_H
#define EC_LIST_FUNCS_H

#include <string>



//*************************************************************************
// Node type used for lists
struct Node {
   int data;
   Node *next;

   Node(int item);
   Node(int item, Node *n);

};


typedef Node * ListType;



//*************************************************************************
// Functions you need to write for this assignment:
//   (implementations go in ecListFuncs.cpp)


/*
 * Note: examples of linked lists here are shown as a space separated list of numbers 
 * surrounded by parentheses.  This is also the format of the string produced by 
 * listToString, below.
 */



/**
   isAltSequence
  
   PRE: list is a well-formed list

   Returns true iff the list is an alternating sequence, where an alternating sequence is defined
   as one where the first two values are increasing (or decreasing), the second and third value
   go in the opposite direction (e.g., decreasing if the first two were increasing), continuing
   on with these alternating directions until the end of the list.  Such a list will have no 
   areas where two ajacent values are the same.  The examples below also show how the function
   should behave for short lists.


   Examples:
   
      list                isAltSequence(list)

      (7 4 5 2 12 -10)    true
      (7 4 3 5 2 12 -10)  false
      (7 4 5 12 15)       false
      (7 4 4 8 2 12 -10)  false
      (4 7 4 5 2)         true
      (1 3 2)             true
      (3 3 3)             false
      (1 2)               true
      (2 1)               true
      (2 2)               false
      (32)                true
      ()                  true
 */ 
bool isAltSequence(ListType list);



/**
   dupe0s
  
  PRE: list is a well-formed list
 
  duplicates any 0's in the list
   
  Examples (list' indicates the value of list after the call):

       list            list'
       ()             ()
       (12)           (12)
       (12 0)         (12 0 0)
       (7 4 7 7)      (7 4 7 7)
       (1 0 -30 0 0)  (1 0 0 -30 0 0 0 0)
       (0 0)          (0 0 0 0)
*/
void dupe0s(ListType & list);



/**
   collapseRepeats

   PRE: list is a well-formed list

   Removes any repeating adjacent values in the list, keeping the first copy of the value.

   Examples (list' indicates the value of list after the call):

      list                            list'

      (1 1 3 3 3 1 1 1 1 5 2 7 7)     (1 3 1 5 2 7)
      (1 3 1 5 2 7)                   (1 3 1 5 2 7)
      ()                              ()
      (12)                            (12)

*/
void collapseRepeats(ListType & list);


//*************************************************************************

#endif
