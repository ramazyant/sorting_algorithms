import pandas
import matplotlib.pyplot as plt

data = pandas.read_csv("out.csv")

plt.ylabel("running time")
plt.xlabel("N")

# 10 - step in the cpp code, done just for being precise
# in the labeling of axes
# see row 46 in main.cpp

i = 0
for experiment in data["INSERTION"]:
    plt.plot(i * 10, experiment, 'ro')
    i += 1

i = 0
for experiment in data["MERGE"]:
    plt.plot(i * 10, experiment, 'yo')
    i += 1

i = 0
for experiment in data["QUICK"]:
    plt.plot(i * 10, experiment, 'bo')
    i += 1

i = 0
for experiment in data["COUNTING"]:
    plt.plot(i * 10, experiment, 'go')
    i += 1

i = 0
for experiment in data["RADIX"]:
    plt.plot(i * 10, experiment, 'rd')
    i += 1


plt.show()

#plt.savefig()