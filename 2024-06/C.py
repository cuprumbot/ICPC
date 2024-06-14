'''
  Tiempo para resolver (ya sabiendo que era el segundo más fácil)
  62 minutos

  Dificultades encontradas y proceso de solución
  - Primer intento, fuerza bruta -> tiempo límite excedido
      Para cada reloj se aplicaba un módulo para saber si sonaría en el momento
      indicado

  - Segundo intento, factores en pareja -> respuestas incorrectas en algunos casos
      El problema se puede convertir en una factorización

      IDEA CLAVE: Para hallar los factores de N basta con llegar hasta sqrt(N)
      Por ejemplo, calcular factores de 36:
        36 / 2 -> encuentro como factores a 2 y 18
        36 / 3 -> encuentro como factores a 3 y 12
        36 / 4 -> encuentro como factores a 4 y 9
      Ya que 36 es un cuadrado perfecto, caso especial:
        36 / 6 -> solo me aporta el factor 36

      Si el tiempo es mayor a la cantidad de relojes, esta idea puede falla

  - Tercer intento, factores sueltos -> listo!
      Por ejemplo, tengo 36 minutos pero solo 10 relojes:
      36 / 2 -> el factor 2 me sirve, el factor 18 no
      36 / 3 -> el factor 3 me sirve, el factor 12 no
      36 / 4 -> los factores 4 y 9 ambos me sirven     
'''


from math import sqrt
from math import ceil

testcases = int( input() )

for _ in range(testcases):
  line = input().split()
  clocks = int(line[0])
  retTime = int(line[1]) - 1            # -1 porque en ese minuto todos suenan


  if (retTime == 0):                    # en este momento todos suenan
      print(clocks)
      continue


  if (retTime <= clocks):               # tengo 'suficientes' relojes...
    factors = 2
    limit = ceil( sqrt(retTime) )

    for div in range(2, limit):
      if (retTime % div == 0):
        factors = factors + 2           # ...entonces puedo agregar mis factores de 2 en 2

    if (limit * limit == retTime):      # en caso sea cuadrado perfecto
      factors = factors + 1
    
    print(factors)
  
  else:                                 # tengo menos relojes que minutos
    factors = 1
    limit = ceil( sqrt(retTime) )

    for div in range(2, limit):
      if (retTime % div == 0):
        factors = factors + 1           # puedo agregar un factor...

        if (retTime / div <= clocks):   # ...pero debo comprobar antes de agregar el otro
          factors = factors + 1
      
      if (limit * limit == retTime):    # en caso sea cuadrado perfecto
          factors = factors + 1
      
    print(factors)