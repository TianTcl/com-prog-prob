import random as rd
S, Q = rd.randint(1, 6), rd.randint(1, 1e4)
print(S, Q)
print(*[rd.randint(0, 9) for _ in range(S)])
dup_chk = list()
while len(dup_chk) < Q:
	ans = rd.randint(-1e5, 1e5)
	if ans not in dup_chk:
		print(ans)
		dup_chk.append(ans)