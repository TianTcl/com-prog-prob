import random as rd
D, W, H = rd.randint(1, 62), rd.randint(1, 10), rd.randint(1, 10)
print(D, W, H)
stylus = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz!@#$%^&*()_+-=/[]\{\}<>?.,:;\"'\\`~"
ref_list, ref_avail = list(stylus[:62]), list()
for _ in range(D):
	ref_use = ref_list.pop(rd.randint(0, len(ref_list) - 1))
	ref_avail.append(ref_use)
	C, R = rd.randint(1, 15), rd.randint(1, 15)
	print(ref_use, C, R)
	for r in range(R): print("".join([rd.choice(stylus) for char in range(C)]))
for _ in range(H): print("".join([rd.choice(ref_avail) for ref in range(W)]))