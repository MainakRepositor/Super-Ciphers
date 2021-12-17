import java.util.Scanner;

public class ROT5 {

    private static Scanner in;
    public static void main(String[] args){
        in = new Scanner(System.in);

        System.out.println("1. Encryption\n2. Decryption\nChoose(1,2): ");
        int choice = in.nextInt();
        in.nextLine();

        String rot5 = "5678901234";
        String zeroToNine = "0123456789";

        if(choice == 1){
            System.out.println("---Encryption---");
            cipherEncryption(rot5, zeroToNine);
        } else if (choice == 2){
            System.out.println("---Decryption---");
            cipherDecryption(rot5, zeroToNine);
        } else {
            System.out.println("Incorrect Choice");
        }
    }

    private static void cipherDecryption(String rot5, String zeroToNine) {
        System.out.println("Message can only be positive integers");
        System.out.print("Enter message: ");
        String message = in.nextLine();
        in.nextLine();

        //checking if input is integer or not
        // we'll be using regular expressions
        if(!message.matches("[\\s\\d]+")){
            // \\d = integers
            // \\s = white space
            // [] a set, with logical OR
            // + = one or more times
            System.out.println("Entered Message is not an integer");
            System.exit(0);
        }

        //encryption
        String decrypText = "";
        for (int i = 0; i < message.length(); i++) {
            if(message.charAt(i) == 32){
                decrypText += " ";
            } else {
                for (int j = 0; j < zeroToNine.length(); j++) {
                    //simple substitution
                    if(message.charAt(i) == rot5.charAt(j)){
                        decrypText += zeroToNine.charAt(j);
                    }
                } // inner for
            } // if else
        } // for

        System.out.println("Decrypted Text: " + decrypText);
    }

    private static void cipherEncryption(String rot5, String zeroToNine) {
        System.out.println("Message can only be positive integers");
        System.out.print("Enter message: ");
        String message = in.nextLine();
        in.nextLine();

        //checking if input is integer or not
        // we'll be using regular expressions
        if(!message.matches("[\\s\\d]+")){
            // \\d = integers
            // \\s = white space
            // [] a set, with logical OR
            // + = one or more times
            System.out.println("Entered Message is not an integer");
            System.exit(0);
        }

        //encryption
        String encrypText = "";
        for (int i = 0; i < message.length(); i++) {
            if(message.charAt(i) == 32){
                encrypText += " ";
            } else {
                for (int j = 0; j < zeroToNine.length(); j++) {
                    //simple substitution
                    if(message.charAt(i) == zeroToNine.charAt(j)){
                        encrypText += rot5.charAt(j);
                    }
                } // inner for
            } // if else
        } // for

        System.out.println("Encrypted Text: " + encrypText);

    }

}
