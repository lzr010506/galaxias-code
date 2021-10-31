from decimal import *

inf = 100
pi = Decimal(3.1415926535897932384626433832795028841971)

def cal(x):
	res = 0
	if x < inf:
		for i in range(1 , int(x + 1)):
			res += Decimal(i).ln()
	else:
		res = x * x.ln() - x + (Decimal(8) * x * x * x + Decimal(4) * x * x + x + Decimal(1) / Decimal(30)).ln() / Decimal(6) + pi.ln() / Decimal(2)

	return res


a , b = input().split()
a = Decimal(a)
b = Decimal(b)

mxx = 9 * Decimal(10).ln()
sum = (a + b) * Decimal(2).ln() + cal(a) + cal(b) - cal(a + b)

if sum > mxx:
	print("Extreme Wealth")
else:
	print(sum.exp())