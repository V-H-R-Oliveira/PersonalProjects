from random import randint

empty_cel = '-'
full_cell= 9
move = 0

def display_board(t):
    print(' 0 1 2')
    for row in range(3):
        print(row, end=' ')
        for col in range(3):
            print(t[row][col], end=' ')
        print()

tabuleiro = [[empty_cel, empty_cel, empty_cel], [empty_cel, empty_cel, empty_cel], [empty_cel, empty_cel, empty_cel]]

def player():
    while True:
        r = int(input('Digite uma linha: '))
        c = int(input('Digite uma coluna: '))
        if tabuleiro[r][c] != empty_cel:
            print('Digite outra combinação.')
            continue
        else:
            tabuleiro[r][c] = 'X'
            print('Sua jogada:')
            display_board(tabuleiro)
            break

def adversario():
    while True:
        r = int(input('Digite uma linha: '))
        c = int(input('Digite uma coluna: '))
        if tabuleiro[r][c] != empty_cel:
            print('Digite outra combinação.')
            continue
        else:
            tabuleiro[r][c] = '0'
            print('Sua jogada:')
            display_board(tabuleiro)
            break

def computer():
    while True:
        r = randint(0, 2)
        c = randint(0, 2)
        if tabuleiro[r][c] != empty_cel:
            print('Célula cheia.')
            continue
        else:
            tabuleiro[r][c] = 'C'
            print('Jogada do computador:')
            display_board(tabuleiro)
            break

def winner(tab):
    for row in range(3):
        if tab[row][0] != empty_cel and tab[row][0] == tab[row][1] and tab[row][0] == tab[row][2]:
            return True
    for col in range(3):
        if tab[0][col] != empty_cel and tab[0][col] == tab[1][col] and tab[0][col] == tab[2][col]:
            return True
    if tab[1][1] != empty_cel:
        if tab[1][1] == tab[0][0] and tab[1][1] == tab[2][2]:
            return True
        if tab[1][1] == tab[0][2] and tab[1][1] == tab[2][0]:
            return True
    return False

display_board(tabuleiro)

while True:
    op = int(input('Digite 1 para jogar multiplayer ou 2 para jogar sozinho: '))

    while op == 1:
        escolha = str(input('Digite sua escolha, X ou O: ')).upper()
        if escolha == 'X':
            player()
            move += 1
            if winner(tabuleiro):
                print('O jogador do X venceu a partida.')
                break
        elif escolha == 'O':
            adversario()
            move += 1
            if winner(tabuleiro):
                print('O jogador do O venceu a partida.')
                break
        if move == full_cell:
            print('Partida resultou em um empate.')
            break

    while op == 2:
        player()
        move += 1
        if winner(tabuleiro):
            print('Você venceu a partida.')
            break
        computer()
        move += 1
        if winner(tabuleiro):
            print('O Computador venceu a partida.')
            break
        if move == full_cell :
            print('Partida resultou em um empate.')
            break
    break
