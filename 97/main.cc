#include <iostream>
using namespace std;
int main(){
  long number=1;
  long mod = 10000000000L;
  for(int i=0;i<7830457;i++){
    number*=2;
    number%=mod;
  }

  number*=28433;
  number %=mod;
  number++;
  number%=mod;
  cout<<number<<endl;
  return 0;
}
