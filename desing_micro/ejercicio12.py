
# Escriba un programa que cree dos archivos en formato txt: el primero
# debe imprimir los números enteros desde 0 hasta 100, el segundo debe
# imprimir los números enteros desde 50 hasta 200. Luego escriba otro
# programa que lea ambos archivos y genere un archivo nuevo que
# contenga sólo números pares organizados de mayor a menor, estos
# números no deben estar repetidos



def run():

	with open('data1.txt', 'r') as d:
		set1 = d.read()
		
	with open('data2.txt', 'r') as d1:
		set2 = d1.read()


	print(set1[0])
	print(set2[2])
#	with open ( 'output.txt','r' ) as out:
#		for i in range (0,200):
#			if (set1[i]%2==0):
#				out.write(f'{set[i]}')

if __name__ == '__main__':
	run()
