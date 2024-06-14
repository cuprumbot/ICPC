/*
 * Tiempo para resolver (ya sabiendo que era el más fácil)
 * 5 minutos
 * 
 * Dificultades encontradas
 * Los ejemplos no mostraban un premio que fuera más caro que el puntaje
 * obtenido, no tuve esto en cuenta en la primera entrega
 */

import java.util.Scanner;

public class F {

  public static void main(String[] args) {
    // teclado y strings
    Scanner kb, str;

    kb = new Scanner(System.in);
    String first = kb.nextLine();
    
    str = new Scanner(first);
    int prizes = str.nextInt();
    int score = str.nextInt();

    String second = kb.nextLine();
    str = new Scanner(second);

    int biggest = -1;
    while(str.hasNext()) {
      int curr = str.nextInt();

      // si es tan caro como nuestro puntaje, es lo más caro que podemos
      // canjear -> podemos finalizar el ciclo
      if (curr == score) {
        biggest = score;
        break;
      // es más caro que los que ya habíamos visto? nos alcanza para canjear
      // el premio? -> anotarlo como el más caro hasta el momento
      } else if (curr > biggest && curr <= score) {
        biggest = curr;
      }
    }
    System.out.println(biggest);
  }
}