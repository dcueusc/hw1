/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
using namespace std;
/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{ //in->5,6,7->nullptr.   in->value=5 
  int oddsc=0;
  if(in==nullptr){return;}
  if(in->next==nullptr){ 
    if(in->value%2==0){ //PROBLEM:Dont need to allocate any new nodes, just put existing nodes from in into evens/odds
    if(evens==NULL){evens=in;}
    else{evens->next = in;}
    }
  else{ 
    if(odds==NULL){odds=in;}
    else{odds->next = in;}
    }
    in=NULL;
    return;}
  Node* temp = in->next;
  if(in->value%2==0){ 
    if(evens==NULL){evens=in; in->next=nullptr;}
    else{evens->next = in; in->next=nullptr;}
    }
  else{
  oddsc=1;
    if(odds==NULL){odds=in; in->next=nullptr;}
    else{odds->next = in; in->next=nullptr;}
    }
    //change function call based on whether odds/evens was added 
    in=NULL;
    if(oddsc==1){
      // split(in->next,odds->next,evens);
      split(temp,odds->next,evens);
    }else{  
      // split(in->next,odds,evens->next);
      split(temp,odds,evens->next);
    }
    
  
}

/* If you needed a helper function, write it here */
