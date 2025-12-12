import matplotlib.pyplot as plt
from matplotlib.axes import Axes
from app.percentagePlotter import PercentagePlotter, PlotType

def threeVowsConsInARowPlot(threeInARow: list[dict[str | int, float]], colors):
    n = 1
    charFig, (
        ax
    ) = plt.subplots(n, 1, figsize=(10, 5*n))

    plotter = PercentagePlotter(colors)

    plotter.plot(ax, threeInARow, PlotType.BAR, ["cons", "vows"])
    ax.set_title("три гласных/согласных подряд")

    return charFig