#include <iostream>
#include <regex>

using namespace std;

int moduloFunc(int a, int b){
    int result = a % b;
    if (result < 0){
        result += b;
    }
    return result;
}

void cipherEncryption(){
    string msg;
    cout << "Enter message: ";
    getline(cin, msg);

    // message to uppercase
    for (int i = 0; i < msg.length(); i++){
        msg[i] = toupper(msg[i]);
    }

    // removing white space from msg
    msg = regex_replace(msg, regex("\\s+"), "");

    // if msg.length %2 != 0 perform padding
    int lenChk = 0;
    if(msg.length()%2 != 0){
        msg += "0";
        lenChk = 1;
    }

    // message to 2x msg.length/2 matrix
    int msg2D[2][msg.length()/2];
    int itr1 = 0;
    int itr2 = 0;
    for (int i = 0; i < msg.length(); i++){
        if(i%2 == 0){
            msg2D[0][itr1] = msg[i] - 65;
            itr1++;
        } else {
            msg2D[1][itr2] = msg[i] - 65;
            itr2++;
        } //if-else
    } // for

//    // testing matrix
//    for(int i = 0; i < 2; i++){
//        for (int j = 0; j < msg.length()/2; j++){
//            cout << (char)(msg2D[i][j]+65) << " ";
//        }
//        cout << endl;
//    }

    cout << "Enter 4 letter key string: ";
    string key;
    getline(cin, key);

    // key to uppercase
    for (int i = 0; i < key.length(); i++){
        key[i] = toupper(key[i]);
    }

    // removing white space from key
    key = regex_replace(key, regex("\\s+"), "");

    // key to 2x2 matrix
    int key2D[2][2];
    int itr3 = 0;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j<2; j++){
            key2D[i][j] = key[itr3]-65;
            itr3++;
        }
    }

    // checking validity of the key
    // finding determinant
    int deter = key2D[0][0] * key2D[1][1] - key2D[0][1] * key2D[1][0];
    deter = moduloFunc(deter, 26);

    // finding multiplicative inverse
    int mulInv = -1;
    for (int i=0; i<26; i++){
        int tempInv = deter * i;
        if (moduloFunc(tempInv, 26) == 1){
            mulInv = i;
            break;
        } else {
            continue;
        }
    } // for

    if (mulInv == -1){
        cout << "invalid key" << endl;
        exit(EXIT_FAILURE);
    }

    string encrypText = "";
    int itrCount = msg.length()/2;
    if (lenChk == 0){
        // if msg.length % 2 == 0
        for (int i = 0; i < itrCount; i++){
            int temp1 = msg2D[0][i] * key2D[0][0] + msg2D[1][i] * key2D[0][1];
            encrypText += (char)((temp1 % 26) + 65);
            int temp2 = msg2D[0][i] * key2D[1][0] + msg2D[1][i] * key2D[1][1];
            encrypText += (char)((temp2 % 26) + 65);
        }
    } else {
        // if msg.length % 2 == 0
        for (int i = 0; i < itrCount-1; i++){
            int temp1 = msg2D[0][i] * key2D[0][0] + msg2D[1][i] * key2D[0][1];
            encrypText += (char)((temp1 % 26) + 65);
            int temp2 = msg2D[0][i] * key2D[1][0] + msg2D[1][i] * key2D[1][1];
            encrypText += (char)((temp2 % 26) + 65);
        }
    }

    cout << endl << "Encrypted text: " << encrypText << endl;
}

void cipherDecryption(){
    string msg;
    cout << "Enter message: ";
    getline(cin, msg);

    // message to uppercase
    for (int i = 0; i < msg.length(); i++){
        msg[i] = toupper(msg[i]);
    }

    // removing white space from msg
    msg = regex_replace(msg, regex("\\s+"), "");

    // if msg.length %2 != 0 perform padding
    int lenChk = 0;
    if(msg.length()%2 != 0){
        msg += "0";
        lenChk = 1;
    }

    // message to 2x msg.length/2 matrix
    int msg2D[2][msg.length()/2];
    int itr1 = 0;
    int itr2 = 0;
    for (int i = 0; i < msg.length(); i++){
        if(i%2 == 0){
            msg2D[0][itr1] = msg[i] - 65;
            itr1++;
        } else {
            msg2D[1][itr2] = msg[i] - 65;
            itr2++;
        } //if-else
    } // for

//    // testing matrix
//    for(int i = 0; i < 2; i++){
//        for (int j = 0; j < msg.length()/2; j++){
//            cout << (char)(msg2D[i][j]+65) << " ";
//        }
//        cout << endl;
//    }

    cout << "Enter 4 letter key string: ";
    string key;
    getline(cin, key);

    // key to uppercase
    for (int i = 0; i < key.length(); i++){
        key[i] = toupper(key[i]);
    }

    // removing white space from key
    key = regex_replace(key, regex("\\s+"), "");

    // key to 2x2 matrix
    int key2D[2][2];
    int itr3 = 0;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j<2; j++){
            key2D[i][j] = key[itr3]-65;
            itr3++;
        }
    }

    // finding determinant
    int deter = key2D[0][0] * key2D[1][1] - key2D[0][1] * key2D[1][0];
    deter = moduloFunc(deter, 26);

    // finding multiplicative inverse
    int mulInv = -1;
    for (int i=0; i<26; i++){
        int tempInv = deter * i;
        if (moduloFunc(tempInv, 26) == 1){
            mulInv = i;
            break;
        } else {
            continue;
        }
    } // for


    // adjugate matrix
    //swapping
    swap(key2D[0][0],key2D[1][1]);

    // changing signs
    key2D[0][1] *= -1;
    key2D[1][0] *= -1;

    key2D[0][1] = moduloFunc(key2D[0][1], 26);
    key2D[1][0] = moduloFunc(key2D[1][0], 26);

    // multiplying multiplicative inverse with adjugate matrix
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            key2D[i][j] *= mulInv;
        }
    }
    for (int i=0; i<2;i++){
        for(int j =0; j <2; j++){
            key2D[i][j] = moduloFunc(key2D[i][j], 26);
        }
    }

    // ciphertext to plain text
    string decrypText = "";
    int itrCount = msg.length()/2;
    if (lenChk == 0){
        // if msg.length % 2 == 0
        for (int i = 0; i < itrCount; i++){
            int temp1 = msg2D[0][i] * key2D[0][0] + msg2D[1][i] * key2D[0][1];
            decrypText += (char)((temp1 % 26) + 65);
            int temp2 = msg2D[0][i] * key2D[1][0] + msg2D[1][i] * key2D[1][1];
            decrypText += (char)((temp2 % 26) + 65);
        }
    } else {
        // if msg.length % 2 == 0
        for (int i = 0; i < itrCount-1; i++){
            int temp1 = msg2D[0][i] * key2D[0][0] + msg2D[1][i] * key2D[0][1];
            decrypText += (char)((temp1 % 26) + 65);
            int temp2 = msg2D[0][i] * key2D[1][0] + msg2D[1][i] * key2D[1][1];
            decrypText += (char)((temp2 % 26) + 65);
        }
    }

    cout << endl << "Decrypted text: " << decrypText << endl;

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
