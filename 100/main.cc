#include <iostream>
#include <map>
using namespace std;

typedef unsigned long long int_t;
typedef map<int_t,size_t> map_t;
int_t smaller_number_larger_than_root(int_t target,int_t min,int_t max){
  int_t mid=(max-min)/2+min;
  if(mid==min){
    return max;
  }
  int_t square = mid*mid;
  if(square<mid || square > target){
    return smaller_number_larger_than_root(target,min,mid);
  } else if(square<target){
    //mid too small
    return smaller_number_larger_than_root(target,mid,max);
  } else {
    return mid;
  }
}
int_t smaller_number_larger_than_root(int_t num){
  return smaller_number_larger_than_root(num,1,num);
}

const map_t factorize(int_t num){
  map_t result;
  while(num%2 == 0){
    result[2]++;
    num/=2;
  }
  for(size_t i=3;i<=num;i++){
    while(num%i == 0){
      result[i]++;
      num/=i;
    }
  }
  if(num!=1){
    result[num]++;
  }
  return result;
} 
ostream& operator<<(ostream& out, const map_t& m){
  for(map_t::const_iterator i=m.begin();
      i!=m.end();
      ++i){
    out<<i->first<<":"<<i->second<<" ";
  }
  return out;
}
int main(){
  for(int_t i=1000000000000;i<1000000000010;i++){
    map_t m=factorize(i);
    cout<<i<<","<<smaller_number_larger_than_root(i)<< " " << m<<endl;
  }
  return 0;
}
