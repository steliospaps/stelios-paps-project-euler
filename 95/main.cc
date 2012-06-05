#include <iostream>
#include <deque>
#include <cstdlib>
using namespace std;

//#define log(x) cout<<x<<endl

#define log(x) /**/


typedef unsigned long number_t;

number_t get_bigger_than_root(number_t target){
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
      return mid+1;
    }
  }
  return high;
}
number_t sum_divisors(number_t target){
  number_t sum=1;
  number_t max=min(get_bigger_than_root(target),target);
  for(number_t i=2;i<max;i++){
    if(target%i==0){
      sum+=i;
      max=target/i;
      if(max!=i){
	sum+=max;
      }
      //      log("got "<<i<<" "<<max<<" "<<sum);
    }
  }
  return sum;
}


number_t max1=1000000;
struct data_t{
  number_t next;
  int id;
  data_t()
    :next(0),
     id(0){}
};
deque<data_t > chain_links(max1+1);
long chain_id=0;

number_t smallest_ever=max1;
size_t longest=0;
void count_loop_size(number_t start){
  size_t count=1;
  number_t smallest=start;
  for(number_t i = chain_links[start].next;i!=start;++count,i=chain_links[i].next){
    log("count_loop_size "<<start<<" "<<i);
    smallest=min(smallest,i);
  }
  log("counted size "<<count);
  if(longest<count){
    longest=count;
    smallest_ever=smallest;
    cout<<"smallest ever force "<<smallest_ever<<" "<<count<<endl;
  }
}


void detect_loop(number_t point){
  chain_id++;
  do{
    log("detect_loop "<<chain_id<<" "<<point);
    if(point > max1){
      return;
    }
    data_t& data=chain_links[point];
    if(data.id!=0){
      if(data.id==chain_id){
	//found loop
	count_loop_size(point);
	return;
      }else{
	//oops an other chain
	return;
      }
    }
    data.id=chain_id;
    point=data.next;
  }while(true);
} 
void follow_chain(const number_t start){
  number_t point=start;
  while(true){
    log("follow_chain "<<point);
    if(point>max1 || point<start){
      return;
    }
    data_t& data=chain_links[point];
    if(data.next==0){
      //new link
      point=data.next=sum_divisors(point);
    } else {
      //log("found loop "<<point<<" "<<chain_links[point].first);
      //exit(0);
      detect_loop(point);
      return;
    }
  }
}
int main(){
  /*number_t data[]={12496 , 14288 , 15472 , 14536 , 14264};
    for(int i=0;i<5;i++){
    log(data[i]<<" "<<sum_divisors(data[i]));
    }*/
  //log(4<<" "<<sum_divisors(4));
  //return 0;
  for(number_t i = 1;i<=max1;i++){
    log(i);
    follow_chain(i);
    if(i%1000==0){
      cout<<i<<endl;
    }
  }
  cout<<smallest_ever<<endl;
  return 0;
}
