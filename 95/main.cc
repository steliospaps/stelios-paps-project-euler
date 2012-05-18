#include <iostream>
#include <deque>
#include <cstdlib>
using namespace std;

typedef unsigned long number_t;

number_t get_root_or_bigger(number_t target){
  number_t low=2;
  number_t high=target;
  while(low<high){
    number_t mid=low + (high-low)/2;
    number_t sq=mid*mid;
    if(sq>target){
      high=mid;
    }else if (sq<target){
      if(low==mid){
	return high;
      }
      low=mid;
    }else{
      return mid;
    }
  }
  return high;
}


number_t sum_divisors(number_t target){
  number_t sum=1;
  number_t max=get_root_or_bigger(target);
  for(number_t i=2;i<max;i++){
    if(target%i==0){
      sum+=i;
      max=target/i;
      if(max!=i){
	sum+=max;
      }
      //      cout<<"got "<<i<<" "<<max<<" "<<sum<<endl;
    }
  }
  return sum;
}

number_t max1=1000000;
deque<pair<number_t,int> > chain_links(max1+1,pair<number_t,int>(0,0));
void follow_chain(number_t point){
  while(true){
    if(point>max1){
      return;
    }
    if(chain_links[point].first==0){
      //new link
      point=chain_links[point].first=sum_divisors(point);
    } else {
      cout<<"found loop "<<point<<" "<<chain_links[point].first<<endl;
      exit(0);
    }
  }
    
}
int main(){
  /*number_t data[]={12496 , 14288 , 15472 , 14536 , 14264};
  for(int i=0;i<5;i++){
    cout<<data[i]<<" "<<sum_divisors(data[i])<<endl;
    }*/
  for(number_t i = 2;i<=max1;i++){
    follow_chain(i);
  }
  return 0;
}
