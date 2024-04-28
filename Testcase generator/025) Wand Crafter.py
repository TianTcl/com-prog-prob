import random as rd
usability = list(range(1, 101))
P, W, U = rd.randint(1, 100), rd.randint(1, 20), rd.choice(usability)
while not (W * U / 100).is_integer():
	usability.remove(U)
	U = rd.choice(usability)
perLog = int(W * U / 100)
maxLength = P * perLog
S = rd.randint(1, min(1000, maxLength))
print(P, W, U, S)
for std in range(S):
	length = rd.randint(1, min(20, maxLength - S + std + 1, perLog))
	print(length, end=" ")
	maxLength -= length
# ใช้ไม้เกิน เพราะเช็คจากความยาวรวม ไม่ใช่แยก แต่ถ้างั้นต้องเอาเฉลยใส่เลย