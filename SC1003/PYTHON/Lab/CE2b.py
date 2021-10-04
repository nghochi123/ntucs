
# from sense_hat import SenseHat

# sense = SenseHat()

# message = "This is fun!"
# text_colour = (0,0,255)
# bg_colour = (255,0,0)
# speed = 0.01

# sense.set_rotation(180)

# sense.show_message(message, 
#                     text_colour=text_colour,
#                     back_colour=bg_colour,
#                     scroll_speed = speed)
                    
# sense.clear()

from sense_hat import SenseHat

sense = SenseHat()

message = input("Please enter your message: ")
colour_msg = []
colour_bg = []
for i in ('red', 'green', 'blue'):
    value = input("Please enter a {} value for message: ".format(i))
    colour_msg.append(int(value))
colour_msg = tuple(colour_msg)
for i in ('red', 'green', 'blue'):
    value = input("Please enter a {} value for background: ".format(i))
    colour_bg.append(int(value))
colour_bg = tuple(colour_bg)

speed = float(input("Please enter a speed (lower is faster): "))

sense.show_message(message, 
                    text_colour=colour_msg, 
                    back_colour=colour_bg, 
                    scroll_speed = speed)

sense.clear()

