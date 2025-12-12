import matplotlib.pyplot as plt
from matplotlib.axes import Axes
from app.percentagePlotter import PercentagePlotter, PlotType
import json

assetsPath = "assets/"

def vowConAlterPlot(conVowAltCount: list[dict[str, dict[str, int]]], colors):
    alterAxes: dict[str, Axes] = {}

    n = 4
    fig, (
        alterAxes["conAfter"],
        alterAxes["conBefore"],
        alterAxes["vowAfter"],
        alterAxes["vowBefore"],
    ) = plt.subplots(n, 1, figsize=(30, 5*n))

    plotter = PercentagePlotter(colors)

    with open(assetsPath + "charTypes.json") as f:
        charTypes = json.load(f)

        for typeAndPos in alterAxes:
            ax = alterAxes[typeAndPos]

            newCount: list[dict[str | int, float]] = [
                {
                    char: d[char][typeAndPos]/(max(sum(d[char].values()), 1))*100 for char in d
                } for d in conVowAltCount
            ]

            plotter.plot(ax, newCount, PlotType.BAR, charTypes["vows"] + charTypes["cons"], countPercents=False)
            ax.set_title(typeAndPos)

    return fig