from sense_hat import SenseHat
from time import sleep

sense = SenseHat()
while True:
    pitch = sense.get_orientation()['pitch']
    roll = sense.get_orientation()['roll']
    print("pitch {} roll {}".format(round(pitch), round(roll)))
    sleep(0.05)