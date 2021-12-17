#include <iostream>

using namespace std;

//we'll be using ASCII in this

int main()
{
    int choice;
    cout << "1. Encryption" << endl << "2. Decryption" << endl << "Enter choice(1,2): ";
    cin >> choice;
    cin.ignore();

    if (choice == 1){
        // encryption
        string msg;
        cout << "Message can only be alphabetic" << endl;
        cout << "Enter message: ";
        getline(cin, msg);

        int key;
        cout << "Enter key (0-25): ";
        cin >> key;
        cin.ignore();

        string encryptedText = msg;

        for (int i = 0; i < msg.size(); i ++){

            if(msg[i]==32){
                continue; //32 is ASCII of space character, we will ignore it
            } else {

                if((msg[i]+key) > 122) {
                    //after lowercase z move back to a, z's ASCII is 122
                    int temp = (msg[i] + key) - 122;
                    encryptedText[i] = 96 + temp;
                } else if (msg[i] + key > 90 && msg[i] <= 96){
                    //after uppercase Z move back to A, 90 is Z's ASCII
                    int temp = (msg[i] + key) - 90;
                    encryptedText[i] = 64 + temp;
                } else {
                    //in case of characters being in between A-Z & a-z
                    encryptedText[i] += key;
                }

            } //if
        } // for

        cout << "Encrypted Message: " << encryptedText;

    } else if (choice == 2){
        //decryption

        string encpMsg;
        cout << "Message can only be alphabetic" << endl;
        cout << "Enter encrypted text: ";
        getline(cin, encpMsg);

        int dcyptKey;
        cout << "Enter key (0-25): ";
        cin >> dcyptKey;
        cin.ignore();

        string decryptedText = encpMsg;

        for (int i = 0; i < encpMsg.size(); i++){
            if(encpMsg[i]==32){
                continue; //ignoring space
            } else {
                if((encpMsg[i] - dcyptKey) < 97 && (encpMsg[i] - dcyptKey) > 90){
                    int temp = (encpMsg[i] - dcyptKey) + 26;
                    decryptedText[i] = temp;
                } else if((encpMsg[i] - dcyptKey) < 65){
                    int temp = (encpMsg[i] - dcyptKey) + 26;
                    decryptedText[i] = temp;
                } else {
                    decryptedText[i] = encpMsg[i] - dcyptKey;
                }
            }
        }

        cout << "Decrypted Message: " << decryptedText << endl;

    } else {
        cout << "Invalid choice";
    }



    return 0;

}
