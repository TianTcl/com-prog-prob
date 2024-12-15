import random as rd
teams = ("BLUE", "RED")
C = rd.randint(5, 5e3)
print(C)
team_best = dict()
for team in teams:
	level, best = list(), -1
	for person in range(C):
		best = rd.randint(best + 1, 7.5e5 - C + person + 1)
		level.append(best)
	print(*level)
	team_best[team] = level[-1]
for tie in range(5):
	for team in teams:
		team_best[team] = rd.randint(max(5e2, team_best.get(team)), 2e6)
	print(*team_best.values())