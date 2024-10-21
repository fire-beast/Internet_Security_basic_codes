#include <iostream>
using namespace std;
int main() {
    int b, c;
    cout<<"Enter 2 numbers:" << endl;
    cin>>b>>c;
    int x0=1, x1=0,y0=0,y1=1;
    int a=b,b1=c;
    while (b1!= 0){
        int q=a/b1;
        int r=a%b1;
        int tempX=x0-q*x1;
        int tempY=y0-q*y1;
        a=b1;
        b1=r;
        x0=x1;
        y0=y1;
        x1=tempX;
        y1=tempY;
    }
    cout<<"gcd("<<b<<", "<<c<<") = "<<a<<endl;
    cout<<b<< "*("<<x0<< ") + "<<c<< "*("<<y0<<") = "<<a<< endl;
}
