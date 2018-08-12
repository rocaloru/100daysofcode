import serial

arduino=serial.Serial("/dev/ttyUSB0", 9600, timeout=1)


while 1:
    val= arduino.readline().decode('utf-8')
    #print(val)
    parsed=val.split(',')
    parsed=[x.rstrip() for x in parsed]
    if (len(parsed) > 2 ):
        #print(parsed)
        a=int(int(parsed[0]+'0')/10)
        b=int(int(parsed[1]+'0')/10)
        c=int(int(parsed[2]+'0')/10)
    print(a)
    print(b)
    print(c)
    print(a+b+c)
