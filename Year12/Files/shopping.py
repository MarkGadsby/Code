GRAVITY_ON_EARTH = 9.81
GRAVITY_ON_MARS = 3.711

def calculateWeightOnMars (weightOnEarth):
    weightOnMars = weightOnEarth / GRAVITY_ON_EARTH * GRAVITY_ON_MARS
    print (weightOnMars)
    return weightOnMars

calculateWeightOnMars(78)