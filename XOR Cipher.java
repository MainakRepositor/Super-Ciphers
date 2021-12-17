import java.util.Scanner;

public class XORCipher {
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
        System.out.print("Enter message: ");
        String msg = in.nextLine();

        System.out.print("Enter key: ");
        String key = in.nextLine();

        String hexToDeci = "";
        for (int i = 0; i < msg.length()-1; i+=2) {
            // splitting hex into a pair of two
            String output = msg.substring(i, (i+2));
            int decimal = Integer.parseInt(output, 16);
            hexToDeci += (char)decimal;
        }

        // decryption
        String decrypText = "";
        int keyItr = 0;
        for (int i = 0; i < hexToDeci.length(); i++) {
            // XOR Operation
            int temp = hexToDeci.charAt(i) ^ key.charAt(keyItr);

            decrypText += (char)temp;
            keyItr++;
            if(keyItr >= key.length()){
                // once all of key's letters are used, repeat the key
                keyItr = 0;
            }

        }

        System.out.println("Decrypted Text: " + decrypText);
    }

    private static void cipherEncryption() {
        System.out.print("Enter message: ");
        String msg = in.nextLine();

        System.out.print("Enter key: ");
        String key = in.nextLine();

        String encrypHexa = "";
        int keyItr = 0;
        for (int i = 0; i < msg.length(); i++) {
            // XOR Operation
            int temp = msg.charAt(i) ^ key.charAt(keyItr);

            encrypHexa += String.format("%02x", (byte)temp);
            keyItr++;
            if(keyItr >= key.length()){
                // once all of key's letters are used, repeat the key
                keyItr = 0;
            }

        }

        System.out.println("Encrypted Text: " + encrypHexa);
    }
}
