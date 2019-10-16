diff = open("diff.txt", "r")

flag = ""
for l in diff:
    flag += l[-2]
print(flag)