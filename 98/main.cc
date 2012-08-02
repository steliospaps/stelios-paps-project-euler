#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
typedef map<string,set<string> > map_t; 

bool is_square(const int num){
  int max=num;
  int min=1;

  while(true){
    int mid = min + (max-min)/2;
    int mid2=mid*mid;
    if(min>max){
      return false;
    }else if(mid2==num){
      return true;
    }else if(mid2>num){
      max=mid-1;
    }else if(mid2<num){
      min=mid+1;
    }else{
      cerr<<"WTF? "<<num<<" "<<mid<<endl;
    }
  }

}

typedef pair<vector<int>,vector<int> > pair_t;
const pair_t make_pair_vec(const string&a, const string& b){
  vector<int> map_a,map_b;
} 

int numerise(std::map<char,int>&map,const std::string&str){
  int result=0;
  for(size_t i=0;i<str.size();i++){
    result*=10;
    result+=map[str[i]];
  }
  return result;
}
int biggest=0;
void check_squareness_recurse(size_t index,std::set<int>&used_numbers,std::map<char,int>&map,const std::string&a,const std::string& b){
  if(index==a.size()){
    int a_num=numerise(map,a);
    int b_num=numerise(map,b);
    if(is_square(a_num) && is_square(b_num)){
      biggest=max(biggest,a_num);
      biggest=max(biggest,b_num);
      cout<<" "<<a_num<<" "<<b_num<<endl;
      cout<<"biggest "<<biggest<<endl;
    }
    
    //end of the line
  }else if(map.find(a[index])!=map.end()){
    //duplicate letter
    check_squareness_recurse(index+1,used_numbers,map,a,b);
  }else{
    for(int i=0;i<=9;i++){
      if(used_numbers.find(i)!=used_numbers.end()){
	continue;
      }
      if(i==0&&a[index]==b[0]){
	//b would start with 0;
	continue;
      }
      used_numbers.insert(i);
      map[a[index]]=i;

      check_squareness_recurse(index+1,used_numbers,map,a,b);

      map.erase(a[index]);
      used_numbers.erase(i);
    }
  }
}
void check_squareness(const string&a, const string& b){
  cout<<"check_squareness "<<a<<" "<<b<<endl;
  for(int i=1;i<=9;i++){
    std::set<int> used_numbers;
    std::map<char,int> map;
    map[a[0]]=i;
    used_numbers.insert(i);
    check_squareness_recurse(1,used_numbers,map,a,b);
  }
}

int main(){
  ifstream in("words_split.txt");
  string word;
  map_t words;
  while(in>>word){
    string key=word;
    sort(key.begin(),key.end());
    words[key].insert(word);
    //cout<<"["<<word<<"]"<<endl;
  }
  for(map_t::iterator i = words.begin();
      i!= words.end();
      ++i){
    if(i->second.size()>1){
      cout<<i->first<<" :";
      for(map_t::value_type::second_type::iterator j=i->second.begin();
	  j!=i->second.end();
	  ++j){
	cout<<" "<<*j;
      }
      cout<<endl;
      for(map_t::value_type::second_type::iterator j=i->second.begin();
	  j!=i->second.end();
	  ++j){
	for(map_t::value_type::second_type::iterator k=j;
	    k!=i->second.end();
	    ++k){
	  if(k!=j){
	    check_squareness(*j,*k);
	  }
	}
      }
    }
  }
  cout<<biggest<<endl;
  return 0;
}
