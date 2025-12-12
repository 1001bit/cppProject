import matplotlib.pyplot as plt
from matplotlib.axes import Axes
from app.percentagePlotter import PercentagePlotter, PlotType

def conVowEndStartPlot(conVowEndStartCount: list[dict[str | int, float]], colors):
    n = 1
    charFig, (
        ax
    ) = plt.subplots(n, 1, figsize=(30, 5*n))

    plotter = PercentagePlotter(colors)

    plotter.plot(ax, conVowEndStartCount, PlotType.BAR, ["conCon", "conVow", "vowCon", "vowVow"])
    ax.set_title("пары слов, начинающиеся/заканчивающиеся на гласную-согласную")

    return charFig