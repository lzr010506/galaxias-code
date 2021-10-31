def qpow(x):
	s = 1
	a = 10
	while x > 0:
		if (x & 1) == 1:
			s *= a
		x //= 2
		a *= a

	return s

x = 0
y = 0

def exgcd(a , b):
	global x
	global y

	if b == 0:
		x = 1
		y = 0

		return a
	else:
		r = exgcd(b , a % b)
		t = x
		x = y
		y = t - a // b * y

		return r

def check(a , b , d , inf):
	global x
	global y
	r = exgcd(a , b)

	if d % r != 0:
		return 0

	x *= (d // r)
	y *= (d // r)

	a //= r
	if y >= 0:
		rd = 1 + y // a
		y -= rd * a
	else:
		rd = (-y) // a
		y += rd * a

	return (-y) * b // 9 <= inf

b , d , a = map(int , input().split())

if d == 0:
	inf = a // b
	tw = 0
	fi = 0

	while b % 5 == 0:
		fi += 1
		b //= 5
	while b % 2 == 0:
		tw += 1
		b //= 2

	res = 0
	k = 1
	if tw >= fi:
		res = fi

		while tw > fi:
			k *= 5
			if k > inf:
				break

			fi += 1
			res += 1
	else:
		res = tw

		while fi > tw:
			k *= 2
			if k > inf:
				break

			tw += 1
			res += 1

	while k <= inf:
		k *= 10
		if k <= inf:
			res += 1

	print(res)

else:
	L = 0
	R = 10001

	while L + 1 < R:
		mid = (L + R) // 2
		if check(qpow(mid) , 9 * b , d , a) == 1:
			L = mid
		else:
			R = mid

	print(L)