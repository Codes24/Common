import requests

r = requests.post('http://127.0.0.1/vHealth/save-data.php', data = {'username':'toan', 'data':'this is data'})

print(r.text)