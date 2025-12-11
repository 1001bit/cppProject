import matplotlib.pyplot as plt
from matplotlib.axes import Axes
import numpy as np

class BarPercentagePlotter():
    def __init__(self, colors):
        self.colors = colors

    def plot(self, ax: Axes, data: list[dict[str, int]], labels: list[str]):
        values = [[0.0] * len(labels) for _ in range(len(data))]

        for i, d in enumerate(data):
            totalCnt = 0
            for key in d:
                totalCnt += d[key]
            for key in d:
                if totalCnt == 0 or key not in labels: continue
                values[i][labels.index(key)] = d[key]/totalCnt

        ax.set_ylabel('%')

        n = len(labels)
        m = len(values)
        x = np.arange(n)

        width = 0.2
        groupWidth = width*m
        for i, v in enumerate(values):
            ax.bar(x + (-groupWidth/2 + i/m*groupWidth), v, width, label=f'text {i+1}', color=self.colors[i%len(self.colors)])

        ax.set_xticks(x)
        ax.set_xticklabels(labels)
        ax.legend()