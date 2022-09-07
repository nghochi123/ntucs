import os
from create_datasets import wipe_folder, create_all_datasets, read_pickled_list
from merge_insertion_sort import MergeInsertionSort

SIZE_TO_SWITCH = 10
NUM_DATASETS = 5

if __name__ == '__main__':
    for sts in range(0, 25, 5):
        for i in range(3, 8):
            for j in [1]:
                if i == 7 and j == 5:
                    break
                os.mkdir(
                    "C:\\Users\\nghoc\\Desktop\\GitHub\\ntucs\\SC2001\\Lab\\Project 1\\datasets")
                os.chdir(
                    "C:\\Users\\nghoc\\Desktop\\GitHub\\ntucs\\SC2001\\Lab\\Project 1\\datasets")
                create_all_datasets((10 ** i) * j, 5)
                for a in range(3, 8):
                    for b in [1]:
                        if a == 7 and b == 5:
                            break
                        for c in [1, 2]:
                            array = read_pickled_list(
                                os.getcwd(), f"10^{a}x{b}\\{c}")[0]
                            mis = MergeInsertionSort(array, sts, (10**i) * j)
                            mis.sort()
                            mis.write_mis_data()
                os.chdir(
                    "C:\\Users\\nghoc\\Desktop\\GitHub\\ntucs\\SC2001\\Lab\\Project 1")
                wipe_folder(
                    'C:\\Users\\nghoc\\Desktop\\GitHub\\ntucs\\SC2001\\Lab\\Project 1\\datasets')
