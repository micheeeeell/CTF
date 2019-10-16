import sys
# print(sys.getrecursionlimit())
sys.setrecursionlimit(10000)
# print(sys.getrecursionlimit())
def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        # print(g,y,x)
        return (g, x - (b // a) * y, y)

def xgcd(a, b):
    x0, y0, x1, y1 = 1, 0, 0, 1
    while b != 0:
        # print(a,b)
        q, a, b = a // b, b, a % b
        x0, x1 = x1, x0 - q * x1
        y0, y1 = y1, y0 - q * y1
    return a, x0, y0


def modinv(a, m):
    g, x, y = xgcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m

if __name__ == "__main__":
    for i in range(13):
        i += 1
        print(modinv(i,13))