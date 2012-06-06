#ifndef SUDOKU_HH 
#define SUDOKU_HH SUDOKU_HH
#include <string>
#include <vector>
#include <iostream>
class sudoku{
  struct empty{
    size_t location;
    std::string valid_values;
  };
  std::string board;
 public:
  sudoku(const std::string& original)
    :board(original){
  }
  void exclude(char c,std::string& str){
    size_t found=str.find(c);
    if(found!=std::string::npos){
      //std::cout<<"removing "<<c<<" from "<<str<<std::endl;
      str.erase(found,1);
    }
  }
  void exclude_col(size_t pos, std::string& str){
    for(size_t i = pos%9;i<board.size();i+=9){
      exclude(board[i],str);
    }
  }
  void exclude_row(size_t pos, std::string& str){
    for(size_t i = 0;i<9;i++){
      exclude(board[i+pos/9],str);
    }
  }
  void exclude_box(size_t pos, std::string& str){
    size_t box_start=(pos - pos%27)+(pos%9-pos%3);
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	exclude(board[box_start+i*27+j],str);
      }
    }
  }
  void exclude_invalids(size_t pos, std::string& str){
    exclude_col(pos,str);
    exclude_row(pos,str);
    exclude_box(pos,str);
  }
  bool solve(){
    std::vector<empty> empties;
    for(size_t i = 0; i<board.size() ;i++){
      if(board[i]=='0'){
	empty e;
	e.location=i;
	e.valid_values="123456789";
	exclude_invalids(i,e.valid_values);
	//std::cout<<"pos "<<i<<" "<<e.valid_values<<std::endl;
	if(e.valid_values.empty()){
	  return false;
	}
	empties.push_back(e);
      }
    }
    if(empties.empty()){
      return true;
    }
    //find smallest empty
    empty smallest=empties[0];
    for(size_t i=1;i<empties.size();i++){
      if(empties[i].valid_values.size() < smallest.valid_values.size()){
	smallest=empties[i];
      }
    }
    for(size_t i =0 ;i < smallest.valid_values.size() ;i++){
      board[smallest.location]=smallest.valid_values[i];
      if(solve()){
	return true;
      }
    }
    board[smallest.location]='0';
    return false;
  }
  const std::string get_solution(){
    return board;
  }
};
#endif 
