#include <iostream>
#include<string>

using namespace std;

void Quadruples(string t[],int n)
{
    cout<<"\n\t\tQuadruples\n=======================================\nop\t arg1\t arg2\t result";
    cout << "\n=======================================";
    for(int i=0; i<n;i++)
    {
        cout<<"\n"<<t[i][3]<<"\t"<<t[i][2]<<"\t"<<t[i][4]<<"\t"<<t[i][0]; 
    }
    cout <<"\n---------------------------------------\n";
}

void Triples(string t[],int n)
{
    cout << "\n\t\tTriples\n=======================================\nop\t arg1\t arg2";
    cout << "\n=======================================";
    for(int i=0; i<n;i++)
    {
        cout<<"\n"<<t[i][3]<<"\t"<<t[i][2]<<"\t"<<t[i][4]<<"\t";
    }
    cout << "\n---------------------------------------";
}

void input()
{
    string t[10];
    int n;
    cout<<"Enter number of statements: "; cin>>n;
    cout << "---------------------------------------\n\tEnter the "<<n<<" statements\n---------------------------------------\n";

    for(int i=0; i <n;i++)
    {
        cin>>t[i];
    }
    Quadruples(t,n);
    Triples(t,n);
}

int main()
{
    input();
    return 0;
}
