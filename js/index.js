"use strict";
const { hrtime } = require('process');



const MAX_ROLLS = 1_000_000;
function throwRandom(faces) {
	return Math.floor(Math.random()*faces);
}

const dice = [
    4, 6, 8, 10, 12, 20    
]

function roll() {
    let tries = 0; 
    for (let i = 0; i < dice.length; i++) {
        let found = false;
        while (!found) {
            tries++;
            const t = throwRandom(dice[i])
           if (t === dice[i] -1) {
            found = true;
            }  
        }
    }
    return tries;
}

function throwAll() {
    let min = Infinity;
    let max = 0;
    let avg = 0;
    let total = 0;    
    for (let i = 0; i < MAX_ROLLS; i++) {
        const tries = roll();
        if (tries < min) {
            min = tries;
        }
        if (tries > max) {
            max = tries;
        }
        total += tries;
        avg = total / i;
    }
    return {min, max, avg, total}
}


const start = hrtime.bigint()
console.log(throwAll());
const end = hrtime.bigint()
console.log(`Time: ${parseInt(end - start) / 1e6} ms`)
