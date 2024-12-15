import random as rd
groups, students = rd.randint(1, 1e3), lambda n: int(n * (n + 9) / 2)
print(students(groups))
for group in range(groups):
	print(*[rd.randint(1, 1e2) for _ in range(5 + group)])