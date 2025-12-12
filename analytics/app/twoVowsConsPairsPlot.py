import matplotlib.pyplot as plt
from matplotlib.axes import Axes
from app.percentagePlotter import PercentagePlotter, PlotType
import numpy as np

def twoVowsConsPairsPlot(twoVowsConsNeighbors: list[int], colors):
    n = 1
    charFig, (
        ax
    ) = plt.subplots(n, 1, figsize=(10, 5*n))

    m = len(twoVowsConsNeighbors)
    width = 0.2
    groupWidth = width*m
    x = np.arange(1)
    for i, v in enumerate(twoVowsConsNeighbors):
        offset = -groupWidth/2 + i/m*groupWidth
        ax.bar(x + offset, v, width, label=f'text {i+1}', color=colors[i%len(colors)])

    ax.set_ylabel('кол-во')
    ax.set_title("пары слов, первое из которых заканчивается на 2 гласные, а второе начинается с 2 согласных")
    ax.set_xticks([])
    handles, labels = ax.get_legend_handles_labels()
    seen = {}
    for h, l in zip(handles, labels):
        if l not in seen:
            seen[l] = h
    ax.legend(seen.values(), seen.keys())

    return charFig