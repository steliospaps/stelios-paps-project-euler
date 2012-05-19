#include <iostream>
#include <deque>
#include <cstdlib>
using namespace std;

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
      //      cout<<"got "<<i<<" "<<max<<" "<<sum<<endl;
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
    cout<<"count_loop_size "<<start<<" "<<i<<endl;
    smallest=min(smallest,i);
  }
  if(longest<=count){
    smallest_ever=min(smallest_ever,smallest);
  }
}


void detect_loop(number_t point){
  chain_id++;
  do{
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
  }while(true);
} 
void follow_chain(number_t point){
  while(true){
    cout<<"follow_chain "<<point<<endl;
    if(point>max1){
      return;
    }
    data_t& data=chain_links[point];
    if(data.next==0){
      //new link
      point=data.next=sum_divisors(point);
    } else {
      //cout<<"found loop "<<point<<" "<<chain_links[point].first<<endl;
      //exit(0);
      detect_loop(point);
      return;
    }
  }
}
int main(){
  /*number_t data[]={12496 , 14288 , 15472 , 14536 , 14264};
  for(int i=0;i<5;i++){
    cout<<data[i]<<" "<<sum_divisors(data[i])<<endl;
    }*/
  //cout<<4<<" "<<sum_divisors(4)<<endl;
  //return 0;
  for(number_t i = 1;i<=max1;i++){
    cout<<i<<endl;
    follow_chain(i);
  }
  cout<<smallest_ever<<endl;
  return 0;
}
