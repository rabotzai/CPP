#include <iostream>

#ifndef BUILD_NUMBER
#define BUILD_NUMBER 0
#endif

int main()
{
  std::cout << "Version: " << BUILD_NUMBER << std::endl;
  std::cout << "Hello, World!" << std::endl;

  return 0;
}