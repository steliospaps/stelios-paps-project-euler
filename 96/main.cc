#include <fstream>
#include <iostream>
#include <sstream>
#include "sudoku.h"
using namespace std;
int main(){
  ifstream in("sudoku.txt");
  string tmp;
  int sum=0;
  while(in>>tmp){
    //got grid
    in>>tmp; //number
    cout<<tmp<<endl;
    string board;
    for(int i=0;i<9;i++){
      in>>tmp;
      board+=tmp;
    }
    cout<<board<<endl;
    sudoku s(board);
    if(!s.solve()){
      cout<<"failed to solve"<<endl;
      return 1;
    }
    cout<<s.get_solution()<<endl;
    istringstream num(s.get_solution().substr(0,3));
    int tmp_num;
    num>>tmp_num;
    cout<<tmp_num<<endl;
    sum+=tmp_num;
  }
  cout<<sum<<endl;
  return 0;
}
