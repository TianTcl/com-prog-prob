import random as rd
S, E = rd.randint(3, 1e3), rd.randint(1, 5e4)
print(S, E)
dup_chk = list()
while len(dup_chk) < S:
	coord = [rd.randint(-1e3, 1e3) for _ in range(3)]
	if coord not in dup_chk:
		print(*coord)
		dup_chk.append(coord)