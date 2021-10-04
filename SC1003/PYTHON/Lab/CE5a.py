from sense_hat import SenseHat

sense = SenseHat()

def not_validate_color(number):
    if not number.isnumeric():
        return True
    elif int(number) < 0 or int(number) > 255:
        return True
    else:
        return False

def get_color(color):
    keep_looping = True
    no_of_try = 0
    while keep_looping and no_of_try < 3:
        color_str = input("Enter the value of the " + color + \
        " color for message (0 to 255)")
        keep_looping = not_validate_color(color_str)
        no_of_try += 1
    if not not_validate_color(color_str):
        return int(color_str)
    else: return 0

if __name__ == "__main__":        
        
    r_int = get_color("red")
    g_int = get_color("green")
    b_int = get_color("blue")
    
    msg_color = (r_int, g_int, b_int)
    sense.show_message("I got it!", text_colour=msg_color)