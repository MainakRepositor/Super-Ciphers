import java.util.Scanner;

public class ROT13 {

    private static Scanner in;
    public static void main(String[] args){
        in = new Scanner(System.in);
        System.out.println("1. Encryption\n2. Decryption\nChoose(1,2): ");
        int choice = in.nextInt();
        in.nextLine();

        if(choice == 1){
            System.out.println("---Encryption---");
            cipherEncryption();
        } else if(choice == 2){
            System.out.println("---Decryption---");
            cipherDecryption();

        } else {
            System.out.println("Incorrect Choice");
        }
    }

    private static void cipherDecryption() {
        System.out.println("Message can only be alphabetic");
        System.out.print("Enter Message: ");
        String message = in.nextLine();
        in.nextLine();
        message = message.toUpperCase();

        int key = 13;
        String decrypText = "";
        for (int i = 0; i < message.length(); i++) {
            int temp = (int)message.charAt(i) - key;
            if((int)message.charAt(i) == 32){
                decrypText += " ";
            } else if(temp < 65){
                temp += 26;
                decrypText += (char)temp;
            } else {
                decrypText += (char)temp;
            }
        }

        System.out.println("Decrypted Message: " + decrypText);
    }

    private static void cipherEncryption() {
        System.out.println("Message can only be alphabetic");
        System.out.print("Enter Message: ");
        String message = in.nextLine();
        in.nextLine();
        message = message.toUpperCase();

        int key = 13;
        String encrypText = "";
        for (int i = 0; i < message.length(); i++) {
            int temp = (int)message.charAt(i) + key;
            if((int)message.charAt(i) == 32){
                encrypText += " ";
            } else if(temp > 90){
                temp -= 26;
                encrypText += (char)temp;
            } else {
                encrypText += (char)temp;
            }
        }

        System.out.println("Encrypted Message: " + encrypText);
    }

}
