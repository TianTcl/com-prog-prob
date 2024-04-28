import random as rd
U, W = rd.randint(2, 1e2), rd.randint(1, 50)
print(U, W)
# chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
letter_freq = (
	("A", 8.167),
	("B", 1.492),
	("C", 2.782),
	("D", 4.253),
	("E", 12.702),
	("F", 2.228),
	("G", 2.015),
	("H", 6.094),
	("I", 6.966),
	("J", 0.153),
	("K", 0.772),
	("L", 4.025),
	("M", 2.406),
	("N", 6.749),
	("O", 7.507),
	("P", 1.929),
	("Q", 0.095),
	("R", 5.987),
	("S", 6.327),
	("T", 9.056),
	("U", 2.758),
	("V", 0.978),
	("W", 2.360),
	("X", 0.150),
	("Y", 1.974),
	("Z", 0.074),
)
chars = "".join([char[0]*round(char[1] * 10) for char in letter_freq])
print("".join([rd.choice(chars) for _ in range(U)]))
word_file = open("Testcase generator/_dict-1.txt", "r")
word_list = word_file.read().split("\n")[1:]
word_file.close()
for _ in range(W):
	word_use = rd.randint(0, len(word_list) - 1)
	print(word_list.pop(word_use).upper())