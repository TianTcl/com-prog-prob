import random as rd
W, O, C = rd.randint(2, 1e3), "ASC" if round(rd.random()) else "DESC", [rd.randint(-5, 15) for _ in range(26)]
W = int(1e3)-89
print(W, O)
print(*C)
word_file = open("Testcase generator/_dict-1.txt", "r")
word_list = word_file.read().split("\n")[1:]
word_file.close()
for _ in range(W):
	word_use = rd.randint(1, len(word_list) - 1)
	print(word_list.pop(word_use))