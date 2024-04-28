import random as rd
max_slot = 16
S = rd.randint(2, max_slot)
R = rd.randint(1, S)
print(S, R)
for slot in range(S - 1):
	print(rd.randint(1, max_slot - 1) * (1 if round(rd.random()) else -1))