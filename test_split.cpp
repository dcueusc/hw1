/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
using namespace std;
#include <cstddef>



int main(int argc, char* argv[])
{ 
  Node in3(7,nullptr);
  Node in2(6,&in3);
  Node in1(5,&in2); 
  Node* in=&in1;
  Node* in4 = NULL;
  Node* odds =NULL;
  Node* evens=NULL;
  split(in4,odds,evens);
  //split(in,odds,evens);
 
  

}
