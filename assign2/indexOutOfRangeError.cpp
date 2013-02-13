#include "indexOutOfRangeError.h"
IndexOutOfRangeError::IndexOutOfRangeError(int i)
{
  index = i;
}
int IndexOutOfRangeError::getIndex()
{
  return index;
}
