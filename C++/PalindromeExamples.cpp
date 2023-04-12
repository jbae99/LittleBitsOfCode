#include<iostream>
#include<string> 
#include<stack>


std::string takeAndStrip();
bool palindromeCheckRecursive(std::string x);
bool palindromeCheckNonRecur(std::string x);


int main(){

  std::string userStr;
  userStr = takeAndStrip();

  if(palindromeCheckRecursive(userStr)){
    std::cout << '\n' << "This sentence is a Palindrome!";
  }
  else{
    std::cout << std::endl << "This Sentence is not a Palindrome!";
  }
  
  if(palindromeCheckNonRecur(userStr)){
    std::cout << '\n' << "This sentence is a Palindrome!";
  }
  else{
    std::cout << std::endl << "This Sentence is not a Palindrome!";
  }
  


  return 0;
}

std::string takeAndStrip(){
    std::string userStr, strippedStr;
    std::cout << "Please enter a string: ";
    getline(std::cin, userStr);

    for(int i =0; i < userStr.length();i++){
      if((int(userStr[i]) > 64) && (int(userStr[i] < 91)) ){
        strippedStr += char((int(userStr[i])) + 32);
      }
      else if((int(userStr[i]) > 96) && (int(userStr[i]) < 123)){
        strippedStr += userStr[i];
      }
    }
    return strippedStr;
}


bool palindromeCheckRecursive(std::string x){

  if(x.length() > 1){
    
    if(x[0] == x[(x.length() - 1)]){
      return palindromeCheckRecursive(x.substr(1, x.length() - 2));
    }
    else{
      return false;
    }
    
  }
    
  else{
    return true;
  }
  
}

bool palindromeCheckNonRecur(std::string x){
  std::stack<char> revStr;

  for(int i = 0;i < x.length();i++){
    revStr.push(x[i]);
  }
  
  for(int i = 0;i < x.length();i++){
    if(x[i] != revStr.top()){
      return false;
    }
    revStr.pop();
  }

  return true;
  
}