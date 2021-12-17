import java.util.Scanner;

public class CaesarCipher {
    //we'll be using ASCII in this
    public static void main(String[] args){
        System.out.print("1. Encryption\n2. Decryption\nChoose(1,2): ");
        Scanner in = new Scanner(System.in);
        int choice = in.nextInt();

        if (choice == 1){
            System.out.println("Encryption");
            in.nextLine(); //to pass empty line to scanner to avoid erros

            System.out.println("Message can only be lower or uppercase alphabet");
            System.out.print("Enter Message: ");
            String msg = in.nextLine();

            System.out.print("Enter key (0-25): ");  //26 being length of alphabet
            int key = in.nextInt();

            String encrypMsg = "";

            for (int i = 0; i < msg.length(); i++) {
                // again casting
                if ((int)msg.charAt(i) == 32){
                    encrypMsg += (char)32; // ignoring space, casting int to char

                } else if ((int)msg.charAt(i) + key > 122){
                    int temp = ((int)msg.charAt(i) + key) - 122;
                    encrypMsg += (char)(96 + temp);

                } else if ((int)msg.charAt(i) + key > 90 && (int)msg.charAt(i) < 96){
                    int temp = ((int)msg.charAt(i) + key) - 90;
                    encrypMsg += (char)(64+temp);

                } else {
                    encrypMsg += (char)((int)msg.charAt(i) + key);

                }
            } // for loop

            System.out.println(encrypMsg);
        } else if (choice == 2){
            System.out.println("Decryption");
            in.nextLine();

            System.out.println("Message can only be upper or lowercase alphabet");
            System.out.print("Enter encrypted Text: ");
            String encypText = in.nextLine();

            System.out.println("Enter key (0-25): ");
            int dcyptkey = in.nextInt();

            String decrypMsg = "";

            for (int i = 0; i < encypText.length(); i++) {
                // now type casting
                if((int)encypText.charAt(i) == 32){
                    decrypMsg += (char)32;
                } else if (((int)encypText.charAt(i) - dcyptkey) < 97 && ((int)encypText.charAt(i) - dcyptkey) > 90) {
                    //lower case
                    int temp = ((int)encypText.charAt(i) - dcyptkey) + 26;
                    decrypMsg += (char)temp;
                } else if ((encypText.charAt(i) - dcyptkey) < 65) {
                    // upper case
                    int temp = ((int)encypText.charAt(i) - dcyptkey) + 26;
                    decrypMsg += (char)temp;
                } else {
                    decrypMsg += (char)((int)encypText.charAt(i) - dcyptkey);
                }

            } // for loop

            System.out.println(decrypMsg);

        } else {
            System.out.println("Wrong Choice");
        }
    }
}
