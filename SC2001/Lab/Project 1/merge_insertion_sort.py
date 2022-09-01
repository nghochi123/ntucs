import os
import datetime
from create_datasets import read_pickled_list


# Definition of a key comparison: one if or if-else statement in merge.

keycomparisons = 0

SIZE_TO_SWITCH = 10


def insertionsort(array):
    global keycomparisons
    length = len(array)
    for i in range(length):
        for j in range(i, 0, -1):
            keycomparisons += 1
            if array[j] < array[j - 1]:
                array[j - 1], array[j] = array[j], array[j-1]
            else:
                break
    return array


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


def merge_insertion_sort(array):
    length = len(array)
    if length <= 1:
        return array
    if length <= SIZE_TO_SWITCH:
        array = insertionsort(array)
        return array
    mid = length // 2
    arrLeft = array[:mid]
    arrRight = array[mid:]
    arrLeft = merge_insertion_sort(arrLeft)
    arrRight = merge_insertion_sort(arrRight)
    newArr = merge(arrLeft, arrRight)
    return newArr


if __name__ == '__main__':
    a = datetime.datetime.now()
    os.chdir("datasets")

    array = read_pickled_list(os.getcwd(), "10^4x1\\5")[0]
    array = merge_insertion_sort(array)
    # print(array)
    print(keycomparisons)
    b = datetime.datetime.now()
    print(b - a)
