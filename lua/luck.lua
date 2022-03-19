ATTEMPTS = 1000000
dice = {4, 6, 8, 10, 12, 20}

function throwRandom(faces)
    return math.random(1, faces)        
end 

function roll()
    tries = 0
    for i = 1, 6 do
        found = false
        while not found do
            tries = tries + 1
            if throwRandom(dice[i]) == dice[i] then
                found = true
            else
                i = 1
            end
        end
    end
    return tries
end

function run()
    min = 1000000
    max = 0
    avg = 0.0
    total = 0
    for i = 1, ATTEMPTS do
        rolls = roll()
        if rolls < min then
            min = rolls
        end
        if rolls > max then
            max = rolls
        end
        total = total + rolls
        avg = total / i
    end

    print("min: ", min , "max: ", max, "avg: ", avg, "total: ", total)
end

nClock = os.clock()
run()
print("Execution time: ", (os.clock() - nClock) * 1000)


    
