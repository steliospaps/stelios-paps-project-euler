#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
  ifstream in("base_exp.txt");
  string word;
  double base,exp;
  char coma;
  double max=0;
  int line=0,max_line=0;
  while(in>>base>>coma>>exp){
    //cout<<base<<" "<<exp<<endl;
    double logged=log(base)*exp;
    line++;
    if(max<logged){
      max_line=line;
      max=logged;
      cout<<"max "<<max<<" line "<<max_line<<endl;
    }
  }

  return 0;
}
