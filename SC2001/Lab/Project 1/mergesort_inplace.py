# Definition of a key comparison: one if or if-else statement in merge.
import datetime
import os
from create_datasets import read_pickled_list

keycomparisons = 0


def merge(array, left, right):
    global keycomparisons
    if right - left <= 0:
        return
    mid = (left + right) // 2
    lstart, mstart = left, mid + 1
    while (lstart <= mid and mstart <= right):
        keycomparisons += 1
        if array[lstart] <= array[mstart]:  # Specifically this one.
            lstart += 1
        else:
            temp = array[mstart]
            for i in range(mstart, lstart, -1):
                array[i] = array[i-1]
            array[lstart] = temp
            lstart += 1
            mid += 1
            mstart += 1


def mergesort(array, left, right):
    if right - left <= 0:
        return
    mid = (right + left) // 2
    mergesort(array, left, mid)
    mergesort(array, mid + 1, right)
    merge(array, left, right)


if __name__ == '__main__':
    a = datetime.datetime.now()
    os.chdir("datasets")
    # for i in range(3, 8):
    #     for j in range(1, 6, 4):

    array = read_pickled_list(os.getcwd(), "10^4x1\\1")[0]
    array = mergesort(array, 0, len(array) - 1)
    # print(array)
    print(keycomparisons)
    b = datetime.datetime.now()
    print(b - a)
