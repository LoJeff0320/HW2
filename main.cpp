#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void getValues(vector<string> &tokens, int &numOfOp, vector<char> &operations, vector<float> &numCount);

void getValues(vector<string> &tokens, int &numOfOp, vector<char> &operations, vector<float> &numCount){
  for(int i = 0; i < tokens.size(); i++){
    if(tokens.at(i).compare("*") == 0|| tokens.at(i).compare("/") == 0 || tokens.at(i).compare("+") == 0 || tokens.at(i).compare("-") == 0){
      numOfOp++;
      operations.push_back(tokens.at(i)[0]);
    }else{
      numCount.push_back(std::stof(tokens.at(i)));
    }
  }
}

int main() {
  string expression;
  int numOfOp = 0;
  float num1, num2, exTotal = 0;
  
  cout << "Enter an expression, in the form a + b * c: ";
  getline(cin, expression);

  //cout << expression << endl;
  vector<string> tokens;
  vector<char> operations; // 
  vector<float> numCount;

  stringstream check1(expression);
  string word;

  while(getline(check1, word, ' ')){
        tokens.push_back(word);
  }

  getValues(tokens, numOfOp, operations, numCount);

  for(int a = 0; a < operations.size(); a++){
    for(int b = 0; b < numCount.size(); b++){
      if(operations.at(a) == '*' || operations.at(a) == '/'){ // if the expression has multiplication or division
      if(operations.at(0) == '*'){
        exTotal = numCount.at(0) * numCount.at(1);
      }else{
        exTotal = numCount.at(0) / numCount.at(1);
      }
      if(operations.at(1) == '+'){
        exTotal += numCount.at(2);
      }else{
        exTotal -= numCount.at(2);
      } 
    }else{
      if(operations.at(0) == '+'){
        exTotal = numCount.at(0) + numCount.at(1);
      }else{
        exTotal = numCount.at(0) - numCount.at(1);
      } 
    }
    }

  }

  cout << expression << " = " << exTotal << endl;
  
  cout << "num of operations: " << numOfOp << endl;

  //print operations vector
  for(char x : operations){
    cout << x << endl;
  }
  //print numCount vector
  for(float y : numCount){
    cout << y << endl;
  }
}

void printVector(){
  /*
  for(auto& x : tokens){
    cout << x << endl;
  }*/
}

