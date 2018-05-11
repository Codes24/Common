import nmap
import sys
import os

nm = nmap.PortScanner()         # instantiate nmap.PortScanner object
nm.scan(hosts='192.168.56.20', arguments='-n -sS')

print(nm['192.168.56.20'])