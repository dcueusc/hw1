#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

using namespace std; //added
#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_front(const std::string& val)
{
   //cases: head=tail, first node full, first node not full - either fill up or fill and add new
      if(head_==NULL){ //head is null, create new node that is head/tail
        Item* toAdd = new Item;
        toAdd->next=tail_;
        toAdd->prev=head_;
        head_=toAdd;
        tail_=toAdd;
      
        toAdd->val[ARRSIZE-1]=val;
        size_++;
        toAdd->first=ARRSIZE-1;
        toAdd->last=ARRSIZE;
       
      }
      
      else if(head_->first > 0){ //add to start of curr head
         Item* curr = head_;
        curr->val[curr->first-1]=val;
        size_++;
        curr->first--;
        //cout << cufirst << " " << last << endl;
      }
      else{ //if first node full, create new first node, add to back
        Item* curr = head_;
        Item* toAdd = new Item;
        toAdd->next=curr;
        head_=toAdd;
        toAdd->prev=head_;
        toAdd->next->prev=toAdd;
        toAdd->val[ARRSIZE-1]=val;
        size_++;
        toAdd->first=ARRSIZE-1;
        toAdd->last=ARRSIZE;
      }


      
}


void ULListStr::push_back(const std::string& val){

      if (size_==0 || tail_->last == ARRSIZE) {

        if (size_==0){ //add new head/tail node
          Item* newItem = new Item();
          tail_= newItem;
          newItem->val[newItem->last++] = val;
          tail_ = newItem;
          head_ = newItem;
        }
        
        else{ //add new node at back
          Item* newItem = new Item();
          tail_->next= newItem;
          newItem->val[newItem->last++] = val;
          newItem->prev = tail_;
          tail_ = newItem;
        }
        
        size_++;
    } else { //add to the curr tail value
        tail_->val[tail_->last++] = val;
        size_++;
    }
}

void ULListStr::pop_front(){ //doesn't delete values just moves pointers for start/end/next
  if (size_==0){return;} //nothing to remove
  if(size_==1){delete head_; //one element - delete node and set head/tail to null
    head_=tail_=NULL; size_--; return;}
  Item* curr = head_;
    if(curr->last-curr->first>1){ //removing from node with other items - just move first pointer up
      curr->first++;
      size_--;
    }else{ Item* temp;  //else delete node and update pointers
    temp=head_;
      head_=head_->next;
      delete temp;
      if(head_!=nullptr){head_->prev=nullptr;}
      else{tail_=nullptr;}
      size_--;
    }
 
}

std::string const & ULListStr::front() const{ 
    return head_->val[head_->first];
}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];
}

void ULListStr::pop_back(){ 
  if(size_==0){return;} //nothing to remove
   if (tail_->first == tail_->last - 1) {
        // One element, remove node, update pointers
        Item* temp = tail_;
        tail_ = tail_->prev;
        delete temp;
        if (tail_!=nullptr) { //set next to null if last
            tail_->next = nullptr;
        } else { //if now empty, set head to null
            head_ = nullptr;
        }
         size_--;
    } else { //otherwise just move last pointer
        tail_->last--;
        size_--;
    }
}

std::string* ULListStr::getValAtLoc(size_t loc) const{

  if(loc>size_){return nullptr;}

  Item* curr = head_;
    while (true) { //keep going until done
      //cout <<  curr==nullptr) << endl;
      //cout << curr->first << " " << curr->last << endl;
        if (loc +curr->first >= curr->first && loc + curr->first < curr->last) { //if index is in this node
            return & (curr->val[loc + curr->first]); //return reference to value at index
        } //otherwise, keep going until you find the node
        loc -= curr->last - curr->first; //subtract # of nodes in curr from target
       curr = curr->next; //move to next node
    }
    return nullptr; 
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
