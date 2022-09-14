import os
import datetime
from create_datasets import read_pickled_list


# Definition of a key comparison: one if or if-else statement in merge.

keycomparisons = 0

SIZE_TO_SWITCH = 0


class MergeInsertionSort():
    def __init__(self, array, size_to_switch, max_val):
        self.keycomparisons = 0
        self.size_to_switch = size_to_switch
        self.originalArray = array
        self.max_val = max_val
        self.timetaken_ms = 0
        self.timetaken_mis = 0

    def insertionsort(self, array):
        for i in range(1, len(array)):
            key = array[i]
            j = i-1
            while j >= 0 and key < array[j]:
                self.keycomparisons += 1
                array[j + 1] = array[j]
                j -= 1
            array[j + 1] = key
        return array

    def merge(self, arrLeft, arrRight):
        newArr = []
        l = 0
        r = 0
        lenLeft = len(arrLeft)
        lenRight = len(arrRight)
        while l < lenLeft and r < lenRight:
            self.keycomparisons += 1
            if arrLeft[l] < arrRight[r]:  # Specifically this one.
                newArr.append(arrLeft[l])
                l += 1
            else:
                newArr.append(arrRight[r])
                r += 1
        return newArr + arrLeft[l:] + arrRight[r:]

    def merge_insertion_sort(self, array):
        length = len(array)
        if length <= 1:
            return array
        if length <= self.size_to_switch:
            array = self.insertionsort(array)
            return array
        mid = length // 2
        arrLeft = array[:mid]
        arrRight = array[mid:]
        arrLeft = self.merge_insertion_sort(arrLeft)
        arrRight = self.merge_insertion_sort(arrRight)
        newArr = self.merge(arrLeft, arrRight)
        return newArr

    def mergesort(self, array):
        length = len(array)
        if length <= 1:
            return array
        mid = length // 2
        arrLeft = array[:mid]
        arrRight = array[mid:]
        arrLeft = self.merge_insertion_sort(arrLeft)
        arrRight = self.merge_insertion_sort(arrRight)
        newArr = self.merge(arrLeft, arrRight)
        return newArr

    def sort(self):
        a = datetime.datetime.now()
        s = self.merge_insertion_sort(self.originalArray)
        b = datetime.datetime.now()
        self.timetaken_mis = b - a
        return s

    def write_mis_data(self, numitems):
        with open("C:\\Users\\nghoc\\Desktop\\GitHub\\ntucs\\SC2001\\Lab\\Project 1\\data_merge_insertion_new.csv", "a") as f:
            f.write(
                f"{self.max_val},{self.size_to_switch},{self.keycomparisons},{self.timetaken_mis},{numitems}\n")
            f.close()


if __name__ == '__main__':
    os.chdir(
        "C:\\Users\\nghoc\\Desktop\\GitHub\\ntucs\\SC2001\\Lab\\Project 1\\datasets")
    array = read_pickled_list(os.getcwd(), "10^5x1\\4")[0]
    mis = MergeInsertionSort(array, SIZE_TO_SWITCH, 100000)
    mis.sort()
    mis.write_mis_data()
    # print(array)
    print(mis.keycomparisons)
    print(mis.timetaken)
