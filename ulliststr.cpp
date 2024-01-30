#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

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
void ULListStr::push_back(const std::string& val) {
  if (empty()) {
    Item* newItem = new Item;
    newItem->val[0] = val;
    newItem->last = 1;
    head_ = newItem;
    tail_ = newItem;
    
  }
  else if (ARRSIZE - tail_->last) {
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  else {
    Item* newItem = new Item;
    newItem->val[0] = val;
    newItem->last = 1;
    tail_->next = newItem;
    newItem->prev = tail_;
    tail_ = newItem;
  }
  size_++;
}
void ULListStr::push_front(const std::string& val) {
  if (empty()) {
    Item* newItem = new Item;
    newItem->val[0] = val;
    newItem->last = 1;
    head_ = newItem;
    tail_ = newItem;
  }
  else if (head_->first) {
    head_->val[head_->first-1] = val;
    head_->first--;
  }
  else {
    Item* newItem = new Item;
    newItem->val[ARRSIZE-1] = val;
    newItem->first = ARRSIZE-1;
    newItem->last = 10;
    head_->prev = newItem;
    newItem->next = head_;
    head_ = newItem;
    head_->prev = nullptr;
  }
  size_++;
}
void ULListStr::pop_back() {
  if (empty()) {
    return;
  }
  else if (size_ == 1) {
    clear();
    return;
  }
  else if (tail_->last > 1) {
    tail_->val[tail_->last-1] = "";
    tail_->last--;
  }
  else {
    Item* temp = tail_;
    tail_ = tail_->prev;
    delete temp;
    tail_->next = nullptr;
  }
  size_--;
}
void ULListStr::pop_front() {
  if (empty()) {
    return;
  }
  else if (size_ == 1) {
    clear();
    return;
  }
  else if (head_->first < 9) {
    head_->val[head_->first] = "";
    head_->first++;
  }
  else {
    Item* temp = head_;
    head_ = head_->next;
    delete temp;
  }
  size_--;
}
std::string const & ULListStr::back() const {
  return tail_->val[tail_->last-1];
}
std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}
std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc > size_-1 || loc < 0) {
    return NULL;
  }
  Item* temp = head_;
  int numNext;
  int backfill;
  int calcHelp = loc-ARRSIZE+head_->first;
  if (calcHelp >= 0) {
    numNext = calcHelp/ARRSIZE+1;
    backfill = calcHelp % ARRSIZE;
  } 
  else {
    numNext = 0;
    backfill = head_->first + loc;
  }
  for (int i = 0; i < numNext; ++i) {
    temp = temp->next;
  }
  std::string* ret = &temp->val[backfill];
  return ret;
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


