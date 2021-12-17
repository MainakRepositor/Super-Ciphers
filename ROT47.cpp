#include <iostream>

using namespace std;

void cipherEncryption(){
    string message;
    cout << "Enter message: ";
    getline(cin, message);
    cin.ignore();

    int key = 47;
    string encrypText = "";

    for (int i = 0; i < message.length(); i++){
        int temp = message[i] + key;
        if(message[i] == 32){
            encrypText += " ";
        } else if (temp > 126){
            temp -= 94;
            encrypText += temp;
        } else {
            encrypText += temp;
        } // if-else
    } // for

    cout << "Encrypted Text: " << encrypText;
}

void cipherDecryption(){
    string message;
    cout << "Enter message: ";
    getline(cin, message);
    cin.ignore();

    int key = 47;
    string decrypText = "";

    for (int i = 0; i < message.length(); i++){
        int temp = message[i] - key;
        if(message[i] == 32){
            decrypText += " ";
        } else if (temp < 32){
            temp += 94;
            decrypText += temp;
        } else {
            decrypText += temp;
        } // if-else
    } // for

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
        cout << "Invalid Choice";
    }

    return 0;
}
