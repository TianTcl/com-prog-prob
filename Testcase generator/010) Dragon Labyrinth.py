import random as rd
M, D = rd.randint(4, 2e3), rd.randint(1, 1e3)
gen_coord = lambda deepest: [rd.randint(1, M), rd.randint(1, M), rd.randint(deepest, 100)]
K, S = rd.randint(0, M**2 - D - 1), gen_coord(0)
print(M, D, K, *S)
dup_chk = list((S))
while len(dup_chk) <= D:
	coord = gen_coord(0)
	if coord not in dup_chk:
		print(*coord)
		dup_chk.append(coord)
while len(dup_chk) - D <= K:
	coord = gen_coord(-1)
	if coord not in dup_chk:
		print(*coord)
		dup_chk.append(coord)