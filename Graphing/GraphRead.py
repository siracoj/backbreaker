import sys, serial
import numpy as np
import math
from time import sleep
from collections import deque
import matplotlib as mpl
from matplotlib import pyplot as plt
 
# class that holds analog data for N samples

mpl.rcParams['toolbar'] = 'None'
x_range = np.arange(0,5000,50)
fig = plt.figure()

class AnalogData:
  # constr
  def __init__(self, maxLen):
    self.aw = deque([0.0]*maxLen)	
    self.ax = deque([0.0]*maxLen)
    self.ay = deque([0.0]*maxLen)
    self.az = deque([0.0]*maxLen)
    self.maxLen = maxLen
 
  # ring buffer
  def addToBuf(self, buf, val):
    if len(buf) < self.maxLen:
      buf.append(val)
    else:
      buf.pop()
      buf.appendleft(val)
 
  # add data
  def add(self, data):
    assert(len(data) == 4)
    self.addToBuf(self.ax, data[0])
    self.addToBuf(self.ay, data[1])
    self.addToBuf(self.az, data[2])
    self.addToBuf(self.aw, data[3])

# plot class
class AnalogPlot:
  # constr
  def __init__(self, analogData):
    # set plot to animated
    plt.ion() 
    self.awline, = plt.plot(x_range, analogData.aw)
    self.axline, = plt.plot(x_range, analogData.ax)
    self.ayline, = plt.plot(x_range, analogData.ay)
    self.azline, = plt.plot(x_range, analogData.az)

    plt.title("Force on the backpack straps")
    plt.ylabel("Pounds")
    plt.xlabel("milliseconds")
    plt.legend([self.axline, self.ayline, self.azline, self.awline], ["A2", "A3", "A4", "A5"])
    plt.ylim([0, 7])
 
  # update plot
  def update(self, analogData):
    self.axline.set_ydata(analogData.ax)
    self.ayline.set_ydata(analogData.ay)
    self.azline.set_ydata(analogData.az)
    self.awline.set_ydata(analogData.aw)
    plt.draw()
 
# main() function
def main():
 
  # plot parameters
  analogData = AnalogData(100)
  analogPlot = AnalogPlot(analogData)
 
 
  # open serial port
  ser = serial.Serial("COM4", 9600)
  while True:
    try:
      line = ser.readline()
      data = [(0.4279 * (math.exp(0.791 * float(val)))) for val in line.split()]

      #print data
      if(len(data) == 4):
        analogData.add(data)
        analogPlot.update(analogData)

	
    except (KeyboardInterrupt, SystemExit, NameError):
      print 'exiting'
      break
    except ValueError:
      print 'bad data'

  # close serial
  ser.flush()
  ser.close()
 
# call main
if __name__ == '__main__':
  main()
 
