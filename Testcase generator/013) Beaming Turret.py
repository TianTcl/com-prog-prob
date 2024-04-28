import random as rd
N, M, O = rd.randint(1, 1e5), rd.randint(1, 1e5), rd.randint(1, 1e5)
T = rd.randint(1, min(1e3, N * M * O))
B = rd.randint(0, min(1e3, N * M * O) - T)
print(N, M, O, T, B)
dup_chk, gen_coord = list(), lambda: [rd.randint(1, N), rd.randint(1, M), rd.randint(1, O)]
while len(dup_chk) < T:
	coord = gen_coord()
	if coord not in dup_chk:
		print(*coord)
		dup_chk.append(coord)
while len(dup_chk) - T < B:
	coord = gen_coord()
	if coord not in dup_chk:
		print(*coord)
		dup_chk.append(coord)