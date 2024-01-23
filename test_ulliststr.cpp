#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std; 

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;
  list.push_back("0"); // on empty 
  list.push_back("1"); //
  list.push_back("2"); 
  list.push_back("3"); 
  list.push_back("4"); 
  list.push_back("5"); 
  list.push_back("6");
  list.push_back("7");
  list.push_back("8");
  list.push_back("9");
  list.push_back("10");  //should be at index 0 of second node/should create new node
  list.push_front("-1"); //adds new node to front, -1 will be at end of array
  list.push_front("-2"); 


  if(list.size()!=13){throw std::invalid_argument("Failed");}
  if(list.get(2)!="0"){throw std::invalid_argument("Failed");} //testing get
  list.pop_back(); //testing pop back on only item in node
  if(list.size()!=12){throw std::invalid_argument("Failed");}
  list.pop_front(); 
  if(list.size()!=11){throw std::invalid_argument("Failed");}
  list.pop_front();//pop front on only item in node
  if(list.back()!= "9" || list.front()!="0"){throw std::invalid_argument("Failed");} //testing back/front

  list.pop_back();
  list.pop_back();
  list.pop_back();
  list.pop_back();
  list.pop_back();
  list.pop_back();
  list.pop_back();
  list.pop_back();
  list.pop_back();
  list.pop_back();//removing last item w pop back

  if(!list.empty()){throw std::invalid_argument("Failed");}

  ULListStr list1;
  list1.push_front("0"); //pushing to front on empty
  if(list1.size()!=1){throw std::invalid_argument("Failed");}
  list1.pop_front(); //removing last item with pop front
  if(!list1.empty()){throw std::invalid_argument("Failed");}
  //passed all tests, correct functionality 
	
}
