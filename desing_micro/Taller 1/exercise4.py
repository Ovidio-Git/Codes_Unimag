import numpy as np


def verification(f1, f2, c1, c2):
	if f1 != f2 and c1 != c2:
		print('\n!ERROR las matrices NO tiene las mismas dimensiones!')
		quit()


def matriz(fila, colum, num):
	matrix = []
	for i in range(fila):
		matrix.append([])
		for j in range(colum):
			aux = int(input(f'ingrese dato el dato ([{i+1}],[{j+1}]) de la matriz {num} : '))
			matrix[i].append(aux)
	return  np.array(matrix)


def operations(m1, m2,c):
	print(f'La suma de las dos matrices es:\n {m1+m2}')
	print(f'El producto de las dos matrices es:\n {m1*m2}')
	if c:
		print(f'La matriz inversa de la matriz 1 es:\n {np.linalg.inv(m1)}')
		print(f'La matriz inversa de la matriz 2 es:\n {np.linalg.inv(m2)}')
		print(f'El determinante de la matriz 1 es:\n {np.linalg.det(m1)}')
		print(f'El determinante de la matriz 2 es:\n {np.linalg.det(m2)}')
	else:
		print('Sus matrices no son cuadradas por eso no se calculo el determinante ni la matriz inversa de estas')


def run():
	print('Ingrese las dimensiones de la matrices (recuerde deben tener las mismas dimensiones)')
	f1 = int(input('Ingrese el numero de filas de la primera matriz -> '))
	c1 = int(input('Ingrese el numero de columnas de la primera matriz -> '))
	f2 = int(input('Ingrese el numero de filas de la segunda matriz -> '))
	c2 = int(input('Ingrese el numero de columnas de la segunda matriz -> '))
	verification(f1,f2,c1,c2)
	matriz1 = matriz(f1, c1, 1)
	matriz2 = matriz(f2, c2, 2)
	print(f'Matriz 1:\n {matriz1}')
	print(f'Matriz 2:\n {matriz2}')
	operations(matriz1, matriz2,f1==c1)


if __name__ == '__main__':
	run()


