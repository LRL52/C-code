e = 55555
d = 976785643
p = 3390852167

def ksm(a, b):
	ret = 1
	while b:
		if b & 1: ret = ret * a % p
		a =  a * a % p
		b >>= 1
	return ret

print(ksm(123, e))