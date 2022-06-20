/*  Name: Ning Nie
 *  USC NetID: 8845992604
 *  CS 455 Spring 2022
 *
 *  See ecListFuncs.h for specification of each function.
 *
 */

#include <string>
#include <cassert>

// for istringstream
#include <sstream>

#include "ecListFuncs.h"

using namespace std;

// *********************************************************
// Node constructors: do not change
Node::Node(int item) { 
   data = item;
   next = NULL;
}

Node::Node(int item, Node *n) {
   data = item;
   next = n;
}
// *********************************************************



bool isAltSequence(ListType list)  {
    // none or single value is true
    if (list == NULL || list -> next == NULL) return true;
    ListType pre = list;
    ListType cur = list -> next;
    ListType nxt = list -> next -> next;
    // two different value is true
    if (nxt == NULL){
        return pre -> data != cur -> data;
    }
    // Monotonicity is opposite between every value's left and right side
    while (nxt != NULL){
        int latter = (nxt -> data - cur -> data);
        int former = (cur -> data - pre -> data);
        // Monotonicity is the same, which means non-alt sequence
        if (latter * former >= 0){
            return false;
        }
        pre = cur;
        cur = nxt;
        nxt = nxt ->next;
    }
   return true;
}



void dupe0s(ListType & list) {
    ListType cur = list;
    if (cur == NULL) return;
    while (cur != NULL){
        ListType nxt = cur -> next;
        if (cur -> data == 0){
            cur -> next = new Node(0, nxt);
        }
        cur = nxt;
    }
}



void collapseRepeats(ListType & list) {
    ListType cur = list;
    // do nothing for none or single element
    if (cur == NULL || cur -> next == NULL) return;
    while (cur -> next != NULL){
        ListType nxt = cur -> next;
        if (nxt -> data == cur -> data){
            // loop through the rest of the duplicate value until null or a different value
            // release the memory for each duplicate element
            while (nxt != NULL && nxt -> data == cur -> data){
                ListType temp = nxt;
                nxt = nxt -> next;
                delete temp;
            }
            cur -> next = nxt;
            if (nxt == NULL){
                return;
            }else{
                cur = nxt;
            }
        }else{
            cur = nxt;
        }
    }
}
