import matplotlib.pyplot as plt
from matplotlib.axes import Axes
from app.percentagePlotter import PercentagePlotter, PlotType
import json

assetsPath = "assets/"

def charsPlot(charCounts: list[dict[str | int, float]], colors):
    charAxes: dict[str, Axes] = {}

    n = 8
    charFig, (
        charAxes["letters"],
        charAxes["vows"],
        charAxes["cons"],
        charAxes["voiced"],
        charAxes["voiceless"],
        charAxes["rare"],
        charAxes["other"],
        charAxes["punct"]
    ) = plt.subplots(n, 1, figsize=(30, 5*n))

    plotter = PercentagePlotter(colors)

    with open(assetsPath + "charTypes.json") as f:
        charTypes = json.load(f)

        for key in charAxes:
            ax = charAxes[key]
            plotter.plot(ax, charCounts, PlotType.BAR, charTypes[key])
            ax.set_title(key)

    return charFig