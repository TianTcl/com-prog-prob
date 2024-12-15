import random as rd
U, R, S, D = rd.randint(1, 1e5), rd.randint(1, 1e3), rd.randint(1, 1e3), rd.randint(1, 1e4)
D = int(1e3)
print(U, R, S, D)
dup_chk = list()
while len(dup_chk) < D:
	info = [rd.randint(1, 1e3) for _ in range(2)]
	if info not in dup_chk:
		print(*info)
		dup_chk.append(info)