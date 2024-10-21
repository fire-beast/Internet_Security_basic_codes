#include<iostream>
using namespace std;
int main()
{
    int b,c;
    cout<<"Enter 2 numbers:"<<endl;
    cin>>b;
    cin>>c;
    while(c!=0){
    int rem=b%c;
    int q=b/c;
        cout<<b<<"="<<c<<"*"<<q<<"+"<<rem<<endl;
    b=c;
    c=rem;
    }
    cout<<"GCD(b,c)="<<b<<endl;
}
