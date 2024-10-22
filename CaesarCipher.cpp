#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char ptxt[50],enctxt[50];
    int key, i;
    char ch;
    cout<<"Enter the text:\n";
    cin.getline(ptxt, 50);
    cout<<"Enter the key:\n";
    cin>>key;
    for(i = 0;i <strlen(ptxt); i++) {
    if (isalpha(ptxt[i])) {
        if (isupper(ptxt[i])) {
            ch=(ptxt[i]+key-65)%26+65;
            enctxt[i]=ch;
        } else {
            ch=(ptxt[i]+key-97)%26+97;
            enctxt[i] = ch;
        }
    }else {
            enctxt[i] = ptxt[i];
    }
    }
    enctxt[i]='\0';
    cout<<"Encrypted Text: " << enctxt << endl;
    char dectxt[50];
    for (i=0;i<strlen(enctxt); i++) {
        if (isalpha(enctxt[i])){
        if (isupper(enctxt[i])) {
            ch=(enctxt[i]-key - 65 +26) % 26 + 65;
            dectxt[i]=ch;
        } else{
            ch=(enctxt[i] - key - 97+26) % 26 + 97;
            dectxt[i] = ch;
        }
    }else {
            dectxt[i] = enctxt[i];
    }
    }
    dectxt[i]='\0';
    cout << "Decrypted Text: " << dectxt << endl;
}
