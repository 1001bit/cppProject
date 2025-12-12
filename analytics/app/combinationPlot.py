import matplotlib.pyplot as plt
from matplotlib.axes import Axes
from app.percentagePlotter import PercentagePlotter, PlotType
import json

assetsPath = "assets/"

def combinationsPlot(combinationsCount: list[dict[str | int, float]], colors):
    n = 1
    fig, (
        ax
    ) = plt.subplots(n, 1, figsize=(50, 5*n))

    plotter = PercentagePlotter(colors)

    with open(assetsPath + "combinations.json") as f:
        combinations = json.load(f)

        plotter.plot(ax, combinationsCount, PlotType.BAR, combinations)
        ax.set_title("комбинации букв")

    return fig