### Директории
* bin - для скомпилированного
* assets - для предлогов и т.п.
* input - входные данные
* output - выходные данные
* src - для c++ 
* include - для хедеров
* analytics - для графиков и аналитики данных
* analytics/plots - готовые графики

### Сборка анализатора текста (С++)
* Для windows: ```mingw32-make```
* Для Linux: ```make ```

### Code::Blocks
* Открой `cppProject.cbp` и выбери цель `Debug` или `Release`.
* Все исходники уже подключены; флаги совпадают с `Makefile` (`-std=c++20 -Wall -Wextra` + линковка `-lstdc++fs` для `std::filesystem`).
* Рабочая директория задана в корень проекта, поэтому `input/`, `assets/` и `output/` ищутся корректно; бинарники собираются в `bin/main_debug` и `bin/main`.

### Запуск С++
* ```./bin/main```

### Предустановка окружения python
* ```python3 -m venv .venv```
* ```source .venv/bin/activate```
* ```pip install -r requirements.txt```

### Генерация графиков
* ```python3 analytics/main.py```
