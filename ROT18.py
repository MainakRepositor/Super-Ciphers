import re
def cipher_encryption():
    rot5 = "5678901234"
    zeroToNine = "0123456789"
    rot_13_key = 13

    print("Message can be alphanumeric")
    message = input("Enter message: ").upper()

    encryp_text = "";
    for i in range(len(message)):
        temp = message[i] + ""
        if ord(message[i]) == 32:
            encryp_text += " "
        elif re.search('[\d\s]+', temp):
            # ROT5
            for j in range(len(zeroToNine)):
                if message[i] == zeroToNine[j]:
                    encryp_text += rot5[j]
            # inner for
        elif re.search('[\w\s]+', temp):
            # ROT13
            ch_temp = ord(message[i]) + rot_13_key
            if ord(message[i]) == 32:
                encryp_text += " "
            elif ch_temp > 90:
                ch_temp -= 26
                encryp_text += chr(ch_temp)
            else:
                encryp_text += chr(ch_temp)
        # if-else
    # for

    print("Encrypted Text: {}".format(encryp_text))


def cipher_decryption():
    rot5 = "5678901234"
    zeroToNine = "0123456789"
    rot_13_key = 13

    print("Message can be alphanumeric")
    message = input("Enter message: ").upper()

    decryp_text = "";
    for i in range(len(message)):
        temp = message[i] + ""
        if ord(message[i]) == 32:
            decryp_text += " "
        elif re.search('[\d\s]+', temp):
            # ROT5
            for j in range(len(zeroToNine)):
                if message[i] == rot5[j]:
                    decryp_text += zeroToNine[j]
                    # inner for
        elif re.search('[\w\s]+', temp):
            # ROT13
            ch_temp = ord(message[i]) - rot_13_key
            if ord(message[i]) == 32:
                decryp_text += " "
            elif ch_temp < 65:
                ch_temp += 26
                decryp_text += chr(ch_temp)
            else:
                decryp_text += chr(ch_temp)
                # if-else
    # for

    print("Decrypted Text: {}".format(decryp_text))


def main():
    choice = int(input("1. Encryption\n2. Decryption\nChoose (1,2): "))
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
