import random as rd
P, B = rd.randint(1, 1e2), rd.randint(1, 1e2)
print(P, B)
dup_chk = list()
while len(dup_chk) < P:
	route, fartest = list(), 0
	for station in range(B):
		fartest = rd.randint(fartest + 1, 1e6 - B + station + 1)
		route.append(fartest)
	if route not in dup_chk:
		print(*route)
		dup_chk.append(route)