
# d2d3d4=406 is divisible by 2		(1)
# d3d4d5=063 is divisible by 3		(2)
# d4d5d6=635 is divisible by 5		(3)
# d5d6d7=357 is divisible by 7		(4)
# d6d7d8=572 is divisible by 11		(5)
# d7d8d9=728 is divisible by 13		(6)
# d8d9d10=289 is divisible by 17	(7)

#	1.	Since (3), d6 must be 0 or 5
#	2.	Since (5), if d6 is 0, d7d8 is digits which gives in set {22, 33, ..., 99}, 
#		and those are not pandigital numbers, therefore d6 must be 5
#	3.  Because (5) and d6 is 5, therefore d6d7d8 must be digits
#		which gives in set {506, 517, 528, 539, 561, 572, 583, 594}
#	4.	Therefore d6d7d8d9 is digits which gives in set {5286, 5390, 5728, 5832}
#	5.	And d6d7d8d9d10 is digits which gives in set {52867, 53901, 57289}
#	6.	Since (4), d5d6d7d8d9 is digits which gives in set {95286, 35728}
#	7.	Because (1), d4 must be even, our set is {0952867, 4952867, 0357289, 4357289, 6357289}
#	8.	Because (2), d3 + d4 + d5 must be divisiable by 3, our set must be {30952867, 60357289, 06357289}
#	9. 	Because pandigital numbaes, d1d2 must be 14 or 41
#	10.	Finally, combine {14, 41} with {30952867, 60357289, 06357289}, we have six number
#		1430952867, 1460357289, 1406357289, 4130952867, 4160357289, 4106357289	

print(1430952867 + 1460357289 + 1406357289 + 4130952867 + 4160357289 + 4106357289)