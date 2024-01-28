/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

using namespace std;

void test(int*, int);

void print_ll(Node* head) {
  Node* temp = head;
  while (temp != nullptr) {
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << endl;
}

void delete_ll(Node* head) {
  Node* temp = head;
  while (temp != nullptr) {
    head = head->next;
    delete temp;
    temp = head;
  }
  delete head;
}

Node* create_ll(int* list, int size) {
  if (size == 0) {
    return nullptr;
  }
  Node* head = new Node(list[size-1], nullptr);
  for (int i = size-2; i >= 0; --i) {
    Node* newNode = new Node(list[i], head);
    head = newNode;
  }
  return head;
}


int main(int argc, char* argv[])
{ 
  int data1[3] = {1,2,3};
  int size1 = 3;

  int data2[5] = {4,4,4,4,4};
  int size2 = 5;

  int data3[6] = {1,3,5,7,9,11};
  int size3 = 6;

  int data4[5] = {1,2,3,4,5};
  int size4 = 5;

  int data5[0] = {};
  int size5 = 0;

  cout << "Testing: " << endl;
  test(data1,size1);
  test(data2,size2);
  test(data3,size3);
  test(data4,size4);
  test(data5,size5);
}

void test(int* data, int size) {
  Node* odds = nullptr;
  Node* evens = nullptr;

  Node* input = create_ll(data,size);

  cout << "Running on input data: ";
  print_ll(input);

  split(input, odds, evens);

  cout << "With odd result: ";
  print_ll(odds);
  cout << "And even result: ";
  print_ll(evens);
  cout << endl;

  delete_ll(odds);
  delete_ll(evens);
}
