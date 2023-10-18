#include <iostream>
#include <exception>
#include <limits>

int read(int second_elem);
int getSign(int value);
bool isSameSign(int a, int b);
int sum(int a, int b);

int main()
{
  int first_elem = 0;
  int second_elem = 0;
  int third_elem = 0;
  int forth_elem = 0;
  int cou = 0;
  try
  {
    forth_elem = read(first_elem);
    while (forth_elem != 0)
    {
      if ((forth_elem == sum(second_elem, third_elem)) && (second_elem != 0))
      {
        cou += 1;
      }
      first_elem = second_elem;
      second_elem = third_elem;
      third_elem = forth_elem;
      forth_elem = read(first_elem);
    }
    std::cout << cou << "\n";
    return 0;
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what();
    return 2;
  }
  catch (const std::istream::failure & e)
  {
    std::cerr << "Not a sequence";
    return 1;
  }
  catch (const std::overflow_error & e)
  {
    std::cerr << e.what();
    return 1;
  }
}

int read(int second_elem)
{
  int forth_elem;
  std::cin.exceptions(std::istream::failbit);
  std::cin >> forth_elem;
  if (forth_elem == 0 && second_elem == 0)
  {
    throw std::logic_error("Not enough arguments");
  }
  return forth_elem;
}

int getSign(int value)
{
  return (value > 0) ? 1 : ((value < 0) ? -1 : 0);
}

bool isSameSign(int a, int b)
{
  return getSign(a) * getSign(b) > 0;
}

int sum(int a, int b)
{
  const int max_int = std::numeric_limits< int >::max();
  const int min_int = std::numeric_limits< int >::min();
  if (isSameSign(a, b) && (a > 0))
  {
    if (max_int - a <= b)
    {
      throw std::overflow_error("Signed overflow");
    }
  }
  if (isSameSign(a, b) && (a < 0))
  {
    if (min_int - a >= b)
    {
      throw std::overflow_error("Signed overflow");
    }
  }
  return a + b;
}
