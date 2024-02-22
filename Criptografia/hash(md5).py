import hashlib

# Abre los archivos
file1 = open("MD5Audio.mp3", "rb")
file2 = open("MD5Foto.png", "rb")

# Crea un objeto hash MD5
md5 = hashlib.md5()

# Lee los datos del primer archivo y actualiza el objeto hash
data = file1.read()
md5.update(data)
hash1 = md5.hexdigest()
print("MD5 del archivo 1 (audio)"+md5.hexdigest())

# Reinicia el objeto hash
md5 = hashlib.md5()

# Lee los datos del segundo archivo y actualiza el objeto hash
data = file2.read()
md5.update(data)
hash2 = md5.hexdigest()
print("MD5 del archivo 2 (foto)"+md5.hexdigest())

# Compara los hashes
if hash1 == hash2:
    print("Los archivos son iguales")
else:
    print("Los archivos son diferentes")


# Cierra los archivos
file1.close()
file2.close()
