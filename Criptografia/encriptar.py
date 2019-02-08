def codificar(array):
  n, q = input("Digite a sua chave pública: ").split()
  n, q = int(n), int(q)
  lista_n, lista_c = [], []
  
  for x in array:
    total = x ** q % n
    lista_n.append(total)
    lista_c.append(chr(total))
  
  print('Lista de caracteres encodificados:', lista_c)
  print("Lista dos números encodificados:", lista_n)
  print(len(lista_n))
  
string = input("Digite a string a ser codificada: ")
lista, lista2 = [], []
lista.extend(string)

for x in lista:
  lista2.append(ord(x))

print("Números a serem encodificados:", lista2)
codificar(lista2)