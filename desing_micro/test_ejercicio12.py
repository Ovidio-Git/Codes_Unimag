




def run():
	#creating file 1 with numbers 0-100
	with open('data1.txt','w') as data1:
		for i in range(0,101):
			data1.write(f'{i} ')
	#creating file 2 with numbers 50-200
	with open('data2.txt','w') as data2:
		for i in range(50,201):
			data2.write(f'{i} ')


if __name__ == '__main__':
	run()
