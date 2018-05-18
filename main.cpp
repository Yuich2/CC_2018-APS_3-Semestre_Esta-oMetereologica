#include <iostream>
#include <windows.h>

#include "Temperatura.h"

using namespace std;

int main()
{
    int n;
    int op;
    double t;
  
    Celsius *p1=new Celsius();
    Fahrenheit *p2=new Fahrenheit();
    Kelvin *p3=new Kelvin();
            
    cout << "Bem vindo à Mini estação meteologica"<< endl;
    cout << "Selecione uma Opção:"<< endl;
    cout << "1)Celsius\n2)Fahrenheit\n3)Kelvin" << endl;
    cin >> op;
    
    while (1) // Faz com que o resultado apareca a cada () min
    {
        if (op == 1)
        {
            // t = n ;
            cout<<"--------------------------------------------------------------"<<endl;
            cout<<"Celsius"<<endl;
            p1-> imp();
           
        }
        else if (op == 2)
        {
            // t = (n *1.8) + 32;
            cout<<"--------------------------------------------------------------"<<endl;
            cout<<"Fahrenheit"<<endl;
            p2-> imp();
        }
        else if (op == 3)
        {
            // t = n + 273
            cout<<"--------------------------------------------------------------"<<endl;
            cout << "Kelvin"<<endl;
            p3-> imp();

        }
        Sleep (300);
    }
    return 0;
}



 