#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main() {
    cout << "Enter two prime numbers:" << endl;
    int p, q;
    cin >> p;
    cin >> q;
    double n = p * q;
    float fn = (p - 1) * (q - 1);
    int e = 3;
    int d = 0;
    for (int i = 0; i < 3; i++) {
        int num = (1 + (i * fn));
        if (num % e == 0) {
            d = num / e;
            cout << "d = " << d << endl;
            break;
        }
    }
    cout << "Enter string to be encrypted:" << endl;
    string input;
    cin.ignore();  // Ignore any newline character left in the input buffer
    getline(cin, input);  // Reading the whole line as input

    cout << "String to be encrypted: " << input << endl;
    
    // Encrypt each character in the string
    cout << "Encrypted text: ";
    for (char c : input) {
        int enc = int(c);  // Get the ASCII value of the character

        if (enc < n) {
            int power = pow(enc, e);  // Perform encryption: (ASCII^e) mod n
            int encrypted = fmod(power, n);  // Modulo operation
            cout << encrypted << " ";  // Print encrypted ASCII value
        } else {
            cout << "Character " << c << " can't be encrypted (out of range)." << endl;
        }
    }
    cout << endl;

    // Decrypt each character
    cout << "Decrypted text: ";
    for (char c : input) {
        int enc = int(c);  // Get the ASCII value of the character

        if (enc < n) {
            int power = pow(enc, e);  // Perform encryption: (ASCII^e) mod n
            int encrypted = fmod(power, n);  // Modulo operation
            
            long double dpow = pow(encrypted, d);  // Decrypt: (Encrypted^d) mod n
            int decrypted = fmod(dpow, n);  // Modulo operation to get back the original ASCII
            cout << char(decrypted);  // Convert back to character and print
        } else {
            cout << "Character " << c << " can't be decrypted (out of range)." << endl;
        }
    }
    cout << endl;

    return 0;
}
