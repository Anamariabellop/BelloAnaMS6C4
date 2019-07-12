import numpy as np
import matplotlib.pylab as plt


datos=np.loadtxt("inicial.txt")
datos2=np.loadtxt("futura.txt")
datos3=np.loadtxt("futura2.txt")
#print(np.shape(datos2))


a= np.where(datos==50)
b= np.where(datos==100)


plt.figure(figsize=(15,5))

plt.subplot(1,3,1)
plt.title("t= 0s")
plt.imshow(datos)
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
#plt.savefig("placainicial.png")

plt.subplot(1,3,2)
plt.title("t= 100s")
plt.imshow(datos2)
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
#plt.savefig("placat100.png")


plt.subplot(1,3,3)
plt.title("t= 2500s")
plt.imshow(datos3)
plt.xlabel("x")
plt.ylabel("y")
plt.colorbar()
plt.subplots_adjust(hspace=.7)
plt.savefig("caso1.png")