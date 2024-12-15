import random as rd
height = rd.randint(1, 3e2)
F = rd.randint(1, height)
C = 2 * height * F - F ** 2
R = rd.randint(1, 2 * (height - F) + 1)
print(F, C, R)