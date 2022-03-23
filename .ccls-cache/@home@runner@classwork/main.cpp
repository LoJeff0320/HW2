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
  float num1, num2, exTotal;
  
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
    
  }
  
  if(operations.at(0) == '*'){
    exTotal = numCount.at(0) * numCount.at(1);
    if(operations.at(0) == '/'){
      exTotal = numCount.at(0) / numCount.at(1);
    }
  }

  cout << "num of operations: " << numOfOp << endl;

  for(char x : operations){
    cout << x << endl;
  }

  for(float y : numCount){
    cout << y << endl;
  }
  /*
  if(tokens.at(1).compare("*")){
    num1 = stof(tokens.at(0));
    num2 = stof(tokens.at(2));
    sum = num1 * num2;
  }*/
  
}

void printVector(){
  /*
  for(auto& x : tokens){
    cout << x << endl;
  }*/
}

