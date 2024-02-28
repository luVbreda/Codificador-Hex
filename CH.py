def codificador_hex(caracter):
    cod1 = ord(caracter)//16
    if (cod1 > 9):
        cod1 += 55
    else:
        cod1 += 48
    
    cod2 = ord(caracter)%16
    if(cod2 > 9):
        cod2 += 55
    else:
        cod2 += 48

    return chr(cod1) + chr(cod2)

def decodifica_hex(caracter1, caracter2):
    if (caracter1 >= 'A'):
        caracter1 = ord(caracter1) - 55
    else:
        caracter1 = ord(caracter1) - 48
    
    if (caracter2 >= 'A'):
        caracter2 = ord(caracter2) - 55
    else:
        caracter2 = ord(caracter2) - 48

    return chr(caracter1*16+caracter2)

print('-_-_-_-  Codificador Hexadecimal (Python)  -_-_-_-')

cripto = ''
print('(1) Codificar\n(2) Decodificar')
while (cripto != '1' and cripto !='2'):
    print('->', end='')
    cripto = input()

print('Texto: ', end='')
texto = input()

cifra = ''

match (cripto):
    case '1':
        for i in range (len(texto)):
            cifra += codificador_hex(texto[i])
    
    case '2':
        for i in range (0, len(texto), 2):
            cifra += decodifica_hex(texto[i], texto[i+1])

print(cifra)