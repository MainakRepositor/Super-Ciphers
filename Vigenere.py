def msg_and_key():
    msg = input("Enter message: ").upper()
    key = input("Enter key: ").upper()

    # variable to store mapped key
    key_map = ""

    j=0
    for i in range(len(msg)):
        if ord(msg[i]) == 32:
            # ignoring space
            key_map += " "
        else:
            if j < len(key):
                key_map += key[j]
                j += 1
            else:
                j = 0
                key_map += key[j]
                j += 1

    # print(key_map)
    return msg, key_map


def create_vigenere_table():
    table = []
    for i in range(26):
        table.append([])

    for row in range(26):
        for column in range(26):
            if (row + 65) + column > 90:
                # moving back to A after Z
                # after first row, each letter will shift left by one position compared to row above it
                table[row].append(chr((row+65) + column - 26))
            else:
                # after first row, each letter will shift left by one position compared to row above it
                table[row].append(chr((row+65)+column))

    # printing the table
    # for row in table:
    #     for column in row:
    #         print(column, end=" ")
    #     print(end="\n")

    return table


def cipher_encryption(message, mapped_key):
    table = create_vigenere_table()
    encrypted_text = ""

    for i in range(len(message)):
        if message[i] == chr(32):
            # ignoring space
            encrypted_text += " "
        else:
            # getting element at specific index of table
            row = ord(message[i])-65
            column = ord(mapped_key[i]) - 65
            encrypted_text += table[row][column]

    print("Encrypted Message: {}".format(encrypted_text))


def itr_count(mapped_key, message):
    counter = 0
    result = ""

    # starting alphabets from mapped_key letter and finishing all 26 letters from it, (after z we move to a)
    for i in range(26):
        if mapped_key + i > 90:
            result += chr(mapped_key+(i-26))
        else:
            result += chr(mapped_key+i)

    # counting the number of iterations it take from mapped key letter to ciphertext letter
    for i in range(len(result)):
        if result[i] == chr(message):
            break
        else:
            counter += 1

    return counter


def cipher_decryption(message, mapped_key):
    table = create_vigenere_table()
    decrypted_text = ""

    for i in range(len(message)):
        if message[i] == chr(32):
            # ignoring space
            decrypted_text += " "
        else:
            # adding number of iterations, it takes to reach from mapped key letter to cipher letter in 65
            # by doing so we get column header of ciphertext letter, which happens to be decrypted letter
            decrypted_text += chr(65 + itr_count(ord(mapped_key[i]), ord(message[i])))

    print("Decrypted Message: {}".format(decrypted_text))


def main():
    print("Key and Message can only be alphabetic")
    choice = int(input("1. Encryption\n2. Decryption\nChoose(1,2): "))
    if choice == 1:
        print("---Encryption---")
        message, mapped_key = msg_and_key()
        cipher_encryption(message, mapped_key)

    elif choice == 2:
        print("---Decryption---")
        message, mapped_key = msg_and_key()
        cipher_decryption(message, mapped_key)

    else:
        print("Wrong choice")


if __name__ == "__main__":
    main()
