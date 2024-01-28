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
#include <iostream>
using namespace std;

/* Add a prototype for a helper function here if you need */
void addNode(Node*& in, Node*& target);


void split(Node*& in, Node*& odds, Node*& evens)
{
  if (in == nullptr) {
    return;
  }
  else {
    Node* temp = in->next;
    if (in->value%2) {
      addNode(in,odds);
    }
    else {
      addNode(in,evens);
    }
    split(temp, odds, evens);
  }
  in = nullptr;
}

/* If you needed a helper function, write it here */
void addNode(Node*& in, Node*& target) {
  in->next = nullptr;
  if (target == nullptr) {
    target = in;
    return;
  }
  if (target->next == nullptr) {
    target->next = in;
    return;
  }
  addNode(in,target->next);
}