#include <iostream>
#include <regex>
#include <string>
#include <sstream>

using namespace std;

string getNumberLocation(string keyword, string kywrdNumListStr) {

    int kywrdNumList[keyword.length()];
    //cout << sizeof(kywrdNumList);
    for (int i = 0; i < sizeof(kywrdNumList)/sizeof(kywrdNumList[0]); i++){
        // using ASCII code '0' is 48, '1' 49 and so on until '9' as 57
        kywrdNumList[i] = kywrdNumListStr[i] - 48;
//        cout << kywrdNumList[i] << endl;
    }

    string numLoc = "";
    for (int i = 1; i < keyword.length() + 1; i++) {
        for (int j = 0; j < keyword.length(); j++) {
            if (kywrdNumList[j] == i){
                numLoc += to_string(j);
            }
        }
    }
    return numLoc;
} // getting number location function

string keywordNumAssign(string keyword){
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int kywrdNumList[keyword.length()];

    int init = 0;
    for (int i = 0; i < alpha.length(); i ++){
        for (int j = 0; j < keyword.length(); j++) {
            if (alpha[i] == keyword[j]){
                init++;
                kywrdNumList[j] = init;
//                cout << kywrdNumList[j];
            }
        } // inner for
    } // for

    string str = "";
    for (int i = 0; i < sizeof(kywrdNumList)/sizeof(kywrdNumList[0]); i++){
//        cout << kywrdNumList[i] << " ";
        str += to_string(kywrdNumList[i]);
    }
//    string str = to_string(kywrdNumList);
//    cout << str;
    return str;
}

void cipherEncryption(){
    string msg;
    cout << "Enter Plain Text: ";
    getline(cin, msg);

    string keyword;
    cout << "Enter Keyword: ";
    getline(cin, keyword);

    // plain text to uppercase
    for (int i = 0; i < msg.length(); i++){
        msg[i] = toupper(msg[i]);
    }

    // replacting whitespace in plain text
    msg = regex_replace(msg,regex("\\s+"), "");

    // keyword to uppercase
    for (int i = 0; i < keyword.length(); i++){
        keyword[i] = toupper(keyword[i]);
    }

    for (int i = 0; i < keyword.length(); i++){
        cout << keyword[i] << " ";
    }
    cout << endl;

    // assigning numbers to keywords
    string kywrdNumListStr = keywordNumAssign(keyword);

    int kywrdNumList[keyword.length()];
    //cout << sizeof(kywrdNumList);
    for (int i = 0; i < sizeof(kywrdNumList)/sizeof(kywrdNumList[0]); i++){
        // using ASCII code '0' is 48, '1' 49 and so on until '9' as 57
        kywrdNumList[i] = kywrdNumListStr[i] - 48;
//        cout << kywrdNumList[i] << endl;
    }
    for (int i: kywrdNumList){
        cout << i << " ";
    }

    // in case characters don't fit the entire grid perfectly.
    int extraLetters = msg.length() % keyword.length();
//    cout << endl << extraLetters << endl;
    int dummyCharacters = keyword.length() - extraLetters;
//    cout << endl << dummyCharacters << endl;

    if (extraLetters != 0){
        for (int i = 0; i < dummyCharacters; i++) {
            msg += ".";
        }
    }

    int numOfRows = msg.length() / keyword.length();
    // Converting message into a grid
    char arr[numOfRows][keyword.length()];

    int z = 0;
    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < keyword.length(); j++) {
            arr[i][j] = msg[z];
            z++;
        }
    }

    cout << endl;
    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < keyword.length(); j++) {
            cout << arr[i][j] << " ";
        } // inner for loop
        cout << endl;
    } // for loop

    // cipher text generation
    string cipherText = "";
    // getting locations of numbers
    string numLoc = getNumberLocation(keyword, kywrdNumListStr);
    cout << numLoc << endl;
    cout << endl;

    for (int i = 0, k = 0; i < numOfRows; i++, k++) {
        int d;
        if (k == keyword.length()){
            break;
        } else {
//            d = Character.getNumericValue(numLoc.charAt(k));
            d = numLoc[k];
            d = d- '0';
        }
        for (int j = 0; j < numOfRows; j++) {
            cipherText += arr[j][d];
        }
    }

    cout << cipherText;

}

void cipherDecryption(){
    string msg;
    cout << "Enter Cipher Text: ";
    getline(cin, msg);

    string keyword;
    cout << "Enter Keyword: ";
    getline(cin, keyword);

    // keyword to uppercase
    for (int i = 0; i < keyword.length(); i++){
        keyword[i] = toupper(keyword[i]);
    }

    // assigning numbers to keywords
    string kywrdNumListStr = keywordNumAssign(keyword);
    int kywrdNumList[keyword.length()];
    //cout << sizeof(kywrdNumList);
    for (int i = 0; i < sizeof(kywrdNumList)/sizeof(kywrdNumList[0]); i++){
        // using ASCII code '0' is 48, '1' 49 and so on until '9' as 57
        kywrdNumList[i] = kywrdNumListStr[i] - 48;
//        cout << kywrdNumList[i] << endl;
    }

    int numOfRows = msg.length() / keyword.length();
    // Converting message into a grid
    char arr[numOfRows][keyword.length()];

    // getting locations of numbers
    string numLoc = getNumberLocation(keyword, kywrdNumListStr);

    for (int i = 0, k = 0; i < msg.length(); i++, k++) {
        int d;
        if (k == keyword.length()){
            k = 0;
        } else {
            d = numLoc[k];
            d = d- '0';
        }
        for (int j = 0; j < numOfRows; j++, i++) {
            arr[j][d] = msg[i];
//            cout << arr[j][d];
        }
        i--;

    }

    cout << endl;

    string plainText = "";

    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < keyword.length(); j++) {
            plainText += arr[i][j];

        } // inner for loop
    } // for loop

    cout << "Plain Text: " << plainText << endl;


}

int main()
{
    cout << "Columnar Transposition Cipher" << endl;
    cout << "1. Encryption\n2. Decryption\nChoose(1,2): ";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1){
        cout << endl << "Encryption" << endl;
        cipherEncryption();
    } else if (choice == 2){
        cout << endl << "Decryption" << endl;
        cipherDecryption();
    } else {
        cout << endl << "Wrong Choice" << endl;
    }

    return 0;
}
