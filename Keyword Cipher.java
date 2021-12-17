import java.util.Scanner;

public class KeywordCipher {

    private static Scanner in;
    private static String keyword = "";
    private static String alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    public static void main(String[] args){

        in = new Scanner(System.in);

        KeywordPicker();

        System.out.print("1. Encryption\n2. Decryption\nChoose(1,2): ");
        int choice = in.nextInt();
        in.nextLine();

        if (choice == 1){
            System.out.println("---Encryption---");
            cipherEncryption();

        } else if (choice == 2){
            System.out.println("---Decryption---");
            cipherDecryption();

        } else {
            System.out.println("Incorrect Choice");
        }

    }

    private static void cipherDecryption() {
        System.out.print("Enter message: ");
        String message = in.nextLine();
        in.nextLine();

        message = message.toUpperCase();

        String decrypText = "";
        for (int i = 0; i < message.length(); i++) {
            if(message.charAt(i) == (char)32){
                decrypText += " ";
            } else {
                int counter = 0;
                for (int j = 0; j < alpha.length(); j++) {
                    if(message.charAt(i) == keyword.charAt(j)){
                        //find character's loaction in keyword variable
                        //character at that location in alphabet is decrypted letter
                        decrypText += alpha.charAt(counter);
                        break;
                    } else {
                        counter++;
                    } // if-else
                } // inner for
            } //if-else
        } // for

        System.out.println("Decrypted Text: " + decrypText);
    }

    private static void cipherEncryption() {
        System.out.print("Enter message: ");
        String message = in.nextLine();
        in.nextLine();

        message = message.toUpperCase();

        String encrypText = "";
        for (int i = 0; i < message.length(); i++) {
            if(message.charAt(i) == (char)32){
                encrypText += " ";
            } else {
                int counter = 0;
                for (int j = 0; j < alpha.length(); j++) {
                    if(message.charAt(i) == alpha.charAt(j)){
                        // character at count location of alphabet is encrypted letter in key
                        encrypText += keyword.charAt(counter);
                        break;
                    } else {
                        counter++;
                    } // if-else
                } // inner for
            } //if-else
        } // for

        System.out.println("Encrypted Text: " + encrypText);
    }

    private static void KeywordPicker() {
        System.out.println("Keyword must contain each letter A-Z exactly once, no repeating letter");
        System.out.print("Enter Keyword: ");
        String keywr = in.nextLine();
        keywr = keywr.toUpperCase();
        in.nextLine();

        // checking repetition of letters in keyword
        for (int i = 0; i < keywr.length(); i++) {
            int pos = i;
            for (int j = 0; j < keywr.length(); j++) {
                if (pos == j){
                    //skipping the letter comparison with itself
                    continue;
                } else if(keywr.charAt(i) == keywr.charAt(j)){
                    System.out.println("Letter \"" + keywr.charAt(i) + "\" Repeating in keyword");
                    System.exit(0);
                } // if-else
            } // inner for
        } // for

        //generating alphabet with keyword
        String temp = "";
        for (int i = 0; i < keywr.length(); i++) {
            temp += keywr.charAt(i);
        }
        for (int i = 0; i < 26; i++) {
            temp += (char)(i+65);
        }

        //removing letters of keyword from alphabet in temp and adding result in keyword variable
        for (int i = 0; i < temp.length(); i++) {
            Boolean found = false;
            for (int j = 0; j < keyword.length(); j++) {
                if (temp.charAt(i) == keyword.charAt(j)){
                    found = true;
                    break; // no need to iterate any further
                }
            } // inner for
            if (found == false){
                keyword += temp.charAt(i);
            }
        } // for

//        System.out.println(keyword);
    }



}
