# Importing Necessary modules
from sense_hat import SenseHat
from time import sleep
from random import randint

# Declaring initial variables
red = (255, 0, 0)
yellow = (255, 255, 0)
green = (0, 255, 0)
blue = (0, 0, 255)

sense = SenseHat()

# Setting 4 corners to red, yellow, green, blue
sense.set_pixel(0, 0, red)
sense.set_pixel(0, 7, yellow)
sense.set_pixel(7, 0, green)
sense.set_pixel(7, 7, blue)

# Four colours on random positions
for i in range(30):
    sense.set_pixel(randint(0, 7), randint(0, 7), red)
    sense.set_pixel(randint(0, 7), randint(0, 7), yellow)
    sense.set_pixel(randint(0, 7), randint(0, 7), green)
    sense.set_pixel(randint(0, 7), randint(0, 7), blue)
    # Wait for 1 second before displaying next batch
    sleep(1)

# Clear lights after finishing 30 batches
sense.clear()
