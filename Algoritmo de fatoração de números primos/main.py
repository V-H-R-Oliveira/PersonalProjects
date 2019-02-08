from math import floor, sqrt

def crivo(maxRange):
    max_prime, min_prime = floor(sqrt(maxRange)), 2
    lista = list(x for x in range(min_prime, maxRange + 1))

    for x in range(min_prime, max_prime + 1):
        for i in lista:
            if i % x == 0 and i != x:
                lista.remove(i)

    return lista

def fatoracao(n):
    primeList, multArray, aux = crivo(n), [], 0

    if n in primeList:
        return n

    while n > 1:
        div = primeList[aux]

        if n % div == 0:
            multArray.append(div)
            n //= div

        if n % div == 0:
            pass
        else:
            aux += 1
    return multArray

while True:
    try:
        n, string = int(input("Digite um número para ser fatorado, ou aperte enter para sair do programa: ")), ""

        resultado = fatoracao(n)

        if n == 0 or n == 1:
            print("O número {} não pode ser fatorado".format(n))
        elif isinstance(resultado, int):
            print("O número {} é primo".format(n))
        else:
            for i in resultado:
                string += (str(i) + " * ")
            string = string.strip()
            string = string[:len(string) - 1]
            string = string.strip()
            print("A fatoração do número {}, resulta no seguinte produto de números primos:".format(n), string)
    except(EOFError, TypeError, ValueError):
        break
