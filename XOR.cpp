#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void cipherEncryption(){
    string msg;
    cout << "Enter message: ";
    getline(cin, msg);

    string key;
    cout << "Enter key: ";
    getline(cin, key);

    string encrypHexa = "";
    int keyItr = 0;
    stringstream res;
    for (int i = 0; i < msg.length(); i++){
        int temp = msg[i] ^ key[keyItr];

        res << hex << setfill('0') << std::setw(2) << (int)temp;
        keyItr++;
        if (keyItr >= key.length()){
            // once all of key's letters are used, repeat the key
            keyItr = 0;
        }
    }

    res >> encrypHexa;
    cout << "Encrypted Text: " << encrypHexa;
}

void cipherDecryption(){
    string msg;
    cout << "Enter message: ";
    getline(cin, msg);

    string key;
    cout << "Enter key: ";
    getline(cin, key);

    string hexToUni = "";
    for (int i = 0; i < msg.length()-1; i+=2){
        // splitting hex into a pair of two
        string output = msg.substr(i, 2);
        // converting hex into unicode
        int decimal = strtol(output.c_str(), NULL, 16);
        hexToUni += (char)decimal;
    }

    string decrypText = "";
    int keyItr = 0;
    for (int i = 0; i < hexToUni.length(); i++){
        int temp = hexToUni[i] ^ key[keyItr];

        decrypText += (char)temp;
        keyItr++;
        if (keyItr >= key.length()){
            // once all of key's letters are used, repeat the key
            keyItr = 0;
        }
    }

    cout << "Decrypted Text: " << decrypText;
}

int main()
{
    cout << "1. Encryption\n2. Decryption\nChoose(1,2): ";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1){
        cout << endl << "---Encryption---" << endl;
        cipherEncryption();
    } else if (choice == 2){
        cout << endl << "---Decryption---" << endl;
        cipherDecryption();
    } else {
        cout << endl << "Wrong choice" << endl;
    }

    return 0;
}
