#include <iostream>

using namespace std;

void cipherEncryption(){
    cout << "Message can only be alphabetic" << endl;
    string message;
    cout << "Enter message: ";
    getline(cin, message);
    cin.ignore();

    //message to upper case
    for(int i = 0; i < message.length(); i++){
        message[i] = toupper(message[i]);
    }

    int key = 13;
    string encrypText = "";

    for(int i = 0; i < message.length(); i++){
        int temp = message[i] + key;
        if(message[i] == 32){
            encrypText += " ";
        } else if(temp > 90){
            temp -= 26;
            encrypText += (char)temp;
        } else {
            encrypText += (char)temp;
        } //if-else
    } //for

    cout << "Encrypted Text: " << encrypText;
}

void cipherDecryption(){
    cout << "Message can only be alphabetic" << endl;
    string message;
    cout << "Enter message: ";
    getline(cin, message);
    cin.ignore();

    //message to upper case
    for(int i = 0; i < message.length(); i++){
        message[i] = toupper(message[i]);
    }

    int key = 13;
    string decrypText = "";

    for(int i = 0; i < message.length(); i++){
        int temp = message[i] - key;
        if(message[i] == 32){
            decrypText += " ";
        } else if(temp < 65){
            temp += 26;
            decrypText += (char)temp;
        } else {
            decrypText += (char)temp;
        } //if-else
    } //for

    cout << "Decrypted Text: " << decrypText;
}

int main()
{
    int choice;
    cout << "1. Encryption\n2. Decryption\nChoose(1,2): ";
    cin >> choice;
    cin.ignore();

    if(choice == 1){
        cout << endl << "---Encryption---" << endl;
        cipherEncryption();

    } else if(choice == 2){
        cout << endl << "---Decryption---" << endl;
        cipherDecryption();

    } else {
        cout << endl << "Wrong Choice" << endl;
    }

    return 0;
}
