import os
import datetime
from create_datasets import read_pickled_list


# Definition of a key comparison: one if or if-else statement in merge.

keycomparisons = 0


def merge(arrLeft, arrRight):
    global keycomparisons
    newArr = []
    l = 0
    r = 0
    lenLeft = len(arrLeft)
    lenRight = len(arrRight)
    while l < lenLeft and r < lenRight:
        keycomparisons += 1
        if arrLeft[l] < arrRight[r]:  # Specifically this one.
            newArr.append(arrLeft[l])
            l += 1
        else:
            newArr.append(arrRight[r])
            r += 1
    return newArr + arrLeft[l:] + arrRight[r:]


def mergesort(array):
    length = len(array)
    if length <= 1:
        return array
    mid = length // 2
    arrLeft = array[:mid]
    arrRight = array[mid:]
    arrLeft = mergesort(arrLeft)
    arrRight = mergesort(arrRight)
    newArr = merge(arrLeft, arrRight)
    return newArr


if __name__ == '__main__':
    a = datetime.datetime.now()
    os.chdir("datasets")
    # for i in range(3, 8):
    #     for j in range(1, 6, 4):

    array = read_pickled_list(os.getcwd(), "10^4x1\\1")[0]
    array = mergesort(array)
    # print(array)
    print(keycomparisons)
    b = datetime.datetime.now()
    print(b - a)
