from sense_hat import SenseHat
from time import sleep
from random import randint
import copy
from threading import Timer

sense = SenseHat()

b = (0,0,0)
w = (255,255,255)
r = (255,0,0)
g = (0,255,0)

gloc = [2,4]

board = [[r,r,r,b,b,b,b,r], 
         [r,b,b,b,b,b,b,r],
         [b,b,b,b,b,r,b,r],
         [b,r,r,b,r,r,b,r],
         [b,b,b,b,b,b,b,b],
         [b,r,b,r,r,b,b,b],
         [b,b,b,r,b,b,b,r], 
         [r,r,b,b,b,r,r,r] ]

board[gloc[0]][gloc[1]] = g
         

y = 2
x = 2
board[y][x] = w
board_1D = sum(board,[])
sense.set_pixels(board_1D)

def check_wall(x,y,new_x,new_y):
    if board[new_y][new_x] != r:
        return new_x, new_y
    elif board[new_y][x]  != r:
        return x, new_y
    elif board[y][new_x] != r:
        return new_x,y
    else: return x,y

def move_marble(pitch,roll,x,y):
    new_x = x
    new_y = y
    if 1 < pitch < 179 and x != 0:
        new_x -= 1
    elif 359 > pitch > 179 and x!= 7:
        new_x += 1
    if 1 < roll < 179 and y != 7:
        new_y += 1
    elif 359 > roll > 179 and y != 0:
        new_y -= 1
    
    new_x, new_y = check_wall(x,y,new_x,new_y)
        
    return new_x, new_y
    
def reset_board():
    board = [[r,r,r,b,b,b,b,r], 
         [r,b,b,b,b,b,b,r],
         [b,b,b,b,b,r,b,r],
         [b,r,r,b,r,r,b,r],
         [b,b,b,b,b,b,b,b],
         [b,r,b,r,r,b,b,b],
         [b,b,b,r,b,b,b,r], 
         [r,r,b,b,b,r,r,r] ]
    board[gloc[0]][gloc[1]] = g
    return board


# def change_position():
#     global gloc
#     y = randint(0,7)
#     x = randint(0,7)
#     gloc = [y,x]
#     Timer(10.0, change_position).start()

# Timer(10.0, change_position).start()

while True:
    pitch = sense.get_orientation()['pitch']
    roll = sense.get_orientation()['roll']
    x, y = move_marble(pitch,roll,x,y)
    board = reset_board()
    board[y][x] = w
    board_1D = sum(board,[])
    sense.set_pixels(board_1D)
    # if x == gloc[1] and y == gloc[0]:
    #     sense.show_message('You Win',
    #                       text_colour=g,
    #                       back_colour=b)
    #     break