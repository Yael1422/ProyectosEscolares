universe = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','Ñ','O','P','Q','R','S','T','U','V','W','X','Y','Z']
newUniverse =[]
key = ['I','N','G','E','N','I','E','R','I','A']
message=['P','U','E','N','T','E','L','O','P','E','Z','G','A','N','D','H','I','Y','A','E','L','X','X','X','X','X','X']

def makeUniverse(key):

    for i in range(0,len(key)):
        newUniverse.append(key[i]); # Adding all elements of key list
    for j in range(0,len(universe)):
        newUniverse.append(universe[j]) # Adding all elements of universe list
    new = list(dict.fromkeys(newUniverse)) # Clean repeat elements of tmp converting it into dictonary and return it as list
    return new # Returning the new universe


def caesarKey(mess,keyy):
    nuevo = makeUniverse(keyy) # generating the universe crypt message
    print("Nuevo Universo\n", nuevo, "\n")
    
    print("Encriptado")
    encrypted_message=[] # Temporary list to append the encypted message
    for i in range(0,len(mess)): # Frist for to travel along the input message
        for j in range(0,len(nuevo)): # Anidade for to travel along of universe 
            if(mess[i] == nuevo[j]): # Verifying if the element of input is the same of any element of universe
                encrypted_message.append(universe[j]) # Appending  encrypted element
    print("Key: ",keyy)
    print("Message: ",mess)
    print("Encypted message: ",encrypted_message,"\n")
    return encrypted_message
    #else:
        #print("The size of message and key are not same")            

def uncryptCaesar(mess,keyy):
    nuevo = makeUniverse(keyy) # generating universe to uncrypt message
    
    print("Descifrado")
    uncrypted_message = [] # Temporary list to append the uncrypted message
    for i in range(0,len(mess)): # First for to travel along of input
        for j in range(0,len(nuevo)): # Anidade for to travel along universe
            if(mess[i] == universe[j]): # Verifying if the input element is equals to universe element    
                uncrypted_message.append(nuevo[j]) # Appending uncrypted element 
    print("Key: ",keyy)
    print("Encrypted message: ",mess)
    print("Uncrypted Message: ",uncrypted_message,"\n")
    return uncrypted_message


e=caesarKey(message,key)
u=uncryptCaesar(e,key)






    