import random

from person import Person

# Display all the information
def displayInformation():
	print("Total population: %d" % Person.populationCount)
	print("Total susceptible: %d" % Person.susceptibleCount)
	print("Total immune: %d" % Person.immuneCount)
	print("Total infected: %d" % Person.infectedCount)
	print("Total dead: %d" % Person.deadCount)

# Determine gridsize
gridSize = 10

# Test variables
population = 20
susceptible = 10

# Create the grid
grid = [[0 for x in range(gridSize)] for x in range(gridSize)]

# Create variables to fill the grid properly
susceptibleCount = susceptible
populationCount = population

# Fill the grid with susceptibles people first
while(susceptibleCount > 0):
	i = random.randint(0,9)
	j = random.randint(0,9)
	if(grid[i][j] == 0):
		grid[i][j] = Person(0,1)
		susceptibleCount -= 1
		populationCount -= 1

# Fill the grid with the remaining people
while(populationCount > 0):
	i = random.randint(0,9)
	j = random.randint(0,9)
	if(grid[i][j] == 0):
		grid[i][j] = Person(1,0)
		populationCount -= 1

# Print the grid in a viewable manner
for row in range(0,len(grid)):
	for colm in range(0,len(grid[row])):
		if(grid[row][colm] != 0):
			print grid[row][colm].dead, ' ',
		else:
			print grid[row][colm], ' ',
	print('\n')
	
# Display the wanted information
displayInformation()