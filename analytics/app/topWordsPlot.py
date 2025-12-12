import matplotlib.pyplot as plt
import numpy as np

def topWordsPlot(wordsCount: list[dict[str | int, float]], colors, top_n: int = 50):
    """Plot top words for each text as a horizontal row of vertical bar charts."""
    if len(wordsCount) == 0:
        return plt.figure()

    fig, axes = plt.subplots(1, len(wordsCount), figsize=(6*len(wordsCount), top_n/2), squeeze=False)

    for i, count in enumerate(wordsCount):
        ax = axes[0][i]

        if not count:
            ax.axis('off')
            ax.set_title(f'текст {i+1} — нет данных')
            continue

        top_items = sorted(count.items(), key=lambda item: item[1], reverse=True)[:top_n]
        labels = [word for word, _ in top_items]
        values = [freq for _, freq in top_items]
        y = np.arange(len(labels))

        bars = ax.barh(y, values, color=colors[i % len(colors)])
        ax.set_yticks(y)
        ax.set_yticklabels(labels)
        ax.invert_yaxis()
        ax.set_xlabel('кол-во вхождений')
        ax.set_title(f'текст {i+1}: топ {top_n} слов')
        ax.bar_label(bars, padding=2, fontsize=8)
        ax.margins(y=0.05)

    return fig
