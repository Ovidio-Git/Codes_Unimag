import machine
import socket
from time import sleep


def request(url, sensor):
	addr = socket.getaddrinfo(url, 80)[0][-1]
	s = socket.socket()
	s.connect(addr)
	s.send(bytes('POST /metrics/%s HTTP/1.1\r\nContent-Type: multipart/form-data; boundary=---011000010111000001101001\r\nHost: pinogano2.mooo.com\r\n\r\n'% (sensor), 'utf8'))
	while True:
		data = s.recv(100)
		if data:
			print(str(data, 'utf8'), end='')
		else:
			break
	s.close()

# POST /metrics/12 HTTP/1.1
# Content-Type: multipart/form-data; boundary=---011000010111000001101001
# Host: pinogano2.mooo.com

def sleep_mode(reset_time):
	rtc = machine.RTC() # RTC (Real Time Clock)
	rtc.irq(trigger=rtc.ALARM0, wake=machine.DEEPSLEEP)
	# Set reset time -> reset_time
	rtc.alarm(rtc.ALARM0, reset_time)


def current():
	pin = machine.Pin(2, machine.Pin.OUT)
	pin.off()
	adc = machine.ADC(0)
	for _ in range(3):
		print(adc.read())
		sleep(0.25)
		if (adc.read() > 1020):
			break
	#machine.deepsleep()


def run():
	if machine.reset_cause() == machine.DEEPSLEEP_RESET:
		print('\n\rdespertando... uwu')
	else:
		print('\n\rme resetearon we :3')
	#sleep_mode(5000)
	current()
	request("pinogano2.mooo.com", 33)



if __name__ == '__main__':
	run()
