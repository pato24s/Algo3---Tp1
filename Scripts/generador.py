import numpy as np
# import matplotlib.pyplot as plt
import random
def main():
    howMany = 0
    cantidadSalidas = 0


    howMany = int(input('How many numbers would you like to generate?: '))
    cantidadSalidas = 30
    for i in range(1,cantidadSalidas+1):
    	numbers = []
    	infile = open ('../Entradas/'+str(howMany)+'/inRandom'+str(howMany)+'_'+str(i)+'.txt', 'w')
    	infile.write(str(howMany) + '\n')
    	for n in range(1,howMany+1):
        	numbers.append(random.randint(1,115))
    	infile.write(' '.join(map(str, numbers)))
    	infile.close()
main()