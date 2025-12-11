import os
import json
import matplotlib.pyplot as plt
from matplotlib.axes import Axes
from app.charsPlot import *

def main() -> None:
    files = []

    for fileName in os.listdir("output"):
        path = "output/" + fileName
        with open(path) as f:
            d = json.load(f)
            files.append(d)

    colors = ['tab:red', 'tab:green', 'tab:grey', 'tab:pink']

    charFig = charsPlot([f["charCnt"] for f in files], colors)

    plt.tight_layout()
    plotsPath = "analytics/plots/"  
    charFig.savefig(plotsPath + "chars.png")

if __name__ == "__main__":
    main()