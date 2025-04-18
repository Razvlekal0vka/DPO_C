int find_max_array(int size, int a[]) {
    // Проверяем, что массив не пустой
    if (size <= 0) {
        return 0; // Возвращаем 0, если массив пустой
    }

    int max = a[0]; // Инициализируем максимальный элемент первым элементом массива

    // Проходим по массиву и ищем максимальный элемент
    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    return max; // Возвращаем найденный максимальный элемент
}
