from toascii import to_ascii as convert
from time import sleep as delay


arr = []
delay(2)
#There are 6799 scenes(YNK); each is +6 from previous. This gives 1134 images.
#1134 images in 275 seconds.
for i in range(1,6752,6):
    arr.append('scene'+str(i).rjust(5,'0')+'.png')

for i in arr:
    print(convert(i))
    delay(0.19)
