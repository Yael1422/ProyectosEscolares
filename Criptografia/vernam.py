from operator import xor

message = ['F','e','r','n','a','n','d','o','C','a','s','a','S','o','l','a']
key = ['S','a','n','t','i','a','g','o','S','a','n','t','i','a','g','o']

def vernamEncrypt(mess, key):
    encryptedMessage = []
    binMess = []
    binKey=[]
    binEnc = []
    for elem in mess:
        binMess.append(bin(ord(elem)))
    for elem in key:
        binKey.append(bin(ord(elem)))
    for elem in range(0,len(mess)):
        binEnc.append(bin(xor(int(binMess[elem],2),int(binKey[elem],2))))
    for elem in binEnc:
        encryptedMessage.append(chr(int(elem,2)))
    print("Encrypting...","\n")
    print("Input message: ", mess)
    print("Input key: ",key)
    print("Binary encrypted: ",binEnc)
    print("Encrypted message: ",encryptedMessage,"\n")
    return encryptedMessage

def vernamUncrypt(mess, key):
    uncryptedMessage = []
    binMess = []
    binKey = []
    binUnc = []
    for elem in mess:
        binMess.append(bin(ord(elem)))
    for elem in key:
        binKey.append(bin(ord(elem)))
    for elem in range(0,len(mess)):
        binUnc.append(bin(xor(int(binMess[elem],2),int(binKey[elem],2))))
    for elem in binUnc:
        uncryptedMessage.append(chr(int(elem,2)))

    print("Uncrypting... ","\n")
    print("Input message: ",mess)
    print("Input Key: ",key)
    print("Binary uncrypted: ",binUnc)
    print("Uncrypted message: ",uncryptedMessage,"\n")
    return uncryptedMessage

e=vernamEncrypt(message,key)
u=vernamUncrypt(e,key)
