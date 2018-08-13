import serial
import time

direction=1
motSpeed=0

arduino=serial.Serial("/dev/ttyUSB1",9600,timeout=1)

def driveMotor(speed, drct):
    
    enA=int(speed)
    enB=int(speed)
    #determinamos la direccion
    if int(drct)==1:
        in1=1
        in2=0
        in3=1;
        in4=0
    elif int(drct)==-1:
        in1=0
        in2=1
        in3=0
        in4=1
    else:
        in1=0
        in2=0
        in3=0
        in4=0
    valList=[str(enA),str(in1),str(in2),str(in3),str(in4),str(enB)]
    serString=','.join(valList)
    
    arduino.write(serString.encode('utf-8'))
    #print(serString)
    time.sleep(0.1)

while True:
    motSpeed=0
    while motSpeed < 256:
        driveMotor(motSpeed,direction)
        motSpeed+=1
        
    while motSpeed >0:
        driveMotor(motSpeed,direction)
        motSpeed=motSpeed-1
    direction=-direction