# Carry entre a soma de dois números
# Carry = 1 | 1 = 0 carry = 1

while True:
    try:
        a, b = input("").split(' ')
        a, b = int(a), int(b)
        print((a ^ b)|(b ^ a))
    except (EOFError, ValueError):
        break
