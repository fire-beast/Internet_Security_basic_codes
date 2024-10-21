#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    long int p, g;
    cout << "Enter the p and g (prime numbers): ";
    cin >> p;
    cin>>g;
    long int a = 4, b = 3;
    long int A = (long int)pow(g, a) % p;
    cout << "Alice's key: " << A << endl;
    long int B = (long int)pow(g, b) % p;
    cout << "Bob's key: " << B << endl;
    int x = (long int)pow(B, a) % p;
    int y = (long int)pow(A, b) % p;
    cout << "Alice's shared secret key: " << x << endl;
    cout << "Bob's shared secret key: " << y << endl;
}
