import matplotlib.pyplot as plt
from matplotlib.axes import Axes
from app.percentagePlotter import PercentagePlotter, PlotType
import json

assetsPath = "assets/"

def prepsPlot(wordsCount: list[dict[str | int, int]], colors):
    n = 1
    charFig, (
        ax
    ) = plt.subplots(n, 1, figsize=(300, 5*n))

    plotter = PercentagePlotter(colors)

    with open(assetsPath + "preps.json") as f:
        preps = json.load(f)

        plotter.plot(ax, wordsCount, PlotType.BAR, preps)
        ax.set_title("предлоги и союзы")

    return charFig