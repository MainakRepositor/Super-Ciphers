import java.util.Scanner;

public class AtBash {

    private static Scanner in;
    public static void main(String[] args){
        in = new Scanner(System.in);
        System.out.print("1. Encryption\n2. Decryption\nChoose(1,2): ");
        int choice = in.nextInt();
        in.nextLine();

        if(choice == 1){
            System.out.println("---Encryption---");
            cipherEncryption();

        } else if (choice == 2){
            System.out.println("--Decryption---");
            cipherDecryption();

        } else {
            System.out.println("Incorrect choice");
        }
    }

    private static void cipherDecryption() {
        String alpa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String reverseAlpa = "";
        // reversing alphabets
        for (int i = alpa.length()-1; i > -1; i--) {
            reverseAlpa += alpa.charAt(i);
        }

        System.out.print("Enter Encrypted Message: ");
        String message = in.nextLine();
        in.nextLine();

        message = message.toUpperCase();

        String dencryText = "";
        for (int i = 0; i < message.length(); i++) {
            if(message.charAt(i) == (char)32){
                dencryText += " ";
            } else {
                int count = 0;
                for (int j = 0; j < reverseAlpa.length(); j++) {
                    if (message.charAt(i) == reverseAlpa.charAt(j)){
                        dencryText += alpa.charAt(j);
                        break;
                    }
                } // inner for
            } // if-else
        } // for

        System.out.println("Decrypted Text: " + dencryText);
    }

    private static void cipherEncryption() {
        String alpa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String reverseAlpa = "";
        // reversing alphabets
        for (int i = alpa.length()-1; i > -1; i--) {
            reverseAlpa += alpa.charAt(i);
        }

        System.out.print("Enter Message: ");
        String message = in.nextLine();
        in.nextLine();

        message = message.toUpperCase();

        String encryText = "";
        for (int i = 0; i < message.length(); i++) {
            if(message.charAt(i) == (char)32){
                encryText += " ";
            } else {
                int count = 0;
                for (int j = 0; j < alpa.length(); j++) {
                    if (message.charAt(i) == alpa.charAt(j)){
                        encryText += reverseAlpa.charAt(j);
                        break;
                    }
                } // inner for
            } // if-else
        } // for

        System.out.println("Encrypted Text: " + encryText);
    }

}
