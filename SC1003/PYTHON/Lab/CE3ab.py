from sense_hat import SenseHat

sense = SenseHat()
exitmsg = "You have exceeded the number of trials allowed. Bye!"

def validate_color(number, count):
    if not number.isnumeric():
        print("Invalid - use number only ({})".format(count))
    elif int(number) < 0 or int(number) > 255:
        print("Invalid - Value has to be between 0 and 255 ({})".format(count))
    else:
        return True
    return False
        
def validate_speed(number, count):
    try:
        value = float(number)
        if value < 0.05 or value > 1:
            print("Invalid - value has to be between 0.05 and 1 ({})".format(count))
            print(value)
        else:
            return True
    except ValueError:
        print("Invalid - use number only ({})".format(count))
    return False

# Request for message
message = input("Please enter your message: ")
colour_msg = []
colour_bg = []
# Requesting for color
errorcount = 1
cnt = False
for i in ('red', 'green', 'blue'):
    while not cnt:
        value = input("Please enter a {} value for message: ".format(i))
        cnt = validate_color(value, errorcount)
        if cnt:
            colour_msg.append(int(value))
        elif errorcount >= 3:
            print(exitmsg)
            exit()
        else:
            errorcount += 1
    cnt = False

colour_msg = tuple(colour_msg)
print('Message Color: ' + str(colour_msg))
# Requesting for background color
for i in ('red', 'green', 'blue'):
    while not cnt:
        value = input("Please enter a {} value for background: ".format(i))
        cnt = validate_color(value, errorcount)
        if cnt:
            colour_bg.append(int(value))
        elif errorcount >= 3:
            print(exitmsg)
            exit()
        else:
            errorcount += 1
    cnt = False
colour_bg = tuple(colour_bg)
print('Background Color: ' + str(colour_bg))

# Request for speed

while not cnt:
    speed = input("Please enter a speed as a floating\
point greater than 0. (lower is faster): ")
    cnt = validate_speed(speed, errorcount)
    if cnt:
        speed = float(speed)
    elif errorcount >= 3:
        print(exitmsg)
        exit()
    else:
        errorcount += 1

sense.show_message(message, 
                    text_colour=colour_msg, 
                    back_colour=colour_bg, 
                    scroll_speed = speed)

sense.clear()

print('ok bb')

