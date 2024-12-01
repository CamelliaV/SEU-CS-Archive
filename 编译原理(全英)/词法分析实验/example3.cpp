#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;
template <typename T>
void println(const initializer_list<T> &&value) {
  for (int i : value) {
    cout << i << " ";
  }
  cout << endl;
}
template <typename T>
void println(const T &value) {
  cout << value << endl;
}

/* alias */
template <typename T>
using Vec = vector<T>;

int main() {
  // /* initialize list */
  // int i, j();
  // int *p();
  // int *q;
  // // cout << i << " " << j << endl;
  // // cout << *q << " " << *p << " " << endl;

  // vector<int> a;
  // a.insert(a.begin(), {1, 2, 3, 4, 5});
  // for (int i : a) {
  //   cout << i << " ";
  // }
  // cout << endl;
  
  // /* nullptr_t */
  // nullptr_t nl;
  // cout << boolalpha;
  // cout << (nullptr == nl ? true : false) << endl;
    
  // /* alias */
  // Vec<int> arr {1, 2, 3};
  // for (int i : arr) {
  //   cout << i << " ";
  // }
  // cout << endl;
  
  /* lambda */
  [] () {
    cout << "Called Immediately" << endl;
  } ();
  
  auto I = [] {
    cout << "lambda" << endl;
  };
  
  I();
  
  int id = 0;
  
  auto f1 = [id] () mutable {
    cout << "original id: " << id++ << endl;
  };
  
  f1();
  f1();
  f1();
  
  cout << id << endl;
  
  auto f2 = [&id] () {
    cout << "original id: " << id++ << endl;
  };
  
  f2();
  f2();
  f2();
  
  cout << id << endl;

  f2();
  id = 100;
  f2();
  
  cout << id << endl;
}