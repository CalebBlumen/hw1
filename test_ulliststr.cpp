#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite
void test();

int main(int argc, char* argv[])
{
 
  test();
  return 0;
}

void test() {
  ULListStr testList;

  testList.push_back("a");
  testList.get(0);
  testList.pop_front();
  cout << testList.size() << endl;
  
 /* cout << "populating: " << endl;
  for (unsigned int i = 0; i < 11; ++i) {
    testList.push_back(to_string(i));
  }
  for (unsigned int i = 0; i < 12; ++i) {
    testList.push_front(to_string(i));
  }
  
  cout << endl;
  cout << "actual size: " << testList.size() << " list size: " << testList.size() << endl;
  
  cout << "full list: " << endl;
  testList.printList();

  cout << "back: " << testList.back() << "; front: " << testList.front() << endl;

  cout << "Popping front and back: " << endl;
  testList.pop_back();
  testList.pop_front();

  testList.printList();

  cout << "Getting index 0: ";
  cout << testList.get(0) << endl;

  cout << "back: " << testList.back() << "; front: " << testList.front() << endl;
*/

}
