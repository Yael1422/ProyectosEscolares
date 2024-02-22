from Crypto.Cipher import AES

# Llave de 16 bytes
key = b'000102030405060708090a0b0c0d0e0f'

# Mensaje de 16 bytes
plaintext = b'00112233445566778899aabbccddeeff'

# Crea un objeto AES en modo ECB
cipher = AES.new(key, AES.MODE_ECB)

# Cifra el mensaje
ciphertext = cipher.encrypt(plaintext)
print(f'Mensaje cifrado: {ciphertext}')

# Descifra el mensaje cifrado
deciphered = cipher.decrypt(ciphertext)

# Imprime el mensaje original y el mensaje descifrado
print(f'Mensaje original: {plaintext}')
print(f'Mensaje descifrado: {deciphered}')