l = "114 114 114 111 99 107 110 114 110 48 49 49 51 114"
l2 = l.split(" ")
for i in l2:
    print(i)
ans = ""
for i in l2:
    ans += chr(int(i))
print(ans)