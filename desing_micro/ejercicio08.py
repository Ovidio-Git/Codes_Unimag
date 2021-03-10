

def run():

	with open('matriz.txt', 'w') as matrix:
		for i in range(1,11):
			matrix.write(f'{i}x1={i*1} {i}x2={i*2} {i}x3={i*3} {i}x4={i*4} {i}x5={i*5} {i}x6={i*6} {i}x7={i*7} {i}x8={i*8} {i}x9={i*9} {i}x10={i*10}\n')




if __name__ == '__main__':
	run() 
