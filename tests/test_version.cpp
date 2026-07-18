#include <iostream>
#include <cstdlib>

int main()
{
  int version = 10;

  if (version < 0)
  {
    std::cerr << "Wrong version";
    return 1;
  }

  return 0;
}