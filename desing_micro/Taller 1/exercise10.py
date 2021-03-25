import numpy as np 

#:::::::::::::::::::::::::::::::::::    1 - 2    :::::::::::::::::::::::::::::::::::::::
def funtion_g(x0):          # se implemeta una funcion para poder calcular el valor de g
    return np.array([2*x0[0], 50*x0[1]]) # se implementa el gradiente de la funcion


def funtion_x(x, alpha, g): # se implemeta una funcion para poder calcular el valor de x
    return x - alpha * g  


def printf(vector):         # se hace una funcion para poder mostrar de mejor forma los resultados obtenidos
    for i in range (len(vector)//2):
        if i % 2 != 0: continue
        print(f'='*40)
        print(f'valor de g = {vector[i]}')
        print(f'valor de x = {vector[i+1]}')

def steepest_descent():     # se implementa el algoritmo de la steepest descent
    memory = []             # se crea una lista vacia para almacenar todos los resultados
    x0 = np.array([0.5, 0.5])
    alpha = 0.035
    k=funtion_g(x0)
    memory.append(k)
    for i in range(3):
        k=funtion_x(x0, alpha, k)
        memory.append(k)
        x0 = k
        k=funtion_g(k)
        memory.append(k)        
    printf(memory)          # se imprimen los resultados

#::::::::::::::::::::::::::::::::::::::    3     :::::::::::::::::::::::::::::::::::::::::::::::
def enterprise_g(x):
    return -3*x**2 + 500*x + 52500

def enterprise_x(x, alpha, g):
    return x + alpha * g


def steepest_enterprise():
    memory = []
    x0 =10
    alpha = 0.001
    k=enterprise_g(x0)
    memory.append(k)
    for i in range(16):
        k=enterprise_x(x0, alpha, k)
        memory.append(k)
        x0 = k
        k=enterprise_g(k)
        memory.append(k)        
    printf(memory)
     

def run():
    print('           Incisos 1 y 2')
    steepest_descent()
    print('\n\n            Inciso 3')
    steepest_enterprise()

if __name__ == '__main__':
    run()



#                                 OUTPUT DEL ALGORITMO


# Para el punto 1 con un alpha igual a 0.01
# ========================================
# valor de g = [ 1. 25.]
# valor de x = [0.49 0.25]
# ========================================
# valor de g = [ 0.98 12.5 ]
# valor de x = [0.4802 0.125 ]

# Para el punto 2 con un alpha igual a 0.035
# ========================================
# valor de g = [ 1. 25.]
# valor de x = [ 0.465 -0.375]
# ========================================
# valor de g = [  0.93 -18.75]
# valor de x = [0.43245 0.28125]

# podemos ver que alfa es un valor que nos dicen que tan grande seran los pasos
# como un "ratio de aprendizaje" y a editarlo a un mas grande
# vemos que los cambios son mas abruptos que los que se optenian con el apha anterior eque 
# era mucho menor 


#                                   3 3 3 3 3 3 3 3 3 3 3 3
#
# salida al ejecutar la condicion 3
# ========================================
# valor de g = 52997
# valor de x = 53.997
# ========================================
# valor de g = 70751.471973
# valor de x = 124.74847197300001
# ========================================
# valor de g = 68187.6922077049
# valor de x = 192.9361641807049
# ========================================
# valor de g = 37294.991744060695
# valor de x = 230.2311559247656
# ========================================
# valor de g = 8596.422487021584
# valor de x = 238.8275784117872
# ========================================
# valor de g = 797.9525757785159
# valor de x = 239.6255309875657
# ========================================
# valor de g = 51.580190564418444
# valor de x = 239.6771111781301
# ========================================
# valor de g = 3.202720983841573
# valor de x = 239.68031389911394

# como podemos ver en los resultados la cantidad de productos que dara el maximo 
# ingreso es de 239.6
# se uso una x0 inicial igual a 1 fue el resultado de un algoritmo que regresa un numero aleatorio
# que implemente. 
# en 16 interaciones se confirma el resultado pero este se optiene a las 9 interaciones