#include <iostream>

int main() {
    int tamanho = 5;
    int *array = new int[tamanho];
    int arrayLength = 0;
    std::cout << "Digite " << tamanho << " números:" << std::endl;

    // Inicializando

    for (int i = 0; i < tamanho; i++) {
        array[i] = -1;
    }

    // Lendo os números digitados pelo usuário e adicionando ao array
    for (int i = 0; i < tamanho; i++) {
        std::cout << "Número " << i + 1 << ": ";
        int input;

        std::cin >> input;
        if (arrayLength == 0) {
            array[i] = input;
            arrayLength++;
        } else {
            for (int j = 0; j < tamanho; j++) {
                if (input <= array[j]) {
                    int arrayTmp[tamanho];

                    for (int i = 0; i < tamanho; ++i) {
                        arrayTmp[i] = array[i];
                    }
                    array[j] = input;

                    for (int k = j+1; k < tamanho; k++) {
                        array[k] = arrayTmp[k - 1];
                    }

                    break;
                } else if (array[j] == -1) {
                    array[j] = input;
                    break;
                }
            }
        }
    }

    // Imprimindo o array
    std::cout << "Array:" << std::endl;
    for (int i = 0; i < tamanho; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
