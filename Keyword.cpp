#include <iostream>
#include <cstdlib>

using namespace std;

string keywordPicker(){
    cout << "Keyword must contain each letter A-Z exactly once, no repetition of letter should occur" << endl;
    string keywrd;
    cout << "Enter keyword: ";
    getline(cin, keywrd);
    cin.ignore();

    //keyword to uppercase
    for(int i = 0; i < keywrd.length(); i++){
        keywrd[i] = toupper(keywrd[i]);
    }

    //checking repetition of letter in keyword
    for (int i = 0; i < keywrd.length(); i++){
        int pos = i;
        for(int j = 0; j < keywrd.length(); j++){
            if(pos == j){
                continue;
            } else if(keywrd[i] == keywrd[j]){
                cout << "Letter \"" << keywrd[i] << "\" Repeating in keyword" << endl;
                exit(EXIT_FAILURE); // terminating the program
            }
        } //inner for
    } // for

    //generating alphabet with keyword
    string temp = "";
    for(int i = 0; i < keywrd.length(); i++){
        temp += keywrd[i];
    }
    for(int i = 0; i < 26; i++){
        temp += (char)(i+65);
    }

    //removing letters of keyword from alphabet
    for (int i = 0; i < temp.length(); i++){
        bool found = false;
        for(int j = 0; j < keywrd.length(); j++){
            if(temp[i] == keywrd[j]){
                found = true;
                break; // no need to iterate any further
            }
        } // inner for
        if(found == false){
            keywrd += temp[i];
        }
    } // for loop

//    cout << keywrd;

    return keywrd;
}

void cipherEncryption(string alpha, string keywrd){
    string message;
    cout << "Enter message: ";
    getline(cin, message);
    cin.ignore();

    //message to uppercase
    for(int i = 0; i < message.length(); i++){
        message[i] = toupper(message[i]);
    }

    string encryText = "";
    for (int i = 0; i < message.length(); i++){
        if(message[i] == (char)32){
            encryText += " ";
        } else {
            int counter = 0;
            for (int j = 0; j < alpha.length(); j++){
                if(message[i] == alpha[j]){
                    //character at count location of alphabet is encrypted letter in key
                    encryText += keywrd[counter];
                    break;
                } else {
                    counter++;
                }
            } // inner for
        } //if-else
    } //for

    cout << "Encrypted Text: " << encryText;
}

void cipherDecryption(string alpha, string keywrd){
    string message;
    cout << "Enter Encrypted Message: ";
    getline(cin, message);
    cin.ignore();

    //message to uppercase
    for(int i = 0; i < message.length(); i++){
        message[i] = toupper(message[i]);
    }

    string decryText = "";
    for (int i = 0; i < message.length(); i++){
        if(message[i] == (char)32){
            decryText += " ";
        } else {
            int counter = 0;
            for (int j = 0; j < alpha.length(); j++){
                if(message[i] == keywrd[j]){
                    //character at count location of alphabet is encrypted letter in key
                    decryText += alpha[counter];
                    break;
                } else {
                    counter++;
                }
            } // inner for
        } //if-else
    } //for

    cout << "Decrypted Text: " << decryText;
}

int main()
{
    int choice;
    cout << "1. Encryption\n2. Decryption\nChoose(1,2): ";
    cin >> choice;
    cin.ignore();

    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string keywrd = keywordPicker();

    if(choice == 1){
        cout << endl << "---Encryption---" << endl;
        cipherEncryption(alpha, keywrd);

    } else if (choice == 2){
        cout << endl << "---Decryption---" << endl;
        cipherDecryption(alpha, keywrd);

    } else {
        cout << endl << "Wrong choice" << endl;
    }

    return 0;
}
