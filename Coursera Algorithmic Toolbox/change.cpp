#include <iostream>
using namespace std;

int get_change(int m) {
  int n = 0;
  int left = m;

  while(left >= 0 && left - 10 >= 0){
      left -= 10;
      n++;
  }
  while(left >= 0 && left - 5 >= 0) {
      left -= 5;
      n++;
  }
  while(left >= 0 && left - 1 >= 0) {
      left -= 1;
      n++;
  }

  return n;
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
