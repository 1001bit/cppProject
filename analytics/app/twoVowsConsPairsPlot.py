import matplotlib.pyplot as plt
from matplotlib.axes import Axes
from app.percentagePlotter import PercentagePlotter, PlotType
import numpy as np

def twoVowsConsPairsPlot(twoVowsConsNeighbors: list[int], colors):
    n = 1
    charFig, (
        ax
    ) = plt.subplots(n, 1, figsize=(10, 5*n))

    plotter = PercentagePlotter(colors)

    plotter.plot(ax, [{"pairs": n} for n in twoVowsConsNeighbors], PlotType.BAR, ["pairs"], countPercents=False)
    ax.set_title("пары слов, первое из которых заканчивается на 2 гласные, а второе начинается с 2 согласных")
    ax.set_ylabel('кол-во')

    return charFig