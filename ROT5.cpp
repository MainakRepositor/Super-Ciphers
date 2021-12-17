#include <iostream>
#include <cstdlib>
#include <regex>

using namespace std;

void cipherEncryption(string rot5, string zeroToNine){
    cout << "Message can only be positive integer numbers" << endl;
    string message;
    cout << "Enter message: ";
    getline(cin, message);
    cin.ignore();

    // checking if input is integer or not
    regex intReg("[\\d\\s]+");
    // \\d = integers
    // \\s = white space
    // [] a set, with logical OR
    // + = one or more times

    if(!regex_match(message,intReg)){
        cout << "Entered message is not an integer" << endl;
        exit(EXIT_FAILURE);
    }

    string encrypText = "";
    for (int i = 0; i < message.length(); i++) {
        if(message[i] == 32){
            encrypText += " ";
        } else {
            for (int j = 0; j < zeroToNine.length(); j++){
                if(message[i] == zeroToNine[j]){
                    encrypText += rot5[j];
                }
            } // inner for
        } // if-else
    } //for

    cout << "Encrypted Text: " << encrypText;
}

void cipherDecryption(string rot5, string zeroToNine) {

cout << "Message can only be positive integer numbers" << endl;
    string message;
    cout << "Enter message: ";
    getline(cin, message);
    cin.ignore();

    // checking if input is integer or not
    regex intReg("[\\d\\s]+");
    // \\d = integers
    // \\s = white space
    // [] a set, with logical OR
    // + = one or more times

    if(!regex_match(message,intReg)){
        cout << "Entered message is not an integer" << endl;
        exit(EXIT_FAILURE);
    }

    string decrypText = "";
    for (int i = 0; i < message.length(); i++) {
        if(message[i] == 32){
            decrypText += " ";
        } else {
            for (int j = 0; j < zeroToNine.length(); j++){
                if(message[i] == rot5[j]){
                    decrypText += zeroToNine[j];
                }
            } // inner for
        } // if-else
    } //for

    cout << "Decrypted Text: " << decrypText;

}

int main()
{
    int choice;
    cout << "1. Encryption\n2. Decryption\nChoose(1,2): ";
    cin >> choice;
    cin.ignore();

    string rot5 = "5678901234";
    string zeroToNine = "0123456789";

    if(choice == 1){
        cout << endl << "---Encryption---" << endl;
        cipherEncryption(rot5, zeroToNine);
    } else if (choice == 2){
        cout << endl << "---Decryption---" << endl;
        cipherDecryption(rot5, zeroToNine);
    } else {
        cout << endl << "Wrong choice" << endl;
    }

    return 0;
}
