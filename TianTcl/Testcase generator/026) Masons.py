import random as rd
S = rd.randint(3, 20)
I = rd.randint(1, min(100, S * (S - 1) / 2))
dup_chk = list()
while len(dup_chk) < I:
	size = [rd.randint(1, S), rd.randint(1, S)]
	if sorted(size) not in dup_chk:
		print(rd.randint(1, 100), end=" ")
		print(*size)
		dup_chk.append(sorted(size))