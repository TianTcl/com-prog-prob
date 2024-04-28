import random as rd
P = rd.randint(1, 1e3)
G = rd.randint(2 * P, 3e3)
print(P, G)
print(*sorted([rd.randint(1, 1e3) for _ in range(G)]))