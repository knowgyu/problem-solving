#include <iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  long long m = 0;
  while(n--){
    int a, d, g;
    cin >> a >> d >> g;
    int s = d + g;
    long long sc = a * 1LL * s;
    if(a == s) sc *= 2;
    if(sc > m) m = sc;
  }
  cout << m;
  return 0;
}