import serial
import time

arduino=serial.Serial("/dev/ttyUSB0",9600, timeout=1)

a=1
b=2
c=3

while True:
    valList=[str(a),str(b),str(c)]
    sendStr=','.join(valList)
    #print(sendStr)
    arduino.write(sendStr.encode('utf-8'))
    time.sleep(0.1)
    recStr=arduino.readline().decode('utf-8')
    print(recStr)
    a+=1
    b+=1
    c+=1