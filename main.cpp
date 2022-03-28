#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Calulator{

  enum Operator : unsigned char
  {
    multiplication = '*', division = '/', addition = '+', subtraction = '-'
  };

  string expression;
  int numOfOp = 0;
  float num1, num2, exTotal = 0;

  vector<string> tokens;
  vector<char> op;
  vector<Operator> op;
  vector<float> numCount;

  public:
  void getExpression(){
    cout << "Enter an expression, in the form a + b * c: ";
    getline(cin, expression);

    stringstream check1(expression);
    string word;

    while(getline(check1, word, ' ')){
      tokens.push_back(word);
    }
  }

  public:
  void getValues(){
    for(int i = 0; i < tokens.size(); i++){
      if(tokens.at(i).compare("*") == 0|| tokens.at(i).compare("/") == 0 || tokens.at(i).compare("+") == 0 || tokens.at(i).compare("-") == 0){
        numOfOp++;
        op.push_back(tokens.at(i)[0]);
      }else{
        numCount.push_back(stof(tokens.at(i)));
      }
    }
  }

  public:
  void precedence(){
    for(int a = 0; a < op.size(); a++){
      for(int b = 0; b < numCount.size(); b++){
        if(op.at(a) == '*' || op.at(a) == '/'){ // if the expression has multiplication or division
          if(op.at(0) == '*'){
            exTotal = numCount.at(0) * numCount.at(1);
          }else{
            exTotal = numCount.at(0) / numCount.at(1);
          }
          if(op.at(1) == '+'){
            exTotal += numCount.at(2);
          }else{
            exTotal -= numCount.at(2);
          } 
        }else{
          if(op.at(0) == '+'){
            exTotal = numCount.at(0) + numCount.at(1);
          }else{
            exTotal = numCount.at(0) - numCount.at(1);
          } 
        }
      }
    }
  }

  public:
  void printOperations(){
    //print operations vector
    for(char x : op){
      cout << x << endl;
    }
  }

  public:
  void printNumCount(){
    for(float y : numCount){
      cout << y << endl;
    }
  }
};

int main() {
  
  Calulator calculate;
  calculate.getExpression();
  calculate.printOperations();
  calculate.printOperations();
  calculate.getValues();

}

