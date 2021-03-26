/* toupper example */
#include <ctype.h>
#include <cstring>
#include <iostream>
using namespace std;
int main ()
{
  int i=0;
  string str ="Test String.";
  char c;
  while (str[i])
  {
    c=str[i];
    putchar (toupper(c));
    i++;
  }
  return 0;
}
