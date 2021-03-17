import numpy as np # funcion para implemetar el  logaritmo y el euler


def run():
	print('por favor ingrese 2 numeros (ingresar 0 no esta permitido)')
	a = int(input('numero a -> '))
	b = int(input('numero b -> '))
	if a != 0 and b != 0:
		print(f'1. La suma de {a} y {b} es {a+b}')
		print(f'2. La diferencia cuando {b} se resta de {a} es {b-a}')
		print(f'3. El producto entre {a} y {b} es {a*b}')
		print(f'4. El conciente cuando {a} es dividido por {b} es {a/b}')
		print(f'5. El resultado del logaritmo base 10 de {a} es {np.log10(a)} ')
		print(f'6. El resultado de elevar {a} a la {b} es {a**b}')
		print(f'7. El resultado de euler a la {a} es {np.exp(a)}')
		print(f'8. El resultado de la raiz {b} de {a} es {a**1/b} ')
	else:
		print('Error no esta permitido ingresar el 0')

if __name__ == '__main__':
	run()
