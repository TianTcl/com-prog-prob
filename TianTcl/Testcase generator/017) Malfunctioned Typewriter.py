import random as rd
print("".join([rd.choice("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz") for _ in range(rd.randint(2, 1e4))]))