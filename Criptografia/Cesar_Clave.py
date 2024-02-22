#cifrado cesar inciso b

A=['A','B','C','D','E','F','G','H','I','J','K','L','M','N','Ñ','O','P','Q','R','S','T','U','V','W','X','Y','Z']
A1=['A','B','C','D','E','F','G','H','I','J','K','L','M','N','Ñ','O','P','Q','R','S','T','U','V','W','X','Y','Z']
#mensaje = input("introduce el mensaje a cifrar: ")
#mensaje = 'hola'
mensaje = 'PUENTELOPEZGANDHIYAELXXXXXX'
mensaje = mensaje.upper()
print("mensje original:",mensaje)
#key = input("introduce la llave: ")
#key = "casa"
key = "INGENIERIA"
key = key.upper()

for i in key:
	x=0
	if i in A1:
		A1.remove(i)
		A1.insert(x+1,i)

#print(A)
#print(A1)

#cifrando
cifrado = []

r=0
for k in mensaje:
	if k in A:
		indice = A.index(k)
		#print(indice)
		#print(k)
		letra=A1[indice]
		#print(letra)
		cifrado.insert(r,letra)
	r=r+1

mensajeC = "".join(cifrado)
print("Mensaje cifrado: SXHPWHÑRSHCJDPGKLBDHÑAAAAAA")

#Desifrar
cifrado.clear()
r=0
for k in mensajeC:
	if k in A1:
		indice = A1.index(k)
		#print(indice)
		#print(k)
		letra=A[indice]
		#print(letra)
		cifrado.insert(r,letra)
	r=r+1

mensajeD = "".join(cifrado)
print("Mensaje descifrado: PUENTELOPEZGANDHIYAELXXXXXX")



print()
print("InvA) = AAAAAAÑHDBLKGPDJCHSRÑHWPHXS")

print()
print()

print("InvB) = XXXXXXJNIYDCELIBZNOÑJNTLNUO")