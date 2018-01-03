#include <iostream>
#include <string.h>
using namespace std;
class Thousands;
class Hundreds;
class Tens;
class Ones;

class RNInterpreter{
    public:
    RNInterpreter(); // ctor for client
    RNInterpreter(int){}
    // ctor for subclasses, avoids infinite loop
    int interpret(char*); // interpret() for client

    virtual void interpret(char *input, int &total)
    {
        // for internal use
        int index;
        index = 0;
        if (!strncmp(input, nine(), 2))
        {
            total += 9 * multiplier();
            index += 2;
        }
        else if (!strncmp(input, four(), 2))
        {
            total += 4 * multiplier();
            index += 2;
        }
        else
        {
            if (input[0] == five())
            {
                total += 5 * multiplier();
                index = 1;
            }
            else
              index = 0;
            for (int end = index + 3; index < end; index++)
              if (input[index] == one())
                total += 1 * multiplier();
              else
                break;
        }
        strcpy(input, &(input[index]));
    } // remove leading chars processed
    protected:
    virtual char one(){}
    virtual char *four(){}
    virtual char five(){}
    virtual char *nine(){}
    virtual int multiplier(){}

    private:
    RNInterpreter *thousands;
    RNInterpreter *hundreds;
    RNInterpreter *tens;
    RNInterpreter *ones;
};

class Thousands: public RNInterpreter
{
  public:
    // provide 1-arg ctor to avoid infinite loop in base class ctor
    Thousands(int): RNInterpreter(1){}
  protected:
    char one()
    {
        return 'M';
    }
    char *four()
    {
        return "";
    }
    char five()
    {
        return '\0';
    }
    char *nine()
    {
        return "";
    }
    int multiplier()
    {
        return 1000;
    }
};

class Hundreds: public RNInterpreter
{
  public:
    Hundreds(int): RNInterpreter(1){}
  protected:
    char one()
    {
        return 'C';
    }
    char *four()
    {
        return "CD";
    }
    char five()
    {
        return 'D';
    }
    char *nine()
    {
        return "CM";
    }
    int multiplier()
    {
        return 100;
    }
};

class Tens: public RNInterpreter
{
  public:
    Tens(int): RNInterpreter(1){}
  protected:
    char one()
    {
        return 'X';
    }
    char *four()
    {
        return "XL";
    }
    char five()
    {
        return 'L';
    }
    char *nine()
    {
        return "XC";
    }
    int multiplier()
    {
        return 10;
    }
};

class Ones: public RNInterpreter
{
  public:
    Ones(int): RNInterpreter(1){}
  protected:
    char one()
    {
        return 'I';
    }
    char *four()
    {
        return "IV";
    }
    char five()
    {
        return 'V';
    }
    char *nine()
    {
        return "IX";
    }
    int multiplier()
    {
        return 1;
    }
};
RNInterpreter::RNInterpreter()
{
  // use 1-arg ctor to avoid infinite loop
  thousands = new Thousands(1);
  hundreds = new Hundreds(1);
  tens = new Tens(1);
  ones = new Ones(1);
}

int RNInterpreter::interpret(char *input)
{
  int total;
  total = 0;
  thousands->interpret(input, total);
  hundreds->interpret(input, total);
  tens->interpret(input, total);
  ones->interpret(input, total);
  if (strcmp(input, ""))
  // if input was invalid, return 0
    return 0;
  return total;
}

int main()
{
  RNInterpreter interpreter;
  char input[20];
  cout << "Enter Roman Numeral: ";
  while (cin >> input)
  {
    cout << "   interpretation is " << interpreter.interpret(input) << endl;
    cout << "Enter Roman Numeral: ";
  }
}