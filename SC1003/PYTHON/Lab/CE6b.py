from sense_hat import SenseHat
from time import sleep

sense = SenseHat()

b = (0,0,0)
w = (255,255,255)

board = [[b,b,b,b,b,b,b,b], 
         [b,b,b,b,b,b,b,b],
         [b,b,b,b,b,b,b,b],
         [b,b,b,b,b,b,b,b],
         [b,b,b,b,b,b,b,b],
         [b,b,b,b,b,b,b,b],
         [b,b,b,b,b,b,b,b], 
         [b,b,b,b,b,b,b,b] ]

y = 2
x = 2
board[y][x] = w
board_1D = sum(board,[])
sense.set_pixels(board_1D)