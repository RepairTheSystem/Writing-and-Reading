#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

void writeMemory(double memsize) {
    // Вычисляем количество элементов int для записи в память
    size_t num_elements = static_cast<size_t>(memsize * 1024 * 1024 * sizeof(int));

    // Выделяем память
    int* memory = reinterpret_cast<int*>(malloc(num_elements * sizeof(int)));

    // Размер шага в байтах для записи в память (4 килобайта)
    size_t step = 4 * 1024;

    // Записываем данные в память
    for (size_t i = 0; i < num_elements; i += step / sizeof(int)) {
        const_cast<volatile int*>(memory)[i] = 0;
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Задержка 1 миллисекунда
    }

    // Освобождаем память
    free(memory);
    memory = nullptr;
}

int main() {
    // Пример использования функции writeMemory
    double memsize_in_gb = 1.0; // Размер памяти в гигабайтах
    writeMemory(memsize_in_gb);

    return 0;
}
