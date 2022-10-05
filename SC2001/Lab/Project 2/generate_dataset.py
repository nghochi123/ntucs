import os
import shutil
from random import randint

NUM_DATASETS = 2
MAX_WEIGHT = 300


def wipe_folder(folder):
    shutil.rmtree(folder)


def create_all_datasets():
    os.chdir(os.path.join(os.getcwd(), 'datasets'))
    for vertices in range(5, 25):
        x = randint(0, (vertices - 3) * 10)
        y = randint(0, (vertices * 10) - 1)
        filename = f"10x{vertices}"
        nodes = []
        weights = []
        for edges in range(20):
            for c in range(40):
                while [x, y] in nodes:
                    x = randint(0, (vertices - 3) * 10)
                    y = randint(0, (vertices * 10) - 1)
                    if x > y:
                        x, y = y, x
                nodes.append([x, y])
                weights.append(randint(0, MAX_WEIGHT))
            weights = [x for _, x in sorted(
                zip(nodes, weights), key=lambda pair: pair[0])]
            nodes.sort()
            with open(f"{filename}", 'a') as f:
                f.write(f"{10 * vertices}\n")
                for a, b in zip(nodes, weights):
                    f.write(f"{a[0]} {a[1]} {b}\n")
                f.write("-1\n")
                f.close()
        with open(f"{filename}", 'a') as f:
            f.write("-2\n")
            f.close()


if __name__ == '__main__':
    create_all_datasets()
