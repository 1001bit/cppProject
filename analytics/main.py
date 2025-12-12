import os
import json
import matplotlib.pyplot as plt
from matplotlib.axes import Axes
from app.charsPlot import *
from app.lenPlots import *
from app.prepsPlot import *
from app.combinationPlot import *
from app.vowConAlterPlot import *
from app.conVowEndStartPlot import *
from app.threeInARowPlot import *
from app.twoVowsConsPairsPlot import *
from app.topWordsPlot import *

def main() -> None:
    files = []

    for fileName in sorted(os.listdir("output")):
        path = "output/" + fileName
        with open(path) as f:
            d = json.load(f)
            files.append(d)

    colors = ['tab:red', 'tab:grey', 'tab:green', 'tab:pink']
    plotsPath = "analytics/plots/"

    charFig = charsPlot([f["charCnt"] for f in files], colors)
    charFig.savefig(plotsPath + "chars.png")

    lensFig = lensPlot(
        [f["wordLenCount"] for f in files],
        [f["sentenceLenCount"] for f in files],
        colors
    )
    lensFig.savefig(plotsPath + "lens.png")

    prepsFig = prepsPlot([f["wordsCount"] for f in files], colors)
    prepsFig.savefig(plotsPath + "preps.png")

    combinationsFig = combinationsPlot([f["combinationsCount"] for f in files], colors)
    combinationsFig.savefig(plotsPath + "combinations.png")

    vowConAlterFig = vowConAlterPlot([f["conVowAltCount"] for f in files], colors)
    vowConAlterFig.savefig(plotsPath + "vowConAlterFig.png")

    conVowEndStartFig = conVowEndStartPlot([f["conVowEndStartCount"] for f in files], colors)
    conVowEndStartFig.savefig(plotsPath + "conVowEndStartFig.png")

    threeInARowFig = threeVowsConsInARowPlot([f["threeVowsOrConsInARow"] for f in files], colors)
    threeInARowFig.savefig(plotsPath + "threeVowsOrConsInARow.png")

    twoVowsConsPairsFig = twoVowsConsPairsPlot([f["twoVowsConsNeighbors"] for f in files], colors)
    twoVowsConsPairsFig.savefig(plotsPath + "twoVowsConsPairs.png")

    topWordsFig = topWordsPlot([f["wordsCount"] for f in files], colors)
    topWordsFig.savefig(plotsPath + "topWords.png")

if __name__ == "__main__":
    main()