
# Escriba un programa que lea un número entero ingresado por el usuario.
# Y luego, muestre un mensaje que indique si el número entero es par o
# impar.

def num():
	number = int(input('Ingrese un numero: '))
	if (number%2 == 0):
		print('El numero es par')
	else:
		print('El numero es impar')


def run():
	num()	



if __name__ == '__main__':
	run()
