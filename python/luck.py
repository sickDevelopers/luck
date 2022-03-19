import random
import time

dice = [4, 6, 8, 10, 12, 20]
ATTEMPTS = 100

def throw_random(faces):
    l = int(faces * random.random()) + 1
    return l

def roll(): 
    tries = 0
    i = 0
    while i < len(dice):
        found = False
        while found == False :
            tries = tries + 1
            x = throw_random(dice[i])
            if x == dice[i]:
                found = True
                i = i + 1
            else:
                i = 0        
    return tries

def main():
    start_time = time.time()
    minimum = 10000000
    maximum = 0
    avg = 0
    total = 0
    for x in range(1, ATTEMPTS):
        t = roll()
        if t < minimum:
            minimum = t
        if t > maximum:
            maximum  = t
        total += t
        avg = total / x

    print('min: {0}, max: {1}, avg: {2}, total: {3}'.format(minimum, maximum, avg, total))
    print('Execution time: %ss' % ((time.time() - start_time) * 1000))
main()
