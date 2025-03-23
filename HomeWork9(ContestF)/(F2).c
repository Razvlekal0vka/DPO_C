void sort_even_odd(int n, int a[]) {
    int* temp = (int*)malloc(n * sizeof(int));
    int evenIndex = 0;

    // Проходим по исходному массиву и записываем четные числа в начало
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            temp[evenIndex++] = a[i];
        }
    }

    // Проходим по исходному массиву и записываем нечетные числа в конец
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            temp[evenIndex++] = a[i];
        }
    }

    // Копируем отсортированные элементы обратно в исходный массив
    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }

    // Освобождаем память, выделенную под временный массив
    free(temp);
}
