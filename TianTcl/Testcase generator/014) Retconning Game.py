import random as rd
N, M, O, C = rd.randint(2, 10), rd.randint(2, 10), rd.randint(2, 10), rd.randint(2, 10)
directions, direction = "xyz", lambda options: ("+" if round(rd.random()) else "-") + rd.choice(options)
Y, F = direction(directions), direction(directions)
P, R = direction(directions.replace(Y[1], "")), direction(directions.replace(F[1], ""))
print(N, M, O, Y, P, F, R, C)
print(*[direction(directions) for _ in range(C)])
# data-matrix
axis = {"x": N, "y": M, "z": O}
observer = {
    "x": axis.get(directions.replace(F[1], "").replace(R[1], "")),
    "y": axis.get(R[1]),
    "z": axis.get(F[1])
}
for relY in range(observer.get("y")):
    print(*[rd.randint(0, pow(2, observer.get("z")) - 1) for _ in range(observer.get("x"))])