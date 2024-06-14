/*
    Tiempo para traducir desde Python
    5 minutos

    Time limit exceeded on test 27
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

  int i, j, swaps, temp, datoUno, datoDos;
  int size;
  int iPlusOne, sizeMinusOne;
  int uno[1000000];
  int dos[1000000];

  scanf("%d", &size);
  sizeMinusOne = size - 1;

  for (i = 0; i < size; i++) {
    scanf("%d", &uno[i]);
  }

  for (i = 0; i < size; i++) {
    scanf("%d", &dos[i]);
  }

  swaps = 0;

  for (i = 0, iPlusOne = 1; i < sizeMinusOne; i++, iPlusOne++) {
    datoUno = uno[i];

    if (datoUno == iPlusOne) {
        continue;
    }

    for (j = iPlusOne; j < size; j++) {
        datoDos = uno[j];

        if (datoDos == iPlusOne) {
            uno[i] = datoDos;
            uno[j] = datoUno;
            swaps++;
            break;
        }
    }
  }

  for (i = 0, iPlusOne = 1; i < sizeMinusOne; i++, iPlusOne++) {
    datoUno = dos[i];

    if (datoUno == iPlusOne) {
        continue;
    }

    for (j = iPlusOne; j < size; j++) {
        datoDos = dos[j];

        if (datoDos == iPlusOne) {
            dos[i] = datoDos;
            dos[j] = datoUno;
            swaps++;
            break;
        }
    }
  }

  printf("%d", swaps);
}