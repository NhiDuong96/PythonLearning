# tuple
t = (1, 2, 3)
a = enumerate(t)
for i, v in enumerate(t):
    print(i, v)

for q, a in zip([1, 2, 3], [2, 3, 4]):
    print(q, a)
