import textwrap
#Permutacion cifrado 4213
#Permutacion decifrado 3240
def permutacion(cif2,a,b,c,d):
  aux2=[]
  perm=[]
  for i in range(0, len(cif2)):
    perm=cif2[i]
    if i%2==0:
      aux2.append("".join([perm[a],perm[b],perm[c],perm[d]]))
    else:
      aux2.append(perm)
    perm=""
  print(aux2)
  return aux2
  
def cambio(cif2):
  aux=[]
  camb=[]
  for i in range(0, len(cif2)):
    if i%2==0:
      camb=cif2[i]
    else:
      aux.append(cif2[i])
      aux.append(camb)
      camb=""
  print(aux)
  return aux

def Cifrado(mensaje,rep,ron):
  x=textwrap.wrap(mensaje,width=8)
  print(x)
  print()
  ron = ron+1
  print(f"Ronda: {ron}")
  c1="".join(x)
  
#Hacemos el Ci=(Mi + 1) mod n
  if rep!=0:
    c11=""
    cuenta=0
    apr=0
    for i in c1:
      if i in abc:
        pos_letra = abc.index(i)
        
# Sumamos para movernos a la derecha del abc
        nueva_pos = ((pos_letra) + 1) % len(abc)
        if apr==0:
          c11+= abc[nueva_pos]
        else:
          c11+= abc[pos_letra]
      cuenta+=1
      if cuenta%4==0:
        if apr==0:
          apr=1
        else:
          apr=0
    cif="".join(c11)
    
#Convertimos a un subgrupo de 4 caracteres para la permutacion
    cif2=textwrap.wrap(cif,width=4)
    print(cif2)
    nuevocif2=permutacion(cif2,1,2,0,3)
    nuevocif2=cambio(nuevocif2)
    nuevocif2=Cifrado("".join(nuevocif2),rep-1,ron)
  else:
    nuevocif2=c1
  return nuevocif2
  
#Decifrado
def Decifrado(mensaje,rep,ron):
    
  ron = ron+1
  print(f"Ronda: {ron}")
    
    
  if rep!=0:
    mensaje=textwrap.wrap(mensaje,width=4)
    print(mensaje)
    mensaje=cambio(mensaje)
    mensaje=permutacion(mensaje,1,2,0,3)
    c1="".join(mensaje)
    c11=""
    cuenta=0
    apr=0
    for i in c1:
      if i in abc:
        pos_letra = abc.index(i)
        
# Sumamos para movernos a la derecha del abc
        nueva_pos = ((pos_letra) - 1) % len(abc)
        if apr==0:
          c11+= abc[nueva_pos]
        else:
          c11+= abc[pos_letra]
      cuenta+=1
      if cuenta%4==0:
        if apr==0:
          apr=1
        else:
          apr=0
    print(c11)
    print()
    nuevocif2=Decifrado("".join(c11),rep-1,ron)
  else:
    nuevocif2=mensaje
    print("Mensaje Descifrado", nuevocif2)
  return nuevocif2

    
abc = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ"
aux = []

#Ingresamos mensaje a cifrar
mensaje=input("Ingrese el mensaje a cifrar: ").upper()

#Verificamos que la longitud del mensaje sea de longitud = 8
if len(mensaje)%8!=0:
  x=8-len(mensaje)%8
  for i in range(0, x):
    aux.append('X')
  mensaje=mensaje + "".join(aux)
  
print(mensaje)
ron = -1
mensajeCif="".join(Cifrado(mensaje,16,ron))
print (f"Mensaje cifrado: {mensajeCif}")
print()
print(f"Decifrando el mensaje: {mensajeCif}")
mensajeDecif=Decifrado(mensajeCif,16,ron)