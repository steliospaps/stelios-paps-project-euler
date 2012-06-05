#ifndef SUDOKU_HH 
#define SUDOKU_HH SUDOKU_HH
#include <string>
#include <vector>
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
  void exclude_col(size_t pos, std::string& str){
    for(size_t i = pos%9;i<board.size();i+=9){
      str.erase(str.find(board[i]));
    }
  }
  void exclude_row(size_t pos, std::string& str){
    for(size_t i = 0;i<9;i++){
      str.erase(str.find(board[i+pos/9]));
    }
  }
  void exclude_box(size_t pos, std::string& str){
    //TODO
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
	if(e.valid_values.empty()){
	  return false;
	}
	empties.push_back(e);
      }
    }
    if(empties.empty()){
      return true;
    }
    return false;
  }
  const std::string get_solution(){
    return board;
  }
};
#endif 
