# def bubblesort(alist):
#     for passnum in range(len(alist)-1):
#         for i in range(len(alist)-passnum-1):
#             if alist[i] > alist[i+1]:
#                 temp = alist[i]
#                 alist[i] = alist[i+1]
#                 alist[i+1] = temp
#         print('pass', passnum + 1, ':', alist)


# alist = [3, 5, 8, 11, 17, 20]
# bubblesort(alist)
# print(alist)

def bubblesort(alist):
    for passnum in range(len(alist)-1):
        swapped = False
        for i in range(len(alist)-passnum-1):
            if alist[i] > alist[i+1]:
                temp = alist[i]
                alist[i] = alist[i+1]
                alist[i+1] = temp
                swapped = True
        print('pass', passnum + 1, ':', alist)
        if not swapped:
            break


alist = [3, 5, 8, 11, 17, 20]
bubblesort(alist)
print(alist)
