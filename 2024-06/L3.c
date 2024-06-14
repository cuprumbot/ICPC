/*
    Tiempo para redisenar
    16 minutos

    Tiempo en total
    11 + 5 + 16 = 32 minutos

    No nos interesa un algoritmo de ordenamiento normal
    Sabemos que son numeros consecutivos, entonces en cuanto veamos cierto numero
    lo podemos enviar a su posicion correcta

    No tenemos garantia que una pasada baste, entonces pasaremos varias veces sobre
    el mismo arreglo
    El flag nos indica si hicimos swaps en la ultima pasada, si no, ya es momento
    de terminar

    IDEAS IMPORTANTES:

    - En lugar de trabajar con un arreglo que comience desde indice 0...
      [ 1, 2, 3, 4, 5 ]
      0  1  2  3  4

      ...trabajamos con un arreglo que "comienza desde indice 1"
      [ basura, 1, 2, 3, 4, 5 ]
        0       1  2  3  4  5
      Esto nos ahorra bastante operaciones de +1 o -1

    - Puedo aprovechar que en C no existen los boolean
      flag = swaps - oldSwaps;          <- esta resta es muy barata
      En otro lenguaje probablemente necesitariamos una comparacion para el flag
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int i;                        // indice para ciclos
    int swaps, oldSwaps;          // swaps realizados en total, cuantos swaps llevaba al iniciar la pasada
    int dato, temp;               // dato que estoy viendo, temporal para hacer swap
    int flag;                     // me indica si hubieron swaps en la ultima pasada
    int size;
    int sizePlusOne;              // chapuz para poder trabajar desde indice 1
    int uno[1000000];             // mi problema fue el tiempo, no la memoria, entonces tendre siempre el tamano maximo de arreglo
    int dos[1000000];

    // input
    scanf("%d", &size);
    sizePlusOne = size + 1;

    for (i = 1; i < sizePlusOne; i++) {
        scanf("%d", &uno[i]);
    }

    for (i = 1; i < sizePlusOne; i++) {
        scanf("%d", &dos[i]);
    }

    // solucion
    swaps = 0;
    oldSwaps = 0;

    flag = 1;                                       // quiero entrar al menos una vez
    while (flag) {
        flag = 0;                                   // apago el flag...

        for (i = 1; i < sizePlusOne; i++) {
            dato = uno[i];

            if (i != dato) {             // si el dato encontrado no corresponde a la posicion...
                temp = uno[dato];
                uno[dato] = dato;        // ...lo mando a su posicion correcta
                uno[i] = temp;           // ...y traigo el dato que me interesa

                swaps++;
            }
        }

        flag = swaps - oldSwaps;                    // ...y lo vuelvo a encender si hice swaps
        oldSwaps = swaps;
    }

    flag = 1;
    while (flag) {
        flag = 0;

        for (i = 1; i < sizePlusOne; i++) {
            dato = dos[i];

            if (i != dato) {
                temp = dos[dato];
                dos[dato] = dato;
                dos[i] = temp;

                swaps++;
            }
        }

        flag = swaps - oldSwaps;
        oldSwaps = swaps;
    }

    printf("%d", swaps);
}