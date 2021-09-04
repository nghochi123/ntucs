# Importing necessary modules
from sense_hat import SenseHat
from time import sleep

sense = SenseHat()

# Declaring initial variables
yellow = (255, 255, 0)
blank = (0, 0, 0)

c1 = blank
c2 = yellow
image_pixels = [c1, c1, c1, c1, c1, c1, c1, c1,
                c1, c1, c1, c2, c1, c1, c1, c1,
                c1, c1, c2, c2, c2, c1, c1, c1,
                c1, c2, c1, c2, c1, c2, c1, c1,
                c1, c1, c1, c2, c1, c1, c1, c1,
                c1, c1, c1, c2, c1, c1, c1, c1,
                c1, c1, c1, c2, c1, c1, c1, c1,
                c1, c1, c1, c1, c1, c1, c1, c1]

sense.set_pixels(image_pixels)
sense.clear()

# Modifying to switch between two colors

for i in range(20):
    c1 = yellow if c1 != yellow else blank
    c2 = yellow if c1 != yellow else blank
    image_pixels = [c1, c1, c1, c1, c1, c1, c1, c1,
                    c1, c1, c1, c2, c1, c1, c1, c1,
                    c1, c1, c2, c2, c2, c1, c1, c1,
                    c1, c2, c1, c2, c1, c2, c1, c1,
                    c1, c1, c1, c2, c1, c1, c1, c1,
                    c1, c1, c1, c2, c1, c1, c1, c1,
                    c1, c1, c1, c2, c1, c1, c1, c1,
                    c1, c1, c1, c1, c1, c1, c1, c1]
    sense.set_pixels(image_pixels)
    sleep(1)
    sense.clear()

# Modifying to auto rotate in 4 random orientations

for i in range(20):
    rotates = [0, 90, 180, 270]
    c1 = yellow if c1 != yellow else blank
    c2 = yellow if c1 != yellow else blank
    image_pixels = [c1, c1, c1, c1, c1, c1, c1, c1,
                    c1, c1, c1, c2, c1, c1, c1, c1,
                    c1, c1, c2, c2, c2, c1, c1, c1,
                    c1, c2, c1, c2, c1, c2, c1, c1,
                    c1, c1, c1, c2, c1, c1, c1, c1,
                    c1, c1, c1, c2, c1, c1, c1, c1,
                    c1, c1, c1, c2, c1, c1, c1, c1,
                    c1, c1, c1, c1, c1, c1, c1, c1]
    sense.set_rotation(rotates[i % 4])
    sense.set_pixels(image_pixels)
    sleep(1)
    sense.clear()
