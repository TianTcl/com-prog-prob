import random as rd
W, C = rd.randint(1, 20), rd.randint(1, 20)
L = rd.randint(W, 20)
print(W, L, C)
dup_chk = list()
while len(dup_chk) < C:
	cmd = [round(rd.random()) for _ in range(L)]
	if cmd not in dup_chk:
		print(*cmd)
		dup_chk.append(cmd)