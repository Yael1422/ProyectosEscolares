#cifrado cesar inciso a

#mensaje = input("introduce el mensaje a cifrar: ")
mensaje = 'hola'
mensaje = mensaje.lower()
#llave = int(input("ingresa un numero entero positivo: "))
llave = 3

MensajeTransformado = []
cifrado = []
C=[]

desifrando=[]
desifrado=[]
D=[]


#obteniendo mensaje en asccii
for i in mensaje:
	MensajeTransformado.append(ord(i))

#print(MensajeTransformado)

#cifrando desde asccii
for j in MensajeTransformado:
	cifrado.append(j+llave)

#print(cifrado)
#lista de nuevos caracteres mensaje cifrado
for k in cifrado:
	C.append(chr(k))


print(MensajeTransformado,"\n",cifrado,"\n",C)

#desifrar

for x in C:
	desifrando.append(ord(x))

print("\n",desifrando)

for y in desifrando:
	desifrado.append(y-llave)

print(desifrado)

for z in desifrado:
	D.append(chr(z))

print(D)