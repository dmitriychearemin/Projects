import math
import numpy as np
import matplotlib.pyplot as plt

F1 = 5000            #частота в герцах
F2 = 200000          #частота в герцах
T = 1/F2                 #период колебания
C = 576 * 10**-12       # емкость
R = 61.3                #сопротивление начальное
w1 = 2 *3.14 * F1       # период в радианах
w2 = 2 *3.14 * F2       # период в радианах
fi = -3.14/2              #
Um1 = 0.03             #красный график
Um2 = 2.25             #жёлтый график
L = 0.0011             #Генри индуктивность
B = R/(2 * L)          #декремент затухания
wzat2 = 1.256 * 10**6  #
# T = 2 *3.14 * sqrt LC


plt.rcParams.update({'font.size': 12})  # размер шрифта
plt.xlabel('t, us', fontsize=16)        #подписи осей и графика
plt.ylabel('U, V', fontsize=16)
plt.title('U(t)')

t = np.arange(0,140,0.1)  # для обоих графиков время в мкс
y1 = Um1 * np.sin((w1*t*10**-6) + fi)   # для красного графика
y2 = Um2 * np.power(2.7,-27864 * t*10**-6) * np.cos((wzat2*t*10**-6) + fi)   # для желтого графика

plt.plot(t,y1, color = 'red',   linewidth = 2)
plt.plot(t,y2, color=  'yellow',linewidth = 2)

plt.grid()
plt.show()

