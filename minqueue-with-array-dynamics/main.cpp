#include <iostream>

class MinqueueWithArrayDynamic
{
private:
  int lengthInit = 9;
  int lengthInitTmp = 1;
  int *arrayDynamic = new int[lengthInit];
  int *arrayDynamicTmp = new int[lengthInitTmp];
  int loopController = 0;

public:
  MinqueueWithArrayDynamic()
  {
    for (int i = 0; i < lengthInit; i++)
    {
      arrayDynamic[i] = -1;
    }
  }

  void insert(int input)
  {
    for (int i = 0; i < lengthInit; i++)
    {
      if (arrayDynamic[i] == -1)
      {
        arrayDynamic[i] = input;
        break;
      }
    }

    remove(input);

    insertArrayDynamic(input);
  };

  void insertArrayDynamic(int target)
  {
    if (loopController == 0)
    {
      arrayDynamicTmp[0] = target;
      loopController = 1;
    }
    else
    {
      int newLength = lengthInitTmp + 1;
      int *newArray = new int[newLength];

      for (int i = 0; i < newLength; i++)
      {
        newArray[i] = arrayDynamicTmp[i];
      }
      newArray[newLength - 1] = target;

      delete[] arrayDynamicTmp;

      arrayDynamicTmp = newArray;

      lengthInitTmp++;
    }
  }

  void remove(int target)
  {
    if (loopController == 1)
    {
      int newLengthArray = 0;

      for (int i = 0; i < lengthInitTmp; i++)
      {
        if (target < arrayDynamicTmp[i])
        {
          arrayDynamicTmp[i] = -1;
        }
      }

      for (int i = 0; i < lengthInitTmp; i++)
      {
        if (arrayDynamicTmp[i] != -1)
        {
          newLengthArray++;
        }
      }

      int *newArray = new int[newLengthArray];

      for (int i = 0, j = 0; i < lengthInitTmp; i++)
      {
        if (arrayDynamicTmp[i] != -1)
        {
          newArray[j] = arrayDynamicTmp[i];
          j++;
        }
      }

      delete[] arrayDynamicTmp;

      arrayDynamicTmp = newArray;

      lengthInitTmp = newLengthArray;
    }
  }
  void list()
  {
    std::cout << "Minqueue: ";
    for (int i = 0; i < lengthInit; i++)
    {
      std::cout << arrayDynamic[i] << " ";
    }
    std::cout << " " << std::endl;
  };

  int getMin()
  {
    return arrayDynamicTmp[0];
  }
};

int main()
{
  MinqueueWithArrayDynamic minqueue;
  for (int i = 0; i < 9; i++)
  {
    int input;
    std::cin >> input;
    minqueue.insert(input);
  }

  minqueue.list();

  std::cout << minqueue.getMin() << std::endl;

  return 0;
}