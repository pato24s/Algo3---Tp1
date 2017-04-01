import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import random
import numpy as np

ns = [10,11,12,13,14,15]
br = [0.1756643,0.5481998333,1.7423426667,5.8852243333,15.7573,48.8966]
bt = [0.0641526567,0.1976728,0.5820608,1.7932903333,5.66075,17.2039]
bc = [0.0001175801,0.0002024571,0.0003961959,0.000734063,0.00107193,0.0015417975]

plt.clf()
df = pd.DataFrame({'Backtracking Recursivo': br, 'Backtracking Iterativo': bt,  'Backtracking c/Poda':bc,'Longitud entrada':ns})
df.plot(x='Longitud entrada')
plt.title('Tiempo en funcion de la entrada')
plt.ylabel('Tiempo (s)')
plt.show()