// TemplateArray.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "CArray.h"


// Check Work to Int
void print(
    CArray <int>& _intArray
)
{
  for (int i = 0; i < _intArray.size(); ++i)
  {
    std::cout << _intArray[i] << " ";
  }
  std::cout << std::endl;  
}

void pushBackInt(
    CArray <int>& _intArray
)
{
  for (size_t i = 0; i < 20; ++i)  
  {  
    _intArray.push_back(rand() % 101);  
  }  

  print(_intArray);  
}

void sortInt(
    CArray <int>& _intArray
)
{
  int tempInt;  
  for (int i = 0; i < _intArray.size() - 1; ++i)  
    for (int j = i; j >= 0; --j)    
    {    
      if (_intArray[j] > _intArray[j + 1])      
      {      
        tempInt = _intArray[j];        
        _intArray[j] = _intArray[j + 1];        
        _intArray[j + 1] = tempInt;        
      }      
    }    

  print(_intArray);  
}

void eraseEverySecondInt(
    CArray <int>& _intArray
)
{
  for (int i = _intArray.size(); i > 0; --i)
  {  
    if (i % 2 == 0)    
      _intArray.erase(i);
  }  
  print(_intArray);
}

void insertInt(
    CArray <int>& _intArray
)
{
  for (int i = 0; i < 10; ++i)  
  {  
    _intArray.insert(rand() % (_intArray.size() - 1), rand() % 101);
  }  
  print(_intArray);
}

void clearInt(
    CArray <int>& _intArray
)
{
  _intArray.clear();
  print(_intArray);
}
// Check Work to String
void print(
    CArray <std::string>& _stringArray
)
{
  for (int i = 0; i < _stringArray.size(); ++i)  
  {  
    std::cout << _stringArray[i] << " ";    
  }  
  std::cout << std::endl;  
}

void pushBackString(
    CArray <std::string>& _stringArray
)
{
  for (int i = 0; i < 15; ++i)  
  {  
    int len = rand() % 3 + 3;    
    std::string word = "";    
    for (int j = 0; j < len; ++j)    
        word += rand() % 26 + 97;    
    _stringArray.push_back(word);    
  }  

  print(_stringArray);  
}

void sortString(
    CArray <std::string>& _stringArray
)
{
  std::string tempString;  
  for (int i = 0; i < _stringArray.size() - 1; ++i)  
    for (int j = i; j >= 0; --j)    
    {    
      if (_stringArray[j].size() > _stringArray[j + 1].size())      
      {      
        tempString = _stringArray[j];        
        _stringArray[j] = _stringArray[j + 1];        
        _stringArray[j + 1] = tempString;        
      }      
    } 

  print(_stringArray);  
}

void eraseWithPattern(
    CArray <std::string>& _stringArray,
    const std::string& pattern
)
{
  for (int i = _stringArray.size() - 1; i > 0; --i)  
  {  
    if (_stringArray[i].find_first_of(pattern) != std::string::npos)    
    {    
      _stringArray.erase(i);    
    }    
  }

  print(_stringArray);
}

void insertString(
    CArray <std::string>& _stringArray
)
{
    for (int i = 0; i < 3; ++i)
    {
        int len = rand() % 3 + 3;
        std::string word = "";
        for (int j = 0; j < len; ++j)
            word += rand() % 26 + 97;
        _stringArray.insert(rand() % (_stringArray.size() - 1), word);
    }

    print(_stringArray);
}

int main()
{
  srand(time(NULL));
  CArray <int> intCArray;
  pushBackInt(intCArray);
  sortInt(intCArray);
  eraseEverySecondInt(intCArray);
  insertInt(intCArray);
  clearInt(intCArray);

  CArray <std::string> stringCArray;
  pushBackString(stringCArray);
  sortString(stringCArray);
  eraseWithPattern(stringCArray, "abcde");
  insertString(stringCArray);
  system("pause");
}
