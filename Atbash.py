def at_encryption():
    alpa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    # reversing alphabets of alpa variable
    rev_alpa = alpa[::-1]

    message = input("Enter message: ").upper();

    encry_text = ""

    for i in range(len(message)):
        if message[i] == chr(32):
            encry_text += " "
        else:
            for j in range(len(alpa)):
                if message[i] == alpa[j]:
                    encry_text += rev_alpa[j]
                    break
                # if
            # inner for
        # if-else
    # for

    print("Encrypted Text: {}".format(encry_text))


def at_decryption():
    alpa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    # reversing alphabets of alpa variable
    rev_alpa = alpa[::-1]

    message = input("Enter message: ").upper();

    dencry_text = ""

    for i in range(len(message)):
        if message[i] == chr(32):
            dencry_text += " "
        else:
            for j in range(len(rev_alpa)):
                if message[i] == rev_alpa[j]:
                    dencry_text += alpa[j]
                    break
                    # if
                    # inner for
                    # if-else
    # for

    print("Decrypted Text: {}".format(dencry_text))


def main():
    choice = int(input("1. Encryption\n2.Decryption\nChoose(1,2): "))
    if choice == 1:
        print("---Encryption---")
        at_encryption()
    elif choice == 2:
        print("---Decryption---")
        at_decryption()
    else:
        print("Wrong Choice")


if __name__ == "__main__":
    main()
