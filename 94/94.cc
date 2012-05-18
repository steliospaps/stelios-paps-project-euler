#include <iostream>
#include <sstream>

using namespace std;
unsigned long long solve(unsigned long long);
int main(int argc, char** argv){
  if(argc == 2){
    unsigned long long n=0;
    istringstream a(argv[1]);
    a>>n;
    if(n>0){
      cout<<solve(n)<<endl;
      return 0;
    }
  }
  cerr<<"usage 94 <n>\nwhere n is the maximum side length"<<endl;
  return 1;
}

unsigned long long sum_small(unsigned loong long n){
  for

unsigned long long solve(unsigned long long n){
  return sum_small(n);
}
