# solve on 14, May 2017 at 2:10 am

import datetime

year = 1901
month = 1
day = 1
sundays = 0
while year < 2001:
	month = 1
	while month < 13:
		date = datetime.date(year, month, day)
		if date.weekday() == 6:
			sundays = sundays + 1
		month = month + 1
	year = year + 1

print(sundays)