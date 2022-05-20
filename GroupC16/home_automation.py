import time
import RPi.GPIO as GPIO 

RUNNING = True

HIGH  = 1
LOW  = 0
PIRPin = 4
DOORpin = 21
LIGHT1pin = 23
LIGHT2pin = 24
LIGHT3pin = 25
FAN1pin	= 6
FAN2pin	= 16
FAN3pin	= 5
Mains1pin = 27
Mains2pin = 22

def InitSystem():
	GPIO.setmode(GPIO.BCM)
	GPIO.setup(PIRPin,GPIO.IN,pull_up_down=GPIO.PUD_UP)
	GPIO.setup(DOORpin,GPIO.OUT)
	GPIO.setup(LIGHT1pin,GPIO.OUT)
	GPIO.setup(LIGHT2pin,GPIO.OUT)
	GPIO.setup(LIGHT3pin,GPIO.OUT)
	GPIO.setup(FAN1pin,GPIO.OUT)
	GPIO.setup(FAN2pin,GPIO.OUT)
	GPIO.setup(FAN3pin,GPIO.OUT)
	GPIO.setup(Mains1pin,GPIO.OUT)
	GPIO.setup(Mains2pin,GPIO.OUT)
	return



def DetectPerson():
	#while True:
	input_state = GPIO.input(PIRPin)
	time.sleep(0.3)	
	if input_state == 0:
		return LOW
	else:
		return HIGH
			
	
			
			
try:
	print "\n\n         Home Automation Testing\n\n"
	print  "-----------------------------------------------\n" 	
	InitSystem()
	count =0;
	count_flag =0
	door_flag =0
	elapsed =0
	start = time.time()
	while RUNNING:
		state = DetectPerson()
		if state == HIGH:
			if count_flag == 1:
				count_flag =0 
				count+=1
				print "Person Detected\n"
		else:
			count_flag = 1
			#print "Waiting for Next Person. Time elapsed %d\n" %elapsed
			
		if count == 0:			
			GPIO.output(DOORpin,0)
			GPIO.output(LIGHT1pin,0)
			GPIO.output(LIGHT2pin,0)
			GPIO.output(LIGHT3pin,0)
			GPIO.output(FAN1pin,0)
			GPIO.output(FAN2pin,0)
			GPIO.output(FAN3pin,0)
			GPIO.output(Mains1pin,0)
			GPIO.output(Mains2pin,0)
			door_flag =1
			
		elif count ==1:	
			if door_flag == 1:
				door_flag =0
				GPIO.output(DOORpin,1)
				time.sleep(1)
				GPIO.output(DOORpin,0)
			
		elif count ==2:
			GPIO.output(LIGHT1pin,1)
			GPIO.output(FAN1pin,1)
		
		elif count ==3:
			GPIO.output(LIGHT2pin,1)
			GPIO.output(FAN2pin,1)
			
		elif count ==4:
			GPIO.output(LIGHT3pin,1)
			GPIO.output(FAN3pin,1)
			
		else:
			GPIO.output(Mains1pin,1)
			GPIO.output(Mains2pin,1)
			time.sleep(5)
			count =0
			
		elapsed = time.time() - start
		if elapsed > 120:		#2 min timeout
			print "\nTimeout Occured. Restart Program"
			break;
			
	
# If CTRL+C is pressed the main loop is broken
except KeyboardInterrupt:
    RUNNING = False
    print "\nStopping"
 
# Actions under 'finally' will always be called
finally:
    # Stop and finish cleanly so the pins
    # are available to be used again
    GPIO.cleanup()
