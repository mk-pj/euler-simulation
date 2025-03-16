import os
import pandas as pd
import matplotlib.pyplot as plt

def main():
    data_folder = "../data_output/"
    chart_folder = "../charts/"
    os.makedirs(data_folder, exist_ok=True)
    os.makedirs(chart_folder, exist_ok=True)

    for i in range(0, 11):
        k = round(i / 10, 2)
        basic_title = f"basic_k={k}.csv"
        basic_path = data_folder + basic_title

        better_title = f"better_k={k}.csv"
        better_path = data_folder + better_title

        try:
            basic_data = pd.read_csv(basic_path, names=["x", "y"], header=None, sep=",")
            x_basic = basic_data["x"]
            y_basic = basic_data["y"]

            better_data = pd.read_csv(better_path, names=["x", "y"], header=None, sep=",")
            x_better = better_data["x"]
            y_better = better_data["y"]

            plt.plot(x_basic, y_basic, label="basic euler")
            plt.plot(x_better, y_better, label="better euler")
            plt.grid()
            plt.legend()
            plt.xlabel("x")
            plt.ylabel("y")
            plt.title(f"Euler simulation k={k}")
            title = f"euler_k={k}"
            plt.savefig(chart_folder + title + ".png")
            plt.clf()
        except FileNotFoundError:
            print(f"File {basic_path} doesn't exist.")

if __name__ == '__main__':
    main()
