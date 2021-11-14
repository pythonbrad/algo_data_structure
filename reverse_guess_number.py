import random
import math

# The biggest range that contains the number to guess
universe_str = '[0, 1024**1024]'
universe = eval(universe_str)

# The number to guess
number_to_guess = random.randint(*universe)

# The smallest range that contains the number to guest
subuniverse = universe
# The number guess
guess_number = None

# The number of tentative
tentative = 0

print('Guessing in %s' % universe_str)

# We try to reduce the universe as possible
while 1:

	# We propose the middle each time (the middle is 50% nearest of the number to guess)
	# Explanation: In the range [0, 100], 50 is nearest of all numbers
	guess_number = (subuniverse[0] + subuniverse[1]) // 2

	# We verify the proposition
	if guess_number > number_to_guess:
		# The guess number is a maximum
		subuniverse[1] = guess_number
	elif guess_number < number_to_guess:
		# The guess number is a minimum
		subuniverse[0] = guess_number
	else:
		# The guess number is the number to guest
		break

	tentative += 1

print("Found in %d tentative:" % tentative)