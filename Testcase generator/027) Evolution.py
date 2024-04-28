import random as rd
N, D = rd.randint(1, 10), rd.randint(4, 1e2)
print(*[rd.randint(1, 1e4) for _ in range(D)])
dup_chk = list()
while len(dup_chk) < N:
	index = rd.randint(3, 3e2)
	if index not in dup_chk:
		print(index)
		dup_chk.append(index)