import java.util.Scanner;

public class ROT47 {
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
            System.out.println("---Decryption---");
            cipherDecryption();

        } else {
            System.out.println("Invalid Choice");
        }
    }

    private static void cipherDecryption() {
        System.out.println("Enter message: ");
        String message = in.nextLine();
        in.nextLine();

        int key = 47;
        String decrypText = "";
        for (int i = 0; i < message.length(); i++) {
            int temp = (int)message.charAt(i) - key;
            if((int)message.charAt(i) == 32){
                decrypText += " ";
            } else if(temp < 32){
                temp += 94;
                decrypText += (char)temp;
            } else {
                decrypText += (char)temp;
            } // if-else
        } // for

        System.out.println("Decrypted Text: " + decrypText);
    }

    private static void cipherEncryption() {
        System.out.println("Enter message: ");
        String message = in.nextLine();
        in.nextLine();

        int key = 47;
        String encrypText = "";
        for (int i = 0; i < message.length(); i++) {
            int temp = (int)message.charAt(i) + key;
            if((int)message.charAt(i) == 32){
                encrypText += " ";
            } else if(temp > 126){
                temp -= 94;
                encrypText += (char)temp;
            } else {
                encrypText += (char)temp;
            } // if-else
        } // for

        System.out.println("Encrypted Text: " + encrypText);
    }
}
