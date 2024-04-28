import random as rd
O = rd.randint(1, 1.5e5)
print(O)
dup_chk = list()
while len(dup_chk) < O:
	order = [rd.randint(1, 1e2), rd.randint(1, 1e8)]
	order.append(rd.randint(1, min(order[1], 2e3)))
	if order not in dup_chk:
		print(*order)
		dup_chk.append(order)