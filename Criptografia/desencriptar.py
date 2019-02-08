lista, final, finalN = [], [], []
qtd = int(input("Digite a quantidade de valores que deseja desencriptar: "))
n, q = input("Digite os valores da chave privada: ").split()
n, q, total = int(n), int(q), 0

for x in range(1, qtd + 1):
  x = int(input("Digite o número que deseja desencriptar: "))
  total = (x**q) % n
  finalN.append(total)
  final.append(chr(total))

print("Array com os caracteres finais:", final)
print("Array com os números desencriptados:", finalN)