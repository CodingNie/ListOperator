/*  Name: Ning Nie
 *  USC NetID: 8845992604
 *  CS 455 Sping 2022
 *  Extra credit assignment
 *
 *  ectest.cpp
 *
 *  a non-interactive test program to thoroughly test the functions described in ecListFuncs.h
 *
 *    to run it use the command:   ectest
 *
 *  Note: this uses separate compilation.  You put your list code ecListFuncs.cpp
 *  Code in this file should call those functions.
 */


#include <iostream>
#include <string>

// for istringstream used in buildList (defined below)
#include <sstream>

#include "ecListFuncs.h"
//#include "ecListFuncs.cpp"

using namespace std;



// You may use the following two utility functions that will make it easier to test your list
// functions on hard-coded list data (specs and definitions appear at the bottom of the file):
string listToString(ListType list);
ListType buildList(const string & listString);

// the following three functions contain test cases for each function in ecListFuncs.cpp
void testAlt();
void testDup();
void testColla();

// print the current list, for user to see the status of the list
void printInfo(ListType list);

/** for test case "testDup" and "testColla"
 *  the parameter is the actual output returned by the program and the expected result type in by me
 *  print message "correct" for same results, and "failed" for different
 */
void doOneStringCompare(const string &output, const string &expected);

/** for test case "testAlt"
 *  the parameter is the actual output returned by the program and the expected result type in by me
 *  print message "correct" for same results, and "failed" for different
 */
void doOneBooleanCompare(const bool &output, const bool &expected);


int main ()
{
    cout << "The following is the test for isAltSequence function: " << endl;
    testAlt();
    cout << "======================================================" << endl;
    cout << "The following is the test for dupe0s function: " << endl;
    testDup();
    cout << "======================================================" << endl;
    cout << "The following is the test for collapseRepeats function: " << endl;
    testColla();
    return 0;
}

/**
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
(0 0 0)             false
(-1 -2 -3)          false
(-2 -1 -4)          true
(-10 -20 -9)        true
(-10 100 -99)       true
(-99 -99 -99)       false
(-99 -100 -99)      true
(-1)                true
*/
void testAlt(){
    ListType l1 = buildList("7 4 5 2 12 -10");
    ListType l2 = buildList("7 4 3 5 2 12 -10");
    ListType l3 = buildList("7 4 5 12 15");
    ListType l4 = buildList("7 4 4 8 2 12 -10");
    ListType l5 = buildList("4 7 4 5 2");
    ListType l6 = buildList("1 3 2");
    ListType l7 = buildList("3 3 3");
    ListType l8 = buildList("1 2");
    ListType l9 = buildList("2 1 ");
    ListType l10 = buildList("2 2");
    ListType l11 = buildList("32");
    ListType l12 = buildList("");
    ListType l13 = buildList("0 0 0");
    ListType l14 = buildList("-1 -2 -3");
    ListType l15 = buildList("-2 -1 -4");
    ListType l16 = buildList("-10 -20 -9");
    ListType l17 = buildList("-10 100 -99");
    ListType l18 = buildList("-99 -99 -99");
    ListType l19 = buildList("-99 -100 -99");
    ListType l20 = buildList("-1");

    cout << "Input: ";
    printInfo(l1);
    doOneBooleanCompare(isAltSequence(l1), true);
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l2);
    doOneBooleanCompare(isAltSequence(l2), false);
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l3);
    doOneBooleanCompare(isAltSequence(l3), false);
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l4);
    doOneBooleanCompare(isAltSequence(l4), false);
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l5);
    doOneBooleanCompare(isAltSequence(l5), true);
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l6);
    doOneBooleanCompare(isAltSequence(l6), true);
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l7);
    doOneBooleanCompare(isAltSequence(l7), false);
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l8);
    doOneBooleanCompare(isAltSequence(l8), true);
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l9);
    doOneBooleanCompare(isAltSequence(l9), true);
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l10);
    doOneBooleanCompare(isAltSequence(l10), false);
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l11);
    doOneBooleanCompare(isAltSequence(l11), true);
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l12);
    doOneBooleanCompare(isAltSequence(l12), true);
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l13);
    doOneBooleanCompare(isAltSequence(l13), false);
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l14);
    doOneBooleanCompare(isAltSequence(l14), false);
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l15);
    doOneBooleanCompare(isAltSequence(l15), true);
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l16);
    doOneBooleanCompare(isAltSequence(l16), true);
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l17);
    doOneBooleanCompare(isAltSequence(l17), true);
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l18);
    doOneBooleanCompare(isAltSequence(l18), false);
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l19);
    doOneBooleanCompare(isAltSequence(l19), true);
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l20);
    doOneBooleanCompare(isAltSequence(l20), true);
}

/**

list            list'
()             ()
(12)           (12)
(12 0)         (12 0 0)
(7 4 7 7)      (7 4 7 7)
(1 0 -30 0 0)  (1 0 0 -30 0 0 0 0)
(0 0)          (0 0 0 0)
(1 1 1)        (1 1 1)
(1 2 3 4 5)    (1 2 3 4 5)
(10 20 30 40)  (10 20 30 40)
(10 0 20 0 30) (10 0 0 20 0 0 30)
(-1 -1 -1)     (-1 -1 -1)
(-1 0 -1)      (-1 0 0 -1)
(0 -10 0)      (0 0 -10 0 0)
(10 0 10 0)    (10 0 0 10 0 0)
(0 20 0 20)    (0 0 20 0 0 20)
(-9 0 -9)      (-9 0 0 -9)
*/
void testDup(){
    ListType l1 = buildList("");
    ListType l2 = buildList("12");
    ListType l3 = buildList("12 0");
    ListType l4 = buildList("7 4 7 7");
    ListType l5 = buildList("1 0 -30 0 0");
    ListType l6 = buildList("0 0");
    ListType l7 = buildList("1 1 1");
    ListType l8 = buildList("1 2 3 4 5");
    ListType l9 = buildList("10 20 30 40");
    ListType l10 = buildList("10 0 20 0 30");
    ListType l11 = buildList("-1 -1 -1");
    ListType l12 = buildList("-1 0 -1");
    ListType l13 = buildList("0 -10 0");
    ListType l14 = buildList("10 0 10 0");
    ListType l15 = buildList("0 20 0 20");
    ListType l16 = buildList("-9 0 -9");

    cout << "Input: ";
    printInfo(l1);
    dupe0s(l1);
    doOneStringCompare(listToString(l1), "()");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l2);
    dupe0s(l2);
    doOneStringCompare(listToString(l2), "(12)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l3);
    dupe0s(l3);
    doOneStringCompare(listToString(l3), "(12 0 0)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l4);
    dupe0s(l4);
    doOneStringCompare(listToString(l4), "(7 4 7 7)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l5);
    dupe0s(l5);
    doOneStringCompare(listToString(l5), "(1 0 0 -30 0 0 0 0)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l6);
    dupe0s(l6);
    doOneStringCompare(listToString(l6), "(0 0 0 0)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l7);
    dupe0s(l7);
    doOneStringCompare(listToString(l7), "(1 1 1)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l8);
    dupe0s(l8);
    doOneStringCompare(listToString(l8), "(1 2 3 4 5)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l9);
    dupe0s(l9);
    doOneStringCompare(listToString(l9), "(10 20 30 40)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l10);
    dupe0s(l10);
    doOneStringCompare(listToString(l10), "(10 0 0 20 0 0 30)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l11);
    dupe0s(l11);
    doOneStringCompare(listToString(l11), "(-1 -1 -1)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l12);
    dupe0s(l12);
    doOneStringCompare(listToString(l12), "(-1 0 0 -1)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l13);
    dupe0s(l13);
    doOneStringCompare(listToString(l13), "(0 0 -10 0 0)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l14);
    dupe0s(l14);
    doOneStringCompare(listToString(l14), "(10 0 0 10 0 0)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l15);
    dupe0s(l15);
    doOneStringCompare(listToString(l15), "(0 0 20 0 0 20)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l16);
    dupe0s(l16);
    doOneStringCompare(listToString(l16), "(-9 0 0 -9)");
}

/**
list                            list'

(1 1 3 3 3 1 1 1 1 5 2 7 7)     (1 3 1 5 2 7)
(1 3 1 5 2 7)                   (1 3 1 5 2 7)
()                              ()
(12)                            (12)
(0 0 0 0 0)                     (0)
(1 1 1 1 1)                     (1)
(1 2 2 3 3 3)                   (1 2 3)
(1 1 1 2 1 1 1)                 (1 2 1)
(1 2 2 2 2 2 1)                 (1 2 1)
(10 10 10 20 20 20)             (10 20)
(-1 -1 -1 -1)                   (-1)
(-1 -2 -2 -3 -3 -3)             (-1 -2 -3)
(-10 10 -10 10)                 (-10 10 -10 10)
(-9 0 0 0 9 9 9)                (-9 0 9)
(-1 -2 -3 -3 -2 -1)             (-1 -2 -3 -2 -1)
(-1 -1 0 0 -1 -1)               (-1 0 -1)

*/
void testColla(){
    ListType l1 = buildList("1 1 3 3 3 1 1 1 1 5 2 7 7");
    ListType l2 = buildList("1 3 1 5 2 7");
    ListType l3 = buildList("");
    ListType l4 = buildList("12");
    ListType l5 = buildList("0 0 0 0 0");
    ListType l6 = buildList("1 1 1 1 1");
    ListType l7 = buildList("1 2 2 3 3 3");
    ListType l8 = buildList("1 1 1 2 1 1 1");
    ListType l9 = buildList("1 2 2 2 2 2 1");
    ListType l10 = buildList("10 10 10 20 20 20");
    ListType l11 = buildList("-1 -1 -1 -1");
    ListType l12 = buildList("-1 -2 -2 -3 -3 -3");
    ListType l13 = buildList("-10 10 -10 10");
    ListType l14 = buildList("-9 0 0 0 9 9 9");
    ListType l15 = buildList("-1 -2 -3 -3 -2 -1");
    ListType l16 = buildList("-1 -1 0 0 -1 -1");

    cout << "Input: ";
    printInfo(l1);
    collapseRepeats(l1);
    doOneStringCompare(listToString(l1), "(1 3 1 5 2 7)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l2);
    collapseRepeats(l2);
    doOneStringCompare(listToString(l2), "(1 3 1 5 2 7)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l3);
    collapseRepeats(l3);
    doOneStringCompare(listToString(l3), "()");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l4);
    collapseRepeats(l4);
    doOneStringCompare(listToString(l4), "(12)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l5);
    collapseRepeats(l5);
    doOneStringCompare(listToString(l5), "(0)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l6);
    collapseRepeats(l6);
    doOneStringCompare(listToString(l6), "(1)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l7);
    collapseRepeats(l7);
    doOneStringCompare(listToString(l7), "(1 2 3)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l8);
    collapseRepeats(l8);
    doOneStringCompare(listToString(l8), "(1 2 1)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l9);
    collapseRepeats(l9);
    doOneStringCompare(listToString(l9), "(1 2 1)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l10);
    collapseRepeats(l10);
    doOneStringCompare(listToString(l10), "(10 20)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l11);
    collapseRepeats(l11);
    doOneStringCompare(listToString(l11), "(-1)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l12);
    collapseRepeats(l12);
    doOneStringCompare(listToString(l12), "(-1 -2 -3)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l13);
    collapseRepeats(l13);
    doOneStringCompare(listToString(l13), "(-10 10 -10 10)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l14);
    collapseRepeats(l14);
    doOneStringCompare(listToString(l14), "(-9 0 9)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l15);
    collapseRepeats(l15);
    doOneStringCompare(listToString(l15), "(-1 -2 -3 -2 -1)");
    cout << "------------------------" << endl;
    cout << "Input: ";
    printInfo(l16);
    collapseRepeats(l16);
    doOneStringCompare(listToString(l16), "(-1 0 -1)");
    cout << "------------------------" << endl;
}

void printInfo(ListType list){
    string s = listToString(list);
    cout << s << endl;
}

void doOneStringCompare(const string &output, const string &expected){
    cout << "Output: " << output << endl;
    cout << "Expected: " << expected << endl;
    if (output == expected){
        cout << "CORRECT" << endl;
    }else{
        cout << "FAILED" << endl;
    }
}

void doOneBooleanCompare(const bool &output, const bool &expected){
    cout << "Output: " << output << endl;
    cout << "Expected: " << expected << endl;
    if (output == expected){
        cout << "CORRECT" << endl;
    }else{
        cout << "FAILED" << endl;
    }
}


/*
 * listToString
 *
 * PRE: list is a well-formed list.
 *
 * converts the list to a string form that has the following format shown by example.
 * the list is unchanged by the function.
 *
 *   string format:
 *
 *   "()"        an empty list
 *   "(3)        a list with one element, 3
 *   "(3 4 5)"   a list with multiple elements: 3 followed by 4 followed by 5
 *
 */
string listToString(ListType list) {

   string listString = "(";

   if (list == NULL) {
      listString += ")";
      return listString;
   }

   Node *p = list;
   while (p->next != NULL) {
      listString += to_string(p->data) + " ";
      p = p->next;
   }

   // print last one with no trailing space
   listString += to_string(p->data) + ")";

   return listString;

}   


/*
 * buildList
 * 
 * PRE: listString only contains numbers (valid integer format) and spaces
 *
 * creates and returns a linked list from a string of space separated numbers
 * 
 *
 * Examples:
 *  listString         return value of buildList(listString)
 *
 *    ""               ()
 *    "-32"            (-32)
 *    "     -32   "    (-32)
 *    "1 3 2"          (1 3 2)
 *    "  1 3 2"        (1 3 2)
 *
 */
ListType buildList(const string & listString) {

   ListType nums = NULL;

   istringstream istr(listString);  // similar to a Java Scanner over a String

   int num;

   if (istr >> num) { // is there one value there?
      nums = new Node(num);
   }
   else {
      return NULL;
   }

   Node *last = nums;

   while (istr >> num) { 
      last->next = new Node(num);
      last = last->next;
   }

   return nums;
}
