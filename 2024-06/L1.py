'''
  Tiempo para resolver (ya sabiendo que era el tercero más fácil)
  11 minutos

  Time limit exceeded on on test 24
'''

leng = int(input())
uno = input().split()
dos = input().split()

uno = [int(u) for u in uno]
dos = [int(d) for d in dos]

swaps = 0

for i in range(leng-1):
  val = uno[i]

  if (val == i+1):
    continue
  else:
    for j in range(i+1, leng):
      comp = uno[j]

      if (comp == i+1):
        uno[i], uno[j] = uno[j], uno[i]
        swaps = swaps + 1
        break

for i in range(leng-1):
  val = dos[i]

  if (val == i+1):
    continue
  else:
    for j in range(i+1, leng):
      comp = dos[j]

      if (comp == i+1):
        dos[i], dos[j] = dos[j], dos[i]
        swaps = swaps + 1
        break

print(swaps)