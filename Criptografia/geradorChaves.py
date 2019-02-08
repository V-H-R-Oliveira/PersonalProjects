from random import randint
from math import gcd

def primo(n):
  c = 0
  for x in range(1, n + 1):
    if n % x == 0:
      c += 1
  
  if c == 2:
    return True
    
  return False

def phi(n):
  c = 0
  if primo(n):
    return n - 1
  else:
    for x in range(1, n):
      if gcd(n, x) == 1:
        c += 1
    return c

while True:
  num = randint(2, 10000)
  num2 = randint(2, 10000)
  if primo(num) and primo(num2):
    break

n = num * num2
aux = phi(n)

while True:
  e = randint(2, n)
  if primo(e) and gcd(e, aux) == 1:
    break
  else:
    continue

MMI = lambda A, n,s=1,t=0,N=0: (n < 2 and t%N or MMI(n, A%n, t, s-A//n*t, N or n),-1)[n<1] # inverso multiplicativo modular

possivel = MMI(e, aux)

if n % possivel > 0:
  print("Chave pública: ({},{})".format(n, e))
  print("Chave privada: ({},{})".format(n, possivel))