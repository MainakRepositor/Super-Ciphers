#include <iostream>
#include <regex>

using namespace std;

void cipherDecryption(){
    string rot5 = "5678901234";
    string zeroToNine = "0123456789";
    int rot13Key = 13;

    cout << "Message can be alphanumeric" << endl;
    string message;
    cout << "Enter message: ";
    getline(cin, message);
    cin.ignore();

    // message to uppercase
    for(int i = 0; i < message.length(); i++){
        message[i] = toupper(message[i]);
    }

    string decrypText = "";
    regex intReg("[\\s\\d]+");
    regex strReg("[\\s\\w]+");

    for (int i = 0; i < message.length(); i++){
        string temp = "";
        temp += message[i];

        if(message[i] == 32){
            decrypText += " ";
        } else if (regex_match(temp, intReg)){
            // ROT5
            for (int j = 0; j < zeroToNine.length(); j++){
                if (message[i] == rot5[j]){
                    decrypText += zeroToNine[j];
                }
            } // inner for
        } else if (regex_match(temp, strReg)){
            // ROT13
            int chTemp = temp[0] - rot13Key;
            if(chTemp < 65){
                chTemp += 26;
                decrypText += (char)chTemp;
            } else {
                decrypText += (char)chTemp;
            }
        } // if else
    } // for

    cout << "Decrypted Text: " << decrypText;
}

void cipherEncryption(){
    string rot5 = "5678901234";
    string zeroToNine = "0123456789";
    int rot13Key = 13;

    cout << "Message can be alphanumeric" << endl;
    string message;
    cout << "Enter message: ";
    getline(cin, message);
    cin.ignore();

    // message to uppercase
    for(int i = 0; i < message.length(); i++){
        message[i] = toupper(message[i]);
    }

    string encrypText = "";
    regex intReg("[\\s\\d]+");
    regex strReg("[\\s\\w]+");

    for (int i = 0; i < message.length(); i++){
        string temp = "";
        temp += message[i];

        if(message[i] == 32){
            encrypText += " ";
        } else if (regex_match(temp, intReg)){
            // ROT5
            for (int j = 0; j < zeroToNine.length(); j++){
                if (message[i] == zeroToNine[j]){
                    encrypText += rot5[j];
                }
            } // inner for
        } else if (regex_match(temp, strReg)){
            // ROT13
            int chTemp = temp[0] + rot13Key;
            if(chTemp > 90){
                chTemp -= 26;
                encrypText += (char)chTemp;
            } else {
                encrypText += (char)chTemp;
            }
        } // if else
    } // for

    cout << "Encrypted Text: " << encrypText;
}

int main()
{
    cout << "1. Encryption\n2. Decryption\n3. Choose(1,2): " << endl;
    int choice;
    cin >> choice;
    cin.ignore();

    if(choice == 1){
        cout << endl << "---Encryption---" << endl;
        cipherEncryption();

    } else if(choice == 2){
        cout << endl << "---Decryption---" << endl;
        cipherDecryption();

    } else {
        cout << endl << "Invalid Choice" << endl;
    }
    return 0;
}
