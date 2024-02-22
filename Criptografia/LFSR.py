# School of Engineering
# Cryptography
# Linear Feedback Shift Register
# Wrote by: ellipsiis (Daniel Zarco)
import numpy as np

def lfsr(seed):
    s_array = seed
    si = [] # declare the array for store the cipher serie
    T_max = (pow(2,(len(s_array)))-1) #gets maximum period for 
    print("Periodo Máximo: ",T_max)
    for i in range (0,T_max):
        si.append(s_array[-1])
        xi = s_array[5]^s_array[3]
        tmp = np.roll(s_array,1)
        s_array = tmp
        s_array[0] = xi
    print("Secuencia cifrante: ",si)
    return si

   

def main(): 
    #some code to execute main
    init = [1,0,1,1,1,1]
    a=lfsr(init)
    

if __name__ == '__main__': #execute main
        main()
