import serial.tools.list_ports

plist = list(serial.tools.list_ports.comports())

if len(plist) <= 0:
    print("no serial port find")
else:
    plist_0 = list(plist[0])
    serialName = plist_0[0]
    serialFind = serial.Serial(serialName, 115200, timeout=60)
    print("can be used serial prot:", serialName)
