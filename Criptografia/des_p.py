from Crypto.Cipher import DES

def pad(text):
    n = len(text) % 8
    return text + (b' ' * n)


key = b'PUENTEXX'
text1 = b'Yael'

des = DES.new(key, DES.MODE_ECB)

padded_text = pad(text1)
encrypted_text = des.encrypt(padded_text)



print(encrypted_text)
print(des.decrypt(encrypted_text))
