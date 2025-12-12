import matplotlib.pyplot as plt
from matplotlib.axes import Axes
import numpy as np
from enum import Enum

class PlotType(Enum):
    BAR = 1
    PLOT = 2

class PercentagePlotter():
    def __init__(self, colors):
        self.colors = colors

    def plot(self, ax: Axes, data: list[dict[str | int, float]], type: PlotType, labels: list[str | int], countPercents = True):
        values = [[0.0] * len(labels) for _ in range(len(data))]

        if countPercents:
            for i, d in enumerate(data):
                totalCnt = 0
                for key in d:
                    totalCnt += d[key]
                for key in d:
                    if totalCnt == 0 or key not in labels: continue
                    values[i][labels.index(key)] = d[key]/totalCnt*100
        else:
            for i, d in enumerate(data):
                for key in d:
                    values[i][labels.index(key)] = d[key]


        n = len(labels)
        m = len(values)
        x = np.arange(n)

        width = 0.2
        groupWidth = width*m
        for i, v in enumerate(values):
            offset = -groupWidth/2 + i/m*groupWidth
            if type == PlotType.BAR:
                bars = ax.bar(x + offset, v, width, label=f'text {i+1}', color=self.colors[i%len(self.colors)])
                ax.bar_label(bars, padding=0, fontsize=6)
            else:
                ax.plot(x, v, label=f'text {i+1}', color=self.colors[i%len(self.colors)])

        ax.set_ylabel('%')
        ax.set_xticks(x)
        ax.set_xticklabels(map(str, labels))

        handles, labels = ax.get_legend_handles_labels()
        seen = {}
        for h, l in zip(handles, labels):
            if l not in seen:
                seen[l] = h
        ax.legend(seen.values(), seen.keys())
