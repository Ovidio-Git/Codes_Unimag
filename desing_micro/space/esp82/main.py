import machine
import socket
import time


def millis():
    return round(time.time() * 1000)

def conversor(value):
	tiempo = millis()
	sumatoria = 0
	n = 0
	while millis()-tiempo<500: #Duración 0.5 segundos(Aprox. 30 ciclos de 60Hz)
		voltaje   = value  * (1.1 / 1023.0)#voltaje del sensor
		corriente = voltaje*30.0		  #corriente=VoltajeSensor*(30A/1V)
		sumatoria = sumatoria+(corriente*corriente)#Sumatoria de Cuadrados
		n = n+1
		time.sleep(0.1)
	sumatoria=sumatoria * 2	  # Para compensar los cuadrados de los semiciclos negativos.
	corriente=(sumatoria/n)**(1/2)# Ecuación del RMS
	irms=corriente; 	  		  # Corriente eficaz (A)
	potence=irms*110.0; 		  # P = I*V (Watts)
	return potence

def request(url, sensor):
	addr = socket.getaddrinfo(url, 80)[0][-1]
	s = socket.socket()
	s.connect(addr)
	s.send(bytes('POST /metrics/%s HTTP/1.1\r\nContent-Type: multipart/form-data; boundary=---011000010111000001101001\r\nHost: pinogano2.mooo.com\r\n\r\n'% (sensor), 'utf8'))
	data = s.recv(15)
	print(str(data, 'utf8'), end='')

def sleep_mode(reset_time):
	rtc = machine.RTC() # RTC (Real Time Clock)
	rtc.irq(trigger=rtc.ALARM0, wake=machine.DEEPSLEEP)
	# Set reset time -> reset_time
	rtc.alarm(rtc.ALARM0, reset_time)


def current():
	pin = machine.Pin(2, machine.Pin.OUT)
	pin.off()
	adc = machine.ADC(0)
	data = 0
	for _ in range(10):
		value = conversor(adc.read())
		if value > data:
			data = round(value, 2)
		print("potence : ",data,"W")
	request("pinogano2.mooo.com", str(data))
	print("\na mimir")
	machine.deepsleep()

def run():
	if machine.reset_cause() == machine.DEEPSLEEP_RESET:
		print('\n\rdespertando :c ...')
	else:
		print('\n\rme resetearon we T-T ')
	sleep_mode(120000)
	current()


if __name__ == '__main__':
	run()