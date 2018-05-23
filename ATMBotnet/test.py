import requests

r = requests.get("http://192.168.56.60")

print(r.text)