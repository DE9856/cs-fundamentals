import random
b = [[' ']*3 for _  in range(3)]

def show():
    for r in b:
        print('|'.join(r))
    print()

def win(p):
    return any(all(b[i][j]==p for j in range(3)) for i in range(3)) or \
            any(all(b[i][j]==p for i in range(3)) for j in range(3)) or \
            all(b[i][i] == p for i in range(3)) or all(b[i][2-i]==p for i in range(3))

while True:
    show()
    try:
        r,c = map(int, input("Enter row col (0-2): ").split())
        if not(0<=r<3 and 0<=c<3):
            print("Out of range")
            continue
        if b[r][c]!= ' ':
            print("Cell Taken! Try again")
            continue
    except:
        print("Invalid input")
        continue
    
    b[r][c] = 'X'
    if win('X'):
        show()
        print("You win!")
        break

    e = [(i,j) for i in range(3) for j in range(3) if b[i][j] == ' ']
    if not e:
        show()
        print("Tie")
        break
    
    r,c = random.choice(e)
    b[r][c] = 'O'

    if win('O'):
        show()
        print("Bot Wins!")
        break
    
    e = [(i,j) for i in range(3) for j in range(3) if b[i][j] == ' ']
    if not e:
        show()
        print("Tie")
        break
    
        
