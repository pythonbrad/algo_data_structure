a = input("Enter a: ")
b = input("Enter b: ")

def distance(a, b):
	delete = 0
	add = 0
	sub = 0
	occ = 0
	# We count the number of delete and add
	# to have same occurence of character in a in b
	for i in a:
		occ = a.count(i) - b.count(i)
		if occ < 0:
			delete += 1
			b = b.replace(i, '', 1)
		elif occ > 0:
			add += 1
			b += i
		else:
			pass
	# We count the number of delete to do to have same character in a in b
	for i in b:
		if not i in a:
			delete += 1
			b = b.replace(i, '', 1)
		else:
			pass
	# The distance is the subtitution + number of add or delete
	# But a subtitution is a add and delete
	# Then the distance is the subtitution + the excess (add or delete)
	# Hence distance is min(add, delete) + (max(add, delete) - min(add, delete))
	return max(add, delete)
			
print "The distance between a and b is:", distance(a, b)
	

