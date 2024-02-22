% Faculty of Engineering
% Cryptography
% Hill Cipher
% Wrote by: ellipsiis (Daniel Al. Zarco Manzanares)
key = 'KILOWATTS'; % Declaring the key
message = 'HOLAMUNDO'; % Declaring the message
disp('El mensaje es: ');
disp(message);
fprintf('\n');
disp('La llave es: ');
disp(key);
fprintf('\n');
keynum = double(key)-65;
K = reshape(keynum,3,[]).';
key1 = double(key);
key2 = reshape(key1,3,[]);
disp('La llave en matriz es: ');
disp(char(key2.'));
fprintf('\n');
messagenum = double(message)-65;
mess1 = double(message);
mess2 = reshape(mess1,3,[]);
disp('El mensaje en la matriz es: ');
disp(char(mess2.'));
fprintf('\n');
M = reshape(messagenum,3,[]).';
detK = double(det(K));
disp('El determinante de K es: ');
disp(detK);
fprintf('\n');
adjK = adjoint(K);
% Calculating inverse modular multiplicative
[G,C,~] = gcd(single(detK),27);
if G==1
    ModMultInv = mod(C,27);
else
    disp('Error');
end
% -----
invK = mod(adjK*ModMultInv,27);
disp('La matriz inversa de K es: ');
disp(invK);
fprintf('\n');
C = mod(K*M,27); %Matrix of Cryptograms
disp('La matriz de criptogramas es: ');
disp(C);
fprintf('\n');
C2 = char(C+65); %Matrix of Cryptograms in char
% Uncrypt
Mu = mod(invK*C,27);
Muf = char(Mu+65);
disp('El mensaje desencriptado es: ');
disp(Muf);
fprintf('\n');



