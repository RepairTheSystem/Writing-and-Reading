#include <iostream>
#include <chrono>
#include <thread>

void writeMemory(double memsize) {
    // Вычисляем количество элементов int для записи в память
    size_t num_elements = static_cast<size_t>(memsize * 1024 * 1024 * sizeof(int));

    // Выделяем память
    int* memory = new int[num_elements];

    // Размер шага в байтах для записи в память (4 килобайта)
    size_t step = 4 * 1024;

    // Записываем данные в память
    for (size_t i = 0; i < num_elements; i += step / sizeof(int)) {
        const_cast<volatile int*>(memory)[i] = 0;
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Задержка 1 миллисекунда
    }

    // Освобождаем память
    delete[] memory;
    memory = nullptr;
}

int main() {
    double memsize_in_gb = 1.0; // Размер памяти в гигабайтах
    writeMemory(memsize_in_gb);

    return 0;
}
