import os
import json
import matplotlib.pyplot as plt
from matplotlib.axes import Axes
from app.charsPlot import *
from app.lenPlots import *

def main() -> None:
    files = []

    for fileName in os.listdir("output"):
        path = "output/" + fileName
        with open(path) as f:
            d = json.load(f)
            files.append(d)

    colors = ['tab:red', 'tab:green', 'tab:grey', 'tab:pink']
    plotsPath = "analytics/plots/"  
    plt.tight_layout()

    charFig = charsPlot([f["charCnt"] for f in files], colors)
    charFig.savefig(plotsPath + "chars.png")

    lensFig = lensPlot(
        [f["wordLenCount"] for f in files],
        [f["sentenceLenCount"] for f in files],
        colors
    )
    lensFig.savefig(plotsPath + "lens.png")

if __name__ == "__main__":
    main()