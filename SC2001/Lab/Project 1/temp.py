with open("data_shortened_merge.csv", 'r') as f:
    x = f.readlines()
    arr = [(10 ** i) * j for i in range(3, 8) for j in [1]]
    count = -1
    with open("data_shortened_merge_new.csv", 'a') as f1:
        for lineIndex in range(1, len(x)):
            if (lineIndex - 1) % 2 == 0:
                count += 1
                if count >= len(arr):
                    count = 0
            size = arr[count]
            f1.write("{},{}\n".format((x[lineIndex]).replace('\n', ''), size))
        f1.close()
    f.close()
