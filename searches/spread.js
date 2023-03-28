//Spread Operator 

function sumOne(a,b){
    return a + b;
}

var myA = [5,4];//your value is coming as a bunch
//console.log(sumOne(5,4,1,2,3));what the function doesnt understands is ignored
console.log()
console.log("Answer using spread operator : " + sumOne(...myA));//spread operator -> takes a group and spreads it into multiple values



//REST operator 
//here ...args converts individual values into array
function sumTwo(a,b,...args){
    let sum = 0;
    let mul = a*b;

    for(const arg of args ){
        sum+=arg;
    }


    return [mul,sum];
}

console.log( sumTwo(1,2,3,4,5))
console.log("REST operator :  " + sumTwo(1,2,3,4,5))



