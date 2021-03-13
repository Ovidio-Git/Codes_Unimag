from ejercicio13 import Astronaut

def action(resul):
	spacetravel = Astronaut(launching='m')
	if resul == 'l': 
		spacetravel.Launching_on()
		return 1
	elif resul == 'a':
		spacetravel.Launching_off()
		return 1
	elif resul == 'f':
		spacetravel.Flag()
		return 1
	elif resul == 'd':
		spacetravel.Alien_die()
		return 1
	elif resul == 'p':
		spacetravel.Die_not_die()
		return 1
	else:
		return 0



def menu(sms):
	ctrl = 0
	while ctrl == 0:
		menu =  str(input(sms))
		ctrl = action(menu)
		if menu == 'e':
			print("\nThanks you and good morning!")
			quit()



def run ():


	sms='''
Welcome a this travel!

press  [l] for start launching
press  [e] for finish program\n\n\r---> '''
	menu(sms)
	sms= '''
press  [a] for landing
press  [e] for finish program\n\n\r---> '''
	menu(sms)
	sms='''
press  [f] for use the flag
press  [e] for finish program\n\n\r---> '''
	menu(sms)
	sms='''
press  [d] for alien Kill
press  [p] for peace with aliens
press  [e] for finish program\n\n\r---> '''
	menu(sms)



if __name__ == '__main__':
	run()
