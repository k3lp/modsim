# Class for population
class Person:

	populationCount = 0
	susceptibleCount = 0
	immuneCount = 0
	infectedCount = 0
	deadCount = 0

	# Initialization for each person
	def __init__(self, immune, susceptible):
		self.immune = immune
		self.susceptible = susceptible
		self.infected = 0
		self.infectionTime = 0
		self.dead = 1
		
		if(immune != 0):
			Person.immuneCount += 1
		
		if(susceptible != 0):
			Person.susceptibleCount += 1
		
		Person.populationCount += 1
	
	# Someone is stung and infected
	def makeInfected(self):
		self.infected = 1
		Person.infectedCount += 1
	
	# Show if infected and if so add infectionTime (so check every itteration)
	def checkInfected(self):
		if(self.infected == 0):
			return self.infected
		
		if(self.infectionTime < 99):
			makeDead()
			
		self.infectionTime += 1
		return self.infectionTime