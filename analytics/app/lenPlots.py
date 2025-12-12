import matplotlib.pyplot as plt
from matplotlib.axes import Axes
from app.percentagePlotter import PercentagePlotter, PlotType

assetsPath = "assets/"

def lensPlot(wordLenCount: list[list[tuple[int, int]]], sentenceLenCount: list[list[tuple[int, int]]], colors):
    lensAxes: dict[str, Axes] = {}

    n = 2
    fig, (
        lensAxes["word length"],
        lensAxes["sentence length"],
    ) = plt.subplots(n, 1, figsize=(30, 5*n))

    plotter = PercentagePlotter(colors)

    for key in lensAxes:
        ax = lensAxes[key]
        count = wordLenCount if key == "word length" else sentenceLenCount
        newCount: list[dict[str | int, float]] = [{} for _ in range(len(count))]

        mx = 0
        for a in count:
            for b in a:
                mx = max(mx, b[0])

        for i, d in enumerate(count):
            newCount[i] = {a[0]: a[1] for a in d}

        plotter.plot(ax, newCount, PlotType.PLOT, list(range(1, mx+1)))
        ax.set_title(key)

    return fig