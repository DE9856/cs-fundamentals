str1 = input("Enter the string: ")
chars = [ord(char) for char in str1]

for i in range(len(chars)):
    ch = chr(chars[i])
    if ch.isalpha():
        if ch.isupper():
            ch = chr((ord(ch) - ord('A')+3)%26 +ord('A'))
        else:
            ch = chr((ord(ch)-ord('a')+3)%26 + ord('a'))
    chars[i] = ch

print(*chars,sep = "")
