
def sum(a, b, c, d):
	print(f'({a}) + ({b}) + ({c}) + ({d}) = {a+b+c+d}')


def run():

	print('Por favor ingrese 4 numeros:')
	a = int(input('Numero 1 -> '))
	b = int(input('Numero 2 -> '))
	c = int(input('Numero 3 -> '))
	d = int(input('Numero 4 -> '))
	sum(a,b,c,d)


if __name__ == '__main__':
	run()
