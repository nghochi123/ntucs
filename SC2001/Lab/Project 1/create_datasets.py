import os
import shutil
import numpy as np
import pickle

MAX_VALUE = 100000
NUM_DATASETS_PER = 5


def wipe_folder(folder):
    shutil.rmtree(folder)


def read_pickled_list(folder, file):
    with open(os.path.join(folder, file), 'rb') as f:
        ll = pickle.load(f)
        f.close()
        return ll


def create_all_datasets(max_val, num_datasets):
    for i in range(3, 8):
        for j in range(1, 6, 4):
            if i == 7 and j == 5:
                break
            folderName = f"10^{i}x{j}"
            if not os.path.exists(os.path.join(os.getcwd(), folderName)):
                os.mkdir(os.path.join(os.getcwd(), folderName))
            os.chdir(folderName)
            for k in range(num_datasets):
                arr = (np.random.rand(1, j * 10**i) *
                       max_val).astype(int).tolist()
                with open(str(k), 'wb') as f:
                    pickle.dump(arr, f)
                    f.close()
            os.chdir("..")


if __name__ == "__main__":
    os.chdir("datasets")
    create_all_datasets(MAX_VALUE, NUM_DATASETS_PER)
    # wipe_folder(".")
