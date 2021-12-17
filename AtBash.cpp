#include <iostream>

using namespace std;

void cipherEncryption(){
    string message;
    cout << "Enter Message: ";
    getline(cin, message);
    cin.ignore();

    //message to upper case
    for(int i = 0; i < message.length(); i++){
        message[i] = toupper(message[i]);
    }

    string alpa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string reverseAlpa = "";
    for(int i = alpa.length()-1; i > -1; i--){
        reverseAlpa += alpa[i];
    }

    string encryText = "";
    for(int i = 0; i < message.length(); i++){
        if(message[i] == 32){
            encryText += " ";
        } else {
            for(int j = 0; j < alpa.length(); j++){
                if(message[i] == alpa[j]){
                    encryText += reverseAlpa[j];
                    break;
                }
            } // inner for
        } // if-else
    } // for

    cout << "Encrypted Text: " << encryText;
}

void cipherDecryption(){
    string message;
    cout << "Enter Encrypted Message: ";
    getline(cin, message);
    cin.ignore();

    //message to upper case
    for(int i = 0; i < message.length(); i++){
        message[i] = toupper(message[i]);
    }

    string alpa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string reverseAlpa = "";
    for(int i = alpa.length()-1; i > -1; i--){
        reverseAlpa += alpa[i];
    }

    string dencryText = "";
    for(int i = 0; i < message.length(); i++){
        if(message[i] == 32){
            dencryText += " ";
        } else {
            for(int j = 0; j < reverseAlpa.length(); j++){
                if(message[i] == reverseAlpa[j]){
                    dencryText += alpa[j];
                    break;
                }
            } // inner for
        } // if-else
    } // for

    cout << "Decrypted Text: " << dencryText;
}

int main()
{
    int choice;
    cout << "1. Encryption\n2. Decryption\nChoose(1,2): ";
    cin >> choice;
    cin.ignore();

    if(choice == 1){
        cout << "Encryption" << endl;
        cipherEncryption();
    } else if (choice == 2){
        cout << "Decryption" << endl;
        cipherDecryption();
    } else {
        cout << "Wrong Choice" << endl;
    }
    return 0;
}
