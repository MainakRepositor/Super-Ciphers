def cipher_encryption():
    print("Message can only be alphabetic")
    message = input("Enter message: ").upper()

    key = 13
    encryp_text = ""

    for i in range(len(message)):
        temp = ord(message[i]) + key
        if ord(message[i]) == 32:
            encryp_text += " "
        elif temp > 90:
            temp -= 26
            encryp_text += chr(temp)
        else:
            encryp_text += chr(temp)
        # if-else
    # for

    print("Encrypted Text: {}".format(encryp_text))


def cipher_decryption():
    print("Message can only be alphabetic")
    message = input("Enter message: ").upper()

    key = 13
    decryp_text = ""

    for i in range(len(message)):
        temp = ord(message[i]) - key
        if ord(message[i]) == 32:
            decryp_text += " "
        elif temp < 65:
            temp += 26
            decryp_text += chr(temp)
        else:
            decryp_text += chr(temp)
            # if-else
    # for

    print("Decrypted Text: {}".format(decryp_text))


def main():
    choice = int(input("1. Encryption\n2. Decryption\nChoose(1,2): "))
    if choice == 1:
        print("---Encryption---")
        cipher_encryption()

    elif choice == 2:
        print("---Decryption---")
        cipher_decryption()

    else:
        print("Invalid Choice")


if __name__ == "__main__":
    main()
