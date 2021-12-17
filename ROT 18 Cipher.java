import java.util.Scanner;

public class ROT18 {
    private static Scanner in;
    public static void main(String[] args){
        in = new Scanner(System.in);
        System.out.print("1. Encryption\n2. Decryption\nChoose(1,2): ");
        int choice = in.nextInt();
        in.nextLine();

        if(choice == 1){
            System.out.println("---Encryption---");
            cipherEncryption();

        } else if(choice == 2){
            System.out.println("---Decryption---");
            cipherDecryption();

        } else {
            System.out.println("Invalid Choice");
        }
    }

    private static void cipherDecryption() {
        String rot5 = "5678901234";
        String zeroToNine = "0123456789";
        int rot13Key = 13;

        System.out.println("Message can be alphanumeric");
        System.out.print("Enter messsage: ");
        String message = in.nextLine();
        in.nextLine();
        message = message.toUpperCase();

        String decrypText = "";
        for (int i = 0; i < message.length(); i++) {
            String temp = message.charAt(i) + "";
            if((int)message.charAt(i) == 32){
                decrypText += " ";
            } else if (temp.matches("[\\s\\d]+")){
                // ROT5
                for (int j = 0; j < zeroToNine.length(); j++) {
                    if(message.charAt(i) == rot5.charAt(j)){
                        decrypText += zeroToNine.charAt(j);
                    }
                } // inner for
            } else if(temp.matches("[\\s\\w]+")) {
                // ROT13
                int chTemp = (int)temp.charAt(0) - rot13Key;
                if (chTemp < 65){
                    chTemp += 26;
                    decrypText += (char)chTemp;
                } else {
                    decrypText += (char)chTemp;
                }
            } // if-else
        } // for

        System.out.println("Decrypted Text: " + decrypText);
    }

    private static void cipherEncryption() {
        String rot5 = "5678901234";
        String zeroToNine = "0123456789";
        int rot13Key = 13;

        System.out.println("Message can be alphanumeric");
        System.out.print("Enter messsage: ");
        String message = in.nextLine();
        in.nextLine();
        message = message.toUpperCase();

        String encrypText = "";
        for (int i = 0; i < message.length(); i++) {
            String temp = message.charAt(i) + "";
            if((int)message.charAt(i) == 32){
                encrypText += " ";
            } else if (temp.matches("[\\s\\d]+")){
                // ROT5
                for (int j = 0; j < zeroToNine.length(); j++) {
                    if(message.charAt(i) == zeroToNine.charAt(j)){
                        encrypText += rot5.charAt(j);
                    }
                } // inner for
            } else if(temp.matches("[\\s\\w]+")) {
                // ROT13
                int chTemp = (int)temp.charAt(0) + rot13Key;
                if (chTemp > 90){
                    chTemp -= 26;
                    encrypText += (char)chTemp;
                } else {
                    encrypText += (char)chTemp;
                }
            } // if-else
        } // for

        System.out.println("Encrypted Text: " + encrypText);
    }
}
