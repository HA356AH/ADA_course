#include <iostream>
using namespace std;

//functions
float Addition(float a, float b)
{
  return a+b;
}
float Subtraction(float a, float b)
{
  return a-b;
}

float Multiplication(float a, float b)
{
  return a*b;
}

float Division(float a, float b)
{
  if (b != 0)
  {
    return a/b;
  } 
    cout<<"error cannot divide by 0\n";
    return 0;
}


/*
  int main(){
  //code A
  float a, b, c = 0; 
  int opt;
  // enter the operands
  cout<<"enter the operands: ";
  cin >> a >> b;
  // OPT-> 0-Addition, 1-Subtraction, 3-Multiplication, 4-Division
  cout<<"--------------------------\n"
      <<"0-Addition\n1-Subtraction\n2-Multiplication\n3-Division\n";
  cout<<"select an opcion: ";
  cin >> opt;
  switch( opt )
  {
  case 0: c = Addition(a, b); break;
  case 1: c = Subtraction(a, b); break;
  case 2: c = Multiplication(a, b); break;
  case 3: c = Division(a, b); break;
  default: cout<<"error\n";
  // more cases operations go here
  }
  cout<<"result: "<<c<<endl;

  return 0;
}
*/

int main()
{
  // Code B
    typedef float (*lpfnOperation)(float, float);
    lpfnOperation vpf[4] = {&::Addition, &::Subtraction,
    &::Multiplication, &::Division};
  
    float a, b, c; int opt;
  cout<<"enter the operands: ";
    cin >> a >> b;
    cout<<"--------------------------\n"
        <<"0-Addition\n1-Subtraction\n2-Multiplication\n3-Division\n"
        <<"select an opcion: ";
    cin >> opt;
  // The next line replaces the switch and replaces the whole switch
    c = (*vpf[opt])(a, b);
    cout<<"result: "<<c<<endl;

  return 0;
}