# Cryptography
# Affin
from invermod import invmod

def AffinEncrypt(mess):
    print("Encrypting...")
    index_crypted = []
    encrypted_message = []
    response = invmod(a,m)
    if(response != -1):
        # contine
        for i in range(0,len(mess)):
            for j in range(0,len(universe)):
                if(universe[j] == mess[i]):
                    index = (a*j + 7) % m # E(x) = (a * M + b) mod m
                    index_crypted.append(index)
        
        for i in range(0,len(index_crypted)):
            for j in range(0,len(universe)):
                if(index_crypted[i] == j):
                    encrypted_message.append(universe[j])
        print("Input message: ",mess)
        print("Encrypted message: ",encrypted_message,"\n")
        return encrypted_message
    else:
        print(a," don't have modular multiplicatve inverse of ",m)

def AffinUncrypt(mess):
    print("Uncrypting...")
    index_uncryp = []
    uncrypted_message = []
    inverse = invmod(a,m)
    for i in range(0,len(mess)):
        for j in range(0,len(universe)):
            if(mess[i] == universe[j]):
                index = (inverse*(j-b) % m)
                index_uncryp.append(index)
    for i in range(0,len(index_uncryp)):
        for j in range(0,len(universe)):
            if(index_uncryp[i] == j):
                uncrypted_message.append(universe[j])
    print("Encrypted message: ",mess)
    print("Uncrypted message: ",uncrypted_message,"\n")
    return uncrypted_message



universe = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','Ñ','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9']
message = ['P','O','R','M','I','R','A','Z','A','H','A','B','L','A','R','A','E','L','E','S','P','I','R','I','T','U']
a = 1 
b = 7
m = len(universe)
u=AffinEncrypt(message)
AffinUncrypt(u)
