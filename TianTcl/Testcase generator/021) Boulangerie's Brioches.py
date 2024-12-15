import random as rd
T, F = rd.randint(2, 20), rd.randint(2, 100)
print(T, F)
print("\n".join([str(rd.randint(10, 1e5)) for _ in range(F)]))