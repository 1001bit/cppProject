import matplotlib.pyplot as plt
from matplotlib.axes import Axes
from app.percentagePlotter import PercentagePlotter, PlotType
import json

assetsPath = "assets/"

def lensPlot(wordLenCount: list[list[tuple[int, int]]], sentenceLenCount: list[list[tuple[int, int]]], colors):
    charAxes: dict[str, Axes] = {}

    n = 2
    charFig, (
        charAxes["word length"],
        charAxes["sentence length"],
    ) = plt.subplots(n, 1, figsize=(30, 5*n))

    plotter = PercentagePlotter(colors)

    for key in charAxes:
        ax = charAxes[key]
        data = wordLenCount if key == "word length" else sentenceLenCount
        newData: list[dict[str | int, int]] = [{} for _ in range(len(data))]

        mx = 0
        for a in data:
            for b in a:
                mx = max(mx, b[0])

        for i, d in enumerate(data):
            newData[i] = {a[0]: a[1] for a in d}

        plotter.plot(ax, newData, PlotType.PLOT, list(range(mx)))
        ax.set_title(key)

    return charFig