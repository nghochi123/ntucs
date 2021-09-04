import os
import PIL.Image as p

fp = "C:\\Users\\nghoc\\Desktop\\GitHub\\ntucs\\SC1003\\Lab\\bad_apple"

width = 8
height = 8


def gs(img):
    return(img.convert("L"))


def resize(image, new_width=width, new_height=height):
    return image.resize((new_width, new_height))


def img_arr(img):
    image = gs(p.open(img))
    rs_img = resize(image)
    pixels = list(rs_img.getdata())
    return pixels


# The final function to convert an image to an 8x8 format.
def to_8x8(img):
    os.chdir(fp)
    np = img_arr(img)
    image = []
    count = 0
    for i in range(8):
        image.append([])
        for j in range(8):
            image[i].append(np[count])
            count += 1

    return image


os.chdir(fp)
image = to_8x8('scene00205.png')
print(image)
