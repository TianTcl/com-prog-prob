import random as rd
W, B = rd.randint(2, 1e2), rd.randint(2, 1e2)
print(W, B)
terrains, line, directions = "-x#*", lambda: "".join([rd.choice(terrains) for _ in range(W)]), (-1, 0, 1)
board = [line() for _ in range(B)]
def count(posX, posY, terrain):
	danger_zone = 0
	for dirX in directions:
		for dirY in directions:
			if dirX == dirY == 0: continue
			elif posX + dirX < 0 or posX + dirX >= W: continue
			elif posY + dirY < 0 or posY + dirY >= B: continue
			if board[posY + dirY][posX + dirX] == terrain: danger_zone += 1
	return danger_zone
for terrain in terrains[1:]:
	for row in range(B):
		for col in range(W):
			print(count(col, row, terrain), end="")
		print()
# print(*board, sep="\n")