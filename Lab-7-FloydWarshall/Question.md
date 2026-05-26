You are managing a network of cities connected by one-way roads. Each road between two cities has a certain travel time. Some pairs of cities are not directly connected, and it may be necessary to travel through other cities to get from one city to another. You want to determine the shortest possible travel time between every pair of cities, even if it requires passing through multiple other cities.

## Given:
A list of N cities, numbered from 1 to N.  
A list of M one-way roads, where each road is represented as a triplet (u,v,w);

u: the starting city  
v: the destination city  
w: the travel time between city u and city v  

## Output:
A matrix where each entry [i][j] represents the shortest travel time from city i to city j.

If there is no path from city i to city j, the value should be infinity.
