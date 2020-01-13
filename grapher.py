import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

f = open("values.txt", "r")

contents = f.read().split()

x_s = [] 
y_s = [] 
z_s = []
i = 0
for c in contents:
    if c == "done":
        print("next")
        i += 1
        continue
    if i == 0:
        x_s.append(int(c))
    elif i == 1:
        y_s.append(int(c))
    else:
        z_s.append(int(c))

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.scatter(x_s, y_s, z_s, c='r', marker='o')
#ax.scatter([1,2,3], [1,2,3], [1,2,3], c='r', marker='o')

ax.set_xlabel("Cost")
ax.set_ylabel("Goal")
ax.set_zlabel("Init wallet")
plt.show()
